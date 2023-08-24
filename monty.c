#include "monty.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/**
 * main - monty entry point
 *
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: 1 if success else return 0
 */

int main(int argc, char *argv[])
{
	stack_t *stack;
	char *data;
	char **sep;
	stack_t *new;

	if (argc != 2)
	{
		print_error("USAGE: monty file", NULL);
		return (EXIT_FAILURE);
	}

	/* Variable declarations */
	stack = NULL;
	data = get_file_data(argv[1]);
	sep = separate_string(data, "\n");
	new = execute_codes(&stack, sep);

	/* Clean up */
	free_list(sep);
	free(data);
	free_stack(new);
	/* Return exit status based on stack */
	return ((stack == NULL) ? EXIT_SUCCESS : EXIT_FAILURE);
}
