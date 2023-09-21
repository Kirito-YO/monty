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
