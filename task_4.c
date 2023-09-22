#include "monty.h"
/**
 * f_add_objects - Adds the top two elements of the stack
 * @stk_tete: Pointer to the head of the stack
 * @useless_ctr: Line number
 * Return: No return
 */
void f_add_objects(stack_t **stk_tete, unsigned int useless_ctr)
{
	stack_t *temp;
	int len = 0, aux;

	temp = *stk_tete;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", useless_ctr);
		fclose(monty_bus.monty_file);
		free(monty_bus.line_content);
		free_stack(*stk_tete);
		exit(EXIT_FAILURE);
	}
	temp = *stk_tete;
	aux = temp->n + temp->next->n;
	temp->next->n = aux;
	*stk_tete = temp->next;
	free(temp);
}
/**
 * run - Executes the opcode
 * @line_content: Line content
 * @stk_tete: Pointer to the head of the stack
 * @useless_ctr: Line counter
 * @monty_file: Pointer to Monty file
 * Return: No return
 */
int run(char *line_content, stack_t **stk_tete, unsigned int useless_ctr, FILE *monty_file)
{
	instruction_t opst[] = {
		{"push", go_stack}, {"pall", back_stack}, {"pint", back_top},
		{"pop", rm_stack},
		{"swap", swap_objects},
		{"add", f_add_objects},
		{"nop", f_nothing},
		{NULL, NULL}
	};

	unsigned int i = 0;
	char *op;

	op = strtok(line_content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	monty_bus.arg_value = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stk_tete, useless_ctr);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", useless_ctr, op);
		fclose(monty_file);
		free(line_content);
		free_stack(*stk_tete);
		exit(EXIT_FAILURE);
	}
	return (1);
}
