#include "monty.h"


/**
 * get_instr - Gets instruction from file
 * @f: String of file name to obtain instruction
 * @line: Line to get instruction
 * Return: instruction_t
 */

int get_opcode(char *dst, int *operand, char *line)
{
	int len, err, argu;
	char *saveptr, *copy, *token;

	copy = allocate(sizeof(strlen(line)));
	strcpy(copy, line);
	token = strtok_r(copy, " \t", &saveptr);
	strcpy(dst, token);
	*operand = atoi(strtok_r(NULL, " \t", &saveptr));
	//printf("operand = %d\n", *operand);
	free(copy);
	return 1;
}

/*int get_opcode(char *dst, int *operand, char *line)
{
	int len = 0, err, argu, pos = 0;

	while(*(line + len) != '\n' && *(line + len) != '\0')
	{
		if (*(line + len) == '\t' || *(line + len) == ' ')
		{
			len++;
			printf("tab\n");
			if (pos == 0)
			continue;
			else
			break;
		}
		else
		{
			*(dst + pos) = *(line + len);
			pos++;
			len++;
		}
		
	}
	*(dst + pos) = '\0';
	return 1;
}*/

int get_line(int *fd, char *dst)
{
	int len = 0, tot = 0;
	char c;
	
	do{
		len = read(*fd, &c, 1);
		
		if (len == 0 || c == '\n')
		{
			if ((c == '\n' || len == 0) && tot > 0)
			{
				*(dst + tot) = '\0';
				break;
			}
			else if(len == 0 && tot == 0)
				return (-1);
			else
				continue;
		}
		*(dst + tot) = c;
		tot += len;
	} while(len > 0);
	

	return (tot);
}

int get_instr(instruction_t *instr, char *opcode_list[], char *opcode, int len)
{
	int pos = 0;
	
	//printf("lent of arr = %d\n", len);
	//printf("gets here ops %s\n", opcode);
	while(pos < len)
	{
		//printf("gets here %s\n", opcode_list[pos]);
		if (strcmp(opcode_list[pos], opcode) == 0)
		break;
		
		pos++;
	}
	
	if (pos == len)
	return (-1);
	
	//instr->opcode = opcode;
	return (pos);
}
