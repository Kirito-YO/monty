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
