#include "monty.h"

/**
 * swap -  swaps data from top to previous
 * @stack: stack given by main
 * @line_number: amount of lines
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	int tmp_n = 0;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	tmp_n = tmp->n;
	tmp->n = tmp_n;

	tmp->n = tmp->next->n;
	tmp->next->n = tmp_n;
}
/**
 * _add -  adds the first two nodes of the stack
 * @stack: stack given by main
 * @line_number: line counter
 *
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, line_number);
	(*stack)->n = result;
}
/**
 * nop -  does nothing
 * @stack: doesnt matter
 * @line_number : for nothing
 *
 * Return: NOTHING
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
