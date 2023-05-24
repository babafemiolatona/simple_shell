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

/**
 * cmd_cd - Changes the current working directory
 * @line: string input
 */

void cmd_cd(char *line)
{
	int index, token_iterator;
	char **args_array;
	const char *delim = "\n\t ";

	token_iterator = 0;
	args_array = int_token(line, delim, token_iterator);
	if (args_array[0] == NULL)
	{
		free_sng(2, args_array, line);
		return;
	}
	if (args_array[1] == NULL)
	{
		index = locate_path("HOME");
		chdir((environ[index]) + 5);
	}
	else if (_strcmp(args_array[1], "-") == 0)
		_printstr(args_array[1], 0);

	else
		chdir(args_array[1]);
	free_db(args_array);
}
