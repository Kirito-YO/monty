#include "monty.h"
MontyBus monty_bus = {NULL, NULL, NULL, 0};
/**
 * main - Monty code interpreter
 * @argc: Number of arguments
 * @argv: Monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *line_content;
	FILE *monty_file;
	size_t size = 0;
	ssize_t lire_ligne = 1;
	stack_t *stk_tete = NULL;
	unsigned int useless_ctr = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r");
	monty_bus.monty_file = monty_file;
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (lire_ligne > 0)
	{
		line_content = NULL;
		lire_ligne = getline(&line_content, &size, monty_file);
		monty_bus.line_content = line_content;
		useless_ctr++;
		if (lire_ligne > 0)
		{
			execute(line_content, &stk_tete, useless_ctr, monty_file);
		}
		free(line_content);
	}
	free_stack(stk_tete);
	fclose(monty_file);
	return (0);
}
