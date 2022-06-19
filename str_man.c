#include "monty.h"

/**
 * get_opcode - Gets instruction from file
 * @dst: String of file name to obtain instruction
 * @operand: String of file name to obtain instruction
 * @line: Line to get instruction
 * Return: int
 */

int get_opcode(char *dst, int *operand, char *line)
{
	char *copy, *token, *args[30];
	int n = 0;

	copy = allocate(strlen(line) + 1);
	strcpy(copy, line);
	token = strtok(copy, " \t");
	if (*token == '#')
		strcpy(dst, "nop");
	else
		strcpy(dst, token);
	while (token != NULL)
	{
		token = strtok(NULL, " \t");
		if (token != NULL)
		{
			args[n] = allocate(strlen(token) + 1);
			strcpy(args[n], token);
			n++;
		}
		
	}
		
	if (strcmp(dst, "push") == 0)
	*operand = atoi(args[0]);
	/*else if (n > 1)
		strcpy(dst, "nop");*/
	free(copy);
	while (n > 0)
	{
		free(args[n - 1]);
		n--;
	}
	return (1); 
}

/**
 * get_line - Gets line from file
 * @fd: String of file name to obtain instruction
 * @dst: Line to get instruction
 * Return: int
 */
int get_line(int *fd, char *dst, int *line_num)
{
	int len = 0, tot = 0;
	char c;

	do {
		len = read(*fd, &c, 1);

		if (len == 0 || c == '\n')
		{
			if ((c == '\n' || len == 0) && tot > 0)
			{
				*(dst + tot) = '\0';
				break;
			}
			else if (len == 0 && tot == 0)
			{
				return (-1);
			}
			else
			{
				(*line_num)++;
				continue;
			}
		}
		*(dst + tot) = c;
		tot += len;
	} while (len > 0);


	return (tot);
}

/**
 * get_instr - Gets line from file
 * @opcode_list: String of file name to obtain instruction
 * @opcode: Line to get instruction
 * @len: Line to get instruction
 * Return: int
 */
int get_instr(char *opcode_list[], char *opcode, int len)
{
	int pos = 0;

	while (pos < len)
	{
		if (strcmp(opcode_list[pos], opcode) == 0)
		break;
		pos++;
	}

	if (pos == len)
	return (-1);

	return (pos);
}
