#include "shell.h"

/**
 * cmd_env - prints env variables in the current shell
 * @s: input from the user.
 */

void cmd_env(__attribute__((unused))char *s)
{
	int a, b;

	for (a = 0; environ[a] != NULL; a++)
	{
		for (b = 0; environ[a][b] != '\0'; b++)
		{
			write(STDOUT_FILENO, &environ[a][b], 1);
		}
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * cmd_exit - exits the shell
 * @line: input from the user
 */

void cmd_exit(char *line)
{
	free(line);
	_printstr("\n", 1);
	exit(0);
}
