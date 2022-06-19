#include "monty.h"
#include <stdio.h>

/**
 * main - Main monty function
 * @argc: number of arguments
 * @argv: Array of arguments
 * Return: 0
 */

int main(int argc, char **argv)
{
	char *opcode_list[] = {"push", "pall", "pint",
		"pop", "swap", "add", "nop", "sub", "div",
		"mul", "mod", "pchar", "pstr", "rotl", "rotr"};

	void (*fun_list[])(stack_t **stack, unsigned int line_number) = {
		push, pall, pint, pop, swap, add, nop, sub, divs, mul, mod,
		pchar, pstr, rotl, rotr};
	int fd, err = 1, pos, operand, line_num = 0, len = 15;
	char *msg, *opcode;
	stack_t *stacks = NULL;
	instruction_t *instr;

	if (argc != 2)
	print_err("USAGE: monty file\n");
	fd = open(argv[1], O_RDONLY);
	msg = allocate(300);
	instr = allocate(sizeof(instruction_t));
	opcode = allocate(25);
	if (fd < 0)
	{
		sprintf(msg, "Error: Can't open file %s\n", argv[1]);
		print_err(msg);
	}
	while (err)
	{
		err = get_line(&fd, msg, &line_num);
		if (err < 0)
			break;
		get_opcode(opcode, &operand, msg);
		pos = get_instr(opcode_list, opcode, len);
		line_num++;
		if (pos < 0)
		{
			sprintf(msg, "L%d: unknown instruction %s\n", line_num, opcode);
			print_err(msg);
		}
		instr->f = fun_list[pos];
		instr->opcode = opcode;
		execute_line(instr, &stacks, operand, line_num);
	}
	close(fd);
	free(msg);
	free_instr(instr);
	free_stack(&stacks);
	return (0);
}

/**
 * execute_line - Executes an instruction function
 * @instr: number of arguments
 * @stack: Array of arguments
 * @operand: Array of arguments
 * Return: 0
 */

int execute_line(instruction_t *instr, stack_t **stack, int operand, int line_num)
{
	if (strcmp(instr->opcode, "push") == 0)
		(instr->f)(stack, operand);
	else
		(instr->f)(stack, line_num);
	return (1);
}
