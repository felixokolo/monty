#include "monty.h"

/**
 * get_instr - Gets instruction from file
 * @f: String of file name to obtain instruction
 * @line: Line to get instruction
 * Return: instruction_t
 */

instruction_t *get_instr(const char *path, int line)
{
	int fd;
	instruction_t *instr;

	instr = malloc(sizeof(instruction_t));
	if (instr < 0)
		write(STDERR_FILENO, "ERROR malloc\n", 12);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		write(STDERR_FILENO, "ERROR\n", 6);
	return (instr);
}
