#include "shell.h"

/**
 * line_format - Parses the command line, extracting
 * commands and arguments
 * @line: Pointer to a string representing the command line.
 * It will always be NULL upon function entry
 * @size: Holder for the size of the string.
 * It is always initialized to 0.
 * @cmdCount: counter keeping track of the number of commands
 * @ret: Name of the program running the shell.
*/

void line_format(char *line, size_t size, int cmdCount, char **ret)
{
	int i;
	ssize_t read_len;
	int token_iterator;
	char **args_array;
	const char *delim = "\n\t ";

	token_iterator = 0;
	write(STDOUT_FILENO, PROMPT, _strlen(PROMPT));
	read_len = getline(&line, &size, stdin);
	if (read_len != -1)
	{
		args_array = int_token(line, delim, token_iterator);
		if (args_array[0] == NULL)
		{
			free_sng(2, args_array, line);
			return;
		}
		i = execute_builtin(args_array, line);
		if (i == -1)
			spawn_process(args_array, line, cmdCount, ret);
		for (i = 0; args_array[i] != NULL; i++)
			free(args_array[i]);
		free_sng(2, args_array, line);
	}
	else
	{
		cmd_exit(line);
	}
}

/**
 * spawn_process - Creates a child process to execute
 * a command
 * @args_array: array of pointers
 * @line: input
 * @cmdCount: keeps count of commands entered
 * @ret: program name
 */

void spawn_process(char **args_array, char *line, int cmdCount, char **ret)
{
	pid_t id;
	int index, status, conf;
	struct stat buf;
	char *tmpCmd, *cmd;

	id = fork();
	if (id == 0)
	{
		tmpCmd = args_array[0];
		cmd = path_finder(args_array[0]);
		if (cmd == NULL)
		{
			conf = stat(tmpCmd, &buf);
			if (conf == -1)
			{
				print_err(ret[0], cmdCount, tmpCmd);
				_printstr(": not found", 0);
				free_sng(2, line, tmpCmd);
				for (index = 1; args_array[index]; index++)
					free(args_array[index]);
				free(args_array);
				exit(100);
			}
			cmd = tmpCmd;
		}
		args_array[0] = cmd;
		if (args_array[0] != NULL)
		{
			if (execve(args_array[0], args_array, environ) == -1)
				handle_exec_error(ret[0], cmdCount, tmpCmd);
		}
	}
	else
		wait(&status);
}
