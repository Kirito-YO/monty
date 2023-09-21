#include "monty.h"
/**
 * back_stack - Prints the elements of the stack
 * @stk_tete: Pointer to the head of the stack
 * @useless_ctr: Unused counter
 * Return: No return value
 */
void back_stack(stack_t **stk_tete, unsigned int useless_ctr)
{
	stack_t *current;

	(void)useless_ctr;

	current = *stk_tete;
	if (current == NULL)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * go_stack - Adds a node to the stack
 * @stk_tete: Pointer to the head of the stack
 * @line_number: Line number
 * Return: No return
 */
void go_stack(stack_t **stk_tete, unsigned int line_number)
{
	int value, index = 0, flag = 0;

	if (monty_bus.arg_value)
	{
		if (monty_bus.arg_value[0] == '-')
			index++;
		for (; monty_bus.arg_value[index] != '\0'; index++)
		{
			if (monty_bus.arg_value[index] > 57 || monty_bus.arg_value[index] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(monty_bus.monty_file);
			free(monty_bus.line_content);
			free_stack(*stk_tete);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(monty_bus.monty_file);
		free(monty_bus.line_content);
		free_stack(*stk_tete);
		exit(EXIT_FAILURE);
	}
	value = atoi(monty_bus.arg_value);
	if (monty_bus.stack_mode == 0)
		add_node_to_stack(stk_tete, value);
	else
		add_node_to_queue(stk_tete, value);
}

/**
 * free_stack - Frees a doubly linked list
 * @stk_tete: Head of the stack
 */
void free_stack(stack_t *stk_tete)
{
	stack_t *aux;

	aux = stk_tete;
	while (stk_tete)
	{
		aux = stk_tete->next;
		free(stk_tete);
		stk_tete = aux;
	}
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
		{"go_stack", go_stack}, {"back_stack", back_stack}, {"back_top", back_top},
		{"rm_stack", rm_stack},
		{"swap_objects", swap_objects},
		{"f_add_objects", f_add_objects},
		{"f_nothing", f_nothing},
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
