#include "monty.h"
/**
 * back_top - Prints the top element of the stack
 * @stk_tete: Pointer to the head of the stack
 * @line_number: Line number
 * Return: No return
 */
void back_top(stack_t **stk_tete, unsigned int line_number)
{
	if (*stk_tete == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(monty_bus.monty_file);
		free(monty_bus.line_content);
		free_stack(*stk_tete);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stk_tete)->n);
}
