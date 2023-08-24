#include "monty.h"
#include <stdlib.h>

/**
 * push - function to add item to stack.
 *
 * @data: data to add to stack
 * @stack: pointer to stack.
 *
 * Return: pointer to stack.
 */

stack_t *push(stack_t *stack, char *data)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		print_error("Error: malloc failed", NULL);
		exit(EXIT_FAILURE);
	}

	new->prev = NULL;
	new->n = atoi(data);
	new->next = stack;

	if (stack != NULL)
	{
		stack->prev = new;
	}

	return (new);
}
