#include "monty.h"

/**
 * push - push element into the stack
 * @stack: stack given by main
 * @line_number: amount of lines
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *n = global.argument;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (global.data_struct == 1)
	{
		if (!add_node(stack, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!queue_node(stack, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
}
/**
 * pall - prints the stack
 * @stack: stack given by main in start.c
 * @line_number: amount of lines
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	print_stack(*stack);
}

/**
* pop - pops the very top element of the stack
* @stack: stack given by main
* @line_number: line number for error messages
*
* Return: void
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	if (!*stack)
		return; /* prevents errors cause next line might assign a NULL */
	(*stack)->prev = NULL;
}
/**
 * pint - print the value at the top of the stack
 * @stack: stack given by main
 * @line_number: amount of lines
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);

	}
	printf("%d\n", (*stack)->n);
}
