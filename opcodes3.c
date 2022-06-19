#include "monty.h"
/**
 * mod - function for push opcode
 * @stack: stack memory
 * @line_number: operand
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int a;
	char *msg = allocate(300);

	if ((*stack) == NULL )
	{
		sprintf(msg, "L%d: can't mod, stack too short\n", line_number);
		print_err(msg);
		return;
	}
	else if ((*stack)->next == NULL )
	{
		sprintf(msg, "L%d: can't mod, stack too short\n", line_number);
		print_err(msg);
		return;
	}
	else
	{
		a = (*stack)->n;
		if (a == 0)
		{
			sprintf(msg, "L%d: division by zero\n", line_number);
			print_err(msg);
		}
		pop(stack, 0);
		(*stack)->n %= a;
	}
	free(msg);
}


/**
 * pchar - function that prints an ascii character
 * @stack: stack memory
 * @line_number: operand
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int a;
	char *msg = allocate(300);

	if ((*stack) == NULL )
	{
		sprintf(msg, "L%d: can't pchar, stack empty\n", line_number);
		print_err(msg);
		return;
	}
	else
	{
		a = (*stack)->n;
		if (a > 127 || a < 0)
		{
			sprintf(msg, "L%d: can't pchar, value out of range\n", line_number);
			print_err(msg);
		}
		printf("%c\n", (*stack)->n);
	}
	free(msg);
}


/**
 * pstr - function that prints an ascii character
 * @stack: stack memory
 * @line_number: operand
 * Return: void
 */
void pstr(stack_t **stack,
	unsigned int __attribute__((__unused__)) line_number)
{
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
			if (tmp->n == 0)
				break;
			else
			printf("%c", tmp->n);
			tmp = tmp->next;
		}
		printf("\n");
	}
}

/**
 * rotl - function for push opcode
 * @stack: stack memory
 * @line_number: operand
 * Return: void
 */
void rotl(stack_t **stack,
	unsigned int __attribute__((__unused__)) line_number)
{
	stack_t *tmp;

	if ((*stack) == NULL )
	{
		return;
	}
	else if ((*stack)->next == NULL )
	{
		return;
	}
	else
	{
		tmp = (*stack);
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = *stack;
		(*stack)->prev = tmp;
		tmp = (*stack)->next;
		(*stack)->next = NULL;
		(*stack) = tmp;
		(*stack)->prev = NULL;
	}
}

/**
 * rotr - function for push opcode
 * @stack: stack memory
 * @line_number: operand
 * Return: void
 */
void rotr(stack_t **stack,
	unsigned int __attribute__((__unused__)) line_number)
{
	stack_t *tmp;

	if ((*stack) == NULL )
	{
		return;
	}
	else if ((*stack)->next == NULL )
	{
		return;
	}
	else
	{
		tmp = (*stack);
		while(tmp->next)
			tmp = tmp->next;
		(*stack)->prev = tmp;
		tmp->next = *stack;
		tmp->prev->next = NULL;
		(*stack) = tmp;
		(*stack)->prev = NULL;
	}
	
}
