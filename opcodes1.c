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

/**
 * pop - function for push opcode
 * @stack: stack memory
 * @line_number: operand
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	char *msg = allocate(300);

	if ((*stack) == NULL)
	{
		sprintf(msg, "L%d: can't pop an empty stack\n", line_number);
		print_err(msg);
		return;
	}
	else
	{
		tmp = *stack;
		*stack = (*stack)->next;
		if(*stack)
		(*stack)->prev = NULL;
		free(tmp);
	}
	free(msg);
}

/**
 * swap - function for push opcode
 * @stack: stack memory
 * @line_number: operand
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	char *msg = allocate(300);

	if ((*stack) == NULL )
	{
		sprintf(msg, "L%d: can't swap, stack too short\n", line_number);
		print_err(msg);
		return;
	}
	else if ((*stack)->next == NULL )
	{
		sprintf(msg, "L%d: can't swap, stack too short\n", line_number);
		print_err(msg);
		return;
	}
	else
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		(*stack)->prev = tmp->prev;
		tmp->prev = NULL;
		tmp->next = *stack;
		(*stack) = tmp;
	}
	free(msg);
}
