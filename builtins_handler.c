#include "shell.h"

/**
 * builtin_handler - determines function needed for execution
 * @s: function name
 * Return: void
 */

void (*builtin_handler(char *s))(char *s)
{
	int res;

	builtin_res beta[] = {
		{"env", cmd_env},
		{"exit", cmd_exit},
		{NULL, NULL}
	};

	for (res = 0; beta[res].num != NULL; res++)
	{
		if (_strcmp(s, beta[res].num) == 0)
		{
			return (beta[res].cmd_func);
		}
	}
	return (NULL);
}

/**
 * execute_builtin - executes a built-in command if it exists
 * @args: array of arguments passed to the shell
 * @line: string containing input from user
 *
 * Return: If the command is a built-in, return 0. Otherwise, return -1.
 */

int execute_builtin(char **args, char *line)
{
	void (*func)(char *);

	func = builtin_handler(args[0]);
	if (func == NULL)
	{
		return (-1);
	}
	if (_strcmp("exit", args[0]) == 0)
	{
		free_db(args);
	}
	func(line);
	return (0);
}
