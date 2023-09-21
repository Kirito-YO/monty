#include "monty.h"
/**
 * add_node_to_stack - Adds a new node to the head of the stack
 * @stk_tete: Pointer to the head of the stack
 * @new_value: New value to add to the stack
 * Return: No return
 */
void add_node_to_stack(stack_t **stk_tete, int new_value)
{
	stack_t *new_node, *temp;

	temp = *stk_tete;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(monty_bus.monty_file);
		free(monty_bus.line_content);
		free_stack(*stk_tete);
		exit(EXIT_FAILURE);
	}
	if (temp)
		temp->prev = new_node;
	new_node->n = new_value;
	new_node->next = *stk_tete;
	new_node->prev = NULL;
	*stk_tete = new_node;
}

/**
 * add_node_to_queue - Adds a new node to the tail of the stack
 * @stk_tete: Pointer to the head of the stack
 * @new_value: New value to add to the stack
 * Return: No return
 */
void add_node_to_queue(stack_t **stk_tete, int new_value)
{
	stack_t *new_node, *temp;

	temp = *stk_tete;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(monty_bus.monty_file);
		free(monty_bus.line_content);
		free_stack(*stk_tete);
		exit(EXIT_FAILURE);
	}
	new_node->n = new_value;
	new_node->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*stk_tete = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}
