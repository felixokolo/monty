#include "monty.h"
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
	
	//printf("added %d\n", line_number);
	
}
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	if ((*stack) == NULL)
	{
		return;
		
	}
	else
	{
		tmp = *stack;
		while(tmp)
		{
			printf("%d", tmp->n);
			if (tmp->next)
				printf("\n");
			tmp = tmp->next;
		}
	}
	
	//printf("added %d\n", line_number);
}

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	if ((*stack) == NULL)
	{
		return;
		
	}
	else
	{
		tmp = *stack;
		while(tmp)
		{
			printf("%d\n", tmp->n);
			tmp = tmp->next;
		}
	}
	
	//printf("added %d\n", line_number);
}
