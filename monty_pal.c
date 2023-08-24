#include "monty.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/**
 * pall - print all values in stack
 *
 * @stack: pointer to stack
 */

void pall(stack_t *stack)
{
	stack_t *current = stack;

	while (current != NULL)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
}
