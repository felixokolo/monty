#include "monty.h"
/**
 * add - function for push opcode
 * @stack: stack memory
 * @line_number: operand
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int a;
	char *msg = allocate(300);

	if ((*stack) == NULL )
	{
		sprintf(msg, "L%d: can't add, stack too short\n", line_number);
		print_err(msg);
		return;
	}
	else if ((*stack)->next == NULL )
	{
		sprintf(msg, "L%d: can't add, stack too short\n", line_number);
		print_err(msg);
		return;
	}
	else
	{
		a = (*stack)->n;
		pop(stack, 0);
		(*stack)->n = (*stack)->n + a;
	}
	free(msg);
}

/**
 * pall - function for pall opcode
 * @stack: stack memory
 * @line_number: operand
 * Return: void
 */

void nop(stack_t __attribute__((__unused__)) **stack,
	unsigned int __attribute__((__unused__)) line_number)
{

	/**
	 * __attribute__ - unused attribute
	 */
	return;
}

/**
 * sub - function for push opcode
 * @stack: stack memory
 * @line_number: operand
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int a;
	char *msg = allocate(300);

	if ((*stack) == NULL )
	{
		sprintf(msg, "L%d: can't sub, stack too short\n", line_number);
		print_err(msg);
		return;
	}
	else if ((*stack)->next == NULL )
	{
		sprintf(msg, "L%d: can't sub, stack too short\n", line_number);
		print_err(msg);
		return;
	}
	else
	{
		a = (*stack)->n;
		pop(stack, 0);
		(*stack)->n -= a;
	}
	free(msg);
}

/**
 * div - function for push opcode
 * @stack: stack memory
 * @line_number: operand
 * Return: void
 */
void divs(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int a;
	char *msg = allocate(300);

	if ((*stack) == NULL )
	{
		sprintf(msg, "L%d: can't div, stack too short\n", line_number);
		print_err(msg);
		return;
	}
	else if ((*stack)->next == NULL )
	{
		sprintf(msg, "L%d: can't div, stack too short\n", line_number);
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
		(*stack)->n /= a;
	}
	free(msg);
}

/**
 * mul - function for push opcode
 * @stack: stack memory
 * @line_number: operand
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int a;
	char *msg = allocate(300);

	if ((*stack) == NULL )
	{
		sprintf(msg, "L%d: can't mul, stack too short\n", line_number);
		print_err(msg);
		return;
	}
	else if ((*stack)->next == NULL )
	{
		sprintf(msg, "L%d: can't mul, stack too short\n", line_number);
		print_err(msg);
		return;
	}
	else
	{
		a = (*stack)->n;
		pop(stack, 0);
		(*stack)->n *= a;
	}
	free(msg);
}

