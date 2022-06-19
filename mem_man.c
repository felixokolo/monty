#include "monty.h"

/**
 * allocate - Allocate memory
 * @size: size of memory to allocate
 * Return: 1 for success -1 for error
 */

void *allocate(size_t size)
{
	void *allocated;

	allocated = malloc(size);
	if (allocated == NULL)
	{
		print_err("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	return (allocated);
}


/**
 * free_instr - Frees memory
 * @instr: memory to free
 * Return: void
 */
void free_instr(instruction_t *instr)
{
	free(instr->opcode);
	free(instr);
}

/**
 * free_stack - Frees memory
 * @instr: memory to free
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;
	if(*stack)
	{
		while(*stack)
		{
			tmp = (*stack)->next;
			free(*stack);
			*stack = tmp;
		}
	}
}
