#include "monty.h"

/**
 * allocate - Allocate memory
 * @size: size of memory to allocate
 * Return: 1 for success -1 for error
 */

void *allocate(size_t size)
{
	void *allocated;

	allocated = malloc(sizeof(instruction_t));
	if (allocated < 0)
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

