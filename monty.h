#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct MontyBus - Variables for Monty interpreter
 * @arg_value: Argument value
 * @monty_file: Pointer to the Monty file
 * @line_content: Line content
 * @stack_mode: Flag for stack/queue mode
 * Description: This structure carries values throughout the program.
 */
typedef struct MontyBus
{
	char *arg_value;
	FILE *monty_file;
	char *line_content;
	int stack_mode;
} MontyBus;
extern MontyBus monty_bus;

void back_stack(stack_t **stk_tete, unsigned int useless_ctr);
void go_stack(stack_t **stk_tete, unsigned int line_number);
void back_top(stack_t **stk_tete, unsigned int line_number);
void rm_stack(stack_t **stk_tete, unsigned int useless_ctr);
void swap_objects(stack_t **stk_tete, unsigned int useless_ctr);
void f_add_objects(stack_t **stk_tete, unsigned int useless_ctr);
void f_nothing(stack_t **stk_tete, unsigned int useless_ctr);
void free_stack(stack_t *stk_tete);
int run(char *line_content, stack_t **stk_tete, unsigned int useless_ctr, FILE *monty_file);
void add_node_to_queue(stack_t **stk_tete, int new_value);
void add_node_to_stack(stack_t **stk_tete, int new_value);

#endif
