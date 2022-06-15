#include "monty.h"

/**
 * print_err - Prints to stderr
 * @text: Text to print to stderr
 * Return: number of characters printed
 */

int print_err(const char *text)
{
	int len = -1;

	len = strlen(text);
	write(STDERR_FILENO, text, len);
	return (len);
}

/**
 * print_out - Prints to stdout
 * @text: Text to print to stdout
 * Return: number of characters printed
 */

int print_out(const char *text)
{
	int len = -1;

	len = strlen(text);
	write(STDOUT_FILENO, text, len);
	return (len);
}
