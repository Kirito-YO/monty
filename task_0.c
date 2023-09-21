#include "monty.h"
/**
 * print_stack - Prints the elements of the stack
 * @stack_head: Pointer to the head of the stack
 * @unused_counter: Unused counter
 * Return: No return value
 */
void print_stack(stack_t **stack_head, unsigned int unused_counter)
{
	stack_t *current;

	(void)unused_counter;

	current = *stack_head;
	if (current == NULL)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
