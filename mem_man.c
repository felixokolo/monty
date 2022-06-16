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

void free_instr(instruction_t *instr)
{
	free(instr->opcode);
	free(instr);
}

