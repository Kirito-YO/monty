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
/**
 * push_to_stack - Adds a node to the stack
 * @stack_head: Pointer to the head of the stack
 * @line_number: Line number
 * Return: No return
 */
void push_to_stack(stack_t **stack_head, unsigned int line_number)
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
            free_stack(*stack_head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        fclose(monty_bus.monty_file);
        free(monty_bus.line_content);
        free_stack(*stack_head);
        exit(EXIT_FAILURE);
    }
    value = atoi(monty_bus.arg_value);
    if (monty_bus.stack_mode == 0)
        add_node_to_stack(stack_head, value);
    else
        add_node_to_queue(stack_head, value);
}
