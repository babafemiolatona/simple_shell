#include "shell.h"

/**
 * main - Entry point of the program.
 * @argc: argument count
 * @ret: argument vector
 * Return: Always 0.
 */

int main(__attribute__((unused)) int argc, char **ret)
{
	char *line;
	size_t size;
	int cmdCount;

	cmdCount = 0;
	signal(SIGINT, SIG_IGN);
	while (1)
	{
		cmdCount++;
		line = NULL;
		size = 0;
		line_format(line, size, cmdCount, ret);
	}
	return (0);
}
