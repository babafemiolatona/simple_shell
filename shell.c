#include "shell.h"

/**
 * main - Entry point of the program.
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0.
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *input_line;
	size_t line_size;
	int cmdCount;

	cmdCount = 0;
	signal(SIGINT, SIG_IGN);
	while (1)
	{
		cmdCount++;
		input_line = NULL;
		line_size = 0;
		line_format(input_line, line_size, cmdCount, argv);
	}
	return (0);
}
