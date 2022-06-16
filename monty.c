#include "monty.h"
#include <stdio.h>


/**
 * main - Main monty function
 * @argc: number of arguments
 * @argv: Array of arguments
 * Return - 0
 */

int main(int argc, char **argv)
{
	instruction_t *instr;
	int err = 1, len;
	char *msg;
	FILE *mon_file;

	mon_file = fopen(argv[1], "r");
	msg = allocate(200);
	if (mon_file == NULL)
	{
		sprintf(msg, "Error: Can't open file %s\n", argv[1]);
		print_err(msg);
	}
	if (argc != 2)
	{
		print_err("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	
	while (err)
	{
		err = getline(&msg, &len, mon_file);
		if (err < 0)
			break;
		instr = get_instr(msg);
	}
	
	fclose(mon_file);
}
