#include "monty.h"
/**
 * run - Executes the opcode
 * @line_content: Line content
 * @stk_tete: Pointer to the head of the stack
 * @useless_ctr: Line counter
 * @monty_file: Pointer to Monty file
 * Return: No return
 */
int run(char *line_content, stack_t **stk_tete,
		unsigned int useless_ctr, FILE *monty_file)
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
