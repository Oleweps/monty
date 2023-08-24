#include "monty.h"
#include <stdlib.h>

/**
 * add - function to add top two elements in stack
 *
 * @stack: pointer to stack.
 * @line: line number of the opcode
 *
 * Return: pointer to stack
 */

stack_t *add(stack_t **stack, int line)
{
	stack_t *top = *stack;
	int sum = top->n + top->next->n;
	stack_t *temp = top->next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		line_or_integer_err(": can't add, stack too short", line);
		exit(EXIT_FAILURE);
	}

	top->next->n = sum;
	top->next = temp->next;if (temp->next)
	{
		temp->next->prev = top;
	}
	free(temp);

	return (top);
}
