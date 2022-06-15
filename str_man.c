#include "monty.h"

/**
 * get_instr - Gets instruction from file
 * @f: String of file name to obtain instruction
 * @line: Line to get instruction
 * Return: instruction_t
 */

instruction_t *get_instr(char *line)
{
	int len, err, argu;
	instruction_t *instr;
	char *opcode;

	instr = allocate(sizeof(instruction_t));
	opcode = allocate(25);
	
	
	strtok(line, " ");
	opcode = strtok(NULL, " ");
	instr->opcode = opcode;
	
	return (instr);
}
