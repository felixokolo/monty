#include "monty.h"
#include <stdio.h>

/*instruction_t *instr_list[] = { {"push",
								push},
								{"pall",
								pall}
								};*/

char *opcode_list[] = {"push", "pall", "pint"};
void (*fun_list[])(stack_t **stack, unsigned int line_number) = {push, pall};

/**
 * main - Main monty function
 * @argc: number of arguments
 * @argv: Array of arguments
 * Return - 0
 */

int main(int argc, char **argv)
{
	instruction_t *instr;
	int fd, err = 1, len, line_num = 1, pos, operand;
	char *msg, *opcode;
	stack_t *stacks = NULL;
	
	
	
	
	if (argc != 2)
	{
		print_err("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	//mon_file = open(argv[1], "r");
	fd = open(argv[1], O_RDONLY);
	msg = allocate(300);
	instr = allocate(sizeof(instruction_t));
	opcode = allocate(25);
	if (fd < 0)
	{
		sprintf(msg, "Error: Can't open file %s\n", argv[1]);
		print_err(msg);
		exit(EXIT_FAILURE);
	}
	
	
	while (err)
	{
		err = get_line(&fd, msg);
		if (err < 0)
			break;
		//printf("line %s\n", msg);
		get_opcode(opcode, &operand, msg);
		//printf("ops %s\n", opcode);
		
		pos = get_instr(instr, opcode_list, opcode, 2);
		//printf("opcode %s\n", instr->opcode);
		if (pos < 0)
		{
			sprintf(msg, "L %d: unknown instruction %s\n", line_num, opcode);
			print_err(msg);
		}
		//printf("opcode %s\n", instr->opcode);
		instr->f = fun_list[pos];
		instr->opcode = opcode;
		
		execute_line(instr, &stacks, operand);
		//printf("top stack %d\n", stacks->n);
		//printf("opcode %s\n", instr->opcode);
	}
	
	close(fd);
	free(msg);
	free_instr(instr);
}

int execute_line(instruction_t *instr, stack_t **stack, int operand)
{
	(instr->f)(stack, operand);
}
