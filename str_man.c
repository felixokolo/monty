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
	char *msg;

	instr = allocate(sizeof(instruction_t));
	msg = allocate(1000);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		sprintf(msg, "Error: Can't open file %s\n", path);
		print_err(msg);
	}
	
	close(fd);
		
	return (instr);
}
