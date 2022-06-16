#include "monty.h"
/**
 * push - function for push opcode
 * @stack: stack memory
 * @line_number: operand
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack = allocate(sizeof(stack_t));

	new_stack->prev = NULL;
	new_stack->next = NULL;
	new_stack->n = line_number;

	if ((*stack) == NULL)
	{
		(*stack) = new_stack;
	}
	else
	{
		new_stack->next = (*stack);
		(*stack) = new_stack;
	}
}

/**
 * pall - function for pall opcode
 * @stack: stack memory
 * @line_number: operand
 * Return: void
 */

void pall(stack_t **stack,
	unsigned int __attribute__((__unused__)) line_number)
{

	/**
	 * __attribute__ - unused attribute
	 */
	stack_t *tmp;

	if ((*stack) == NULL)
	{
		return;
	}
	else
	{
		tmp = *stack;
		while (tmp)
		{
			printf("%d\n", tmp->n);
			tmp = tmp->next;
		}
	}
}

/**
 * pint - function for push opcode
 * @stack: stack memory
 * @line_number: operand
 * Return: void
 */
void pint(stack_t **stack,
		unsigned int __attribute__((__unused__)) line_number)
{
	if ((*stack) == NULL)
	{
		return;
	}
	else
	{
		printf("%d\n", (*stack)->n);
	}
}
