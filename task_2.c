#include "monty.h"
/**
 * rm_stack - Removes the top element from the stack
 * @stk_tete: Pointer to the head of the stack
 * @useless_ctr: Line number
 * Return: No return
 */
void rm_stack(stack_t **stk_tete, unsigned int useless_ctr)
{
    stack_t *temp;

    if (*stk_tete == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", useless_ctr);
        fclose(monty_bus.monty_file);
        free(monty_bus.line_content);
        free_stack(*stk_tete);
        exit(EXIT_FAILURE);
    }
    temp = *stk_tete;
    *stk_tete = temp->next;
    free(temp);
}
