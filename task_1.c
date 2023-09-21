#include "monty.h"
/**
 * print_top - Prints the top element of the stack
 * @stack_head: Pointer to the head of the stack
 * @line_number: Line number
 * Return: No return
 */
void print_top(stack_t **stack_head, unsigned int line_number)
{
	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(monty_bus.monty_file);
		free(monty_bus.line_content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack_head)->n);
}
