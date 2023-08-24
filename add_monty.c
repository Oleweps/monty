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
	stack_t *top;
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		line_or_integer_err(": can't add, stack too short", line);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	*stack = (*stack)->next; /* Move to the next element */
	sum = top->n + (*stack)->n; /* Declare variable here */
	(*stack)->n = sum;

	free(top); /* Free the previous top element */

	return (*stack);
}
