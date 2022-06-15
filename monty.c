#include "monty.h"

/**
 * main - Main monty function
 * @argc: number of arguments
 * @argv: Array of arguments
 * Return - 0
 */

int main(int argc, char **argv)
{
	instruction_t *instr;
	instruction_t *instr_list[30];

	if (argc != 2)
	{
		print_err("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	instr = get_instr(argv[1], 1);
	while (instr)
	{
		
	}
	
}
