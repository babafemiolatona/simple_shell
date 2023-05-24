#include "shell.h"

/**
 * handle_exec_error - handles execution errors and exits.
 * @args: args
 * @len: number of commands entered.
 * @cmd: command that failed
 */

void handle_exec_error(char *args, int len, char *cmd)
{
	print_err(args, len, cmd);
	_printstr(": ", 1);
	perror("");
	exit(0);
}

/**
 * print_err - prints a message error when a comand
 * is not found
 * @args: args
 * @len: number of commands executed in the shell
 * @cmd: command that was not found
 */

void print_err(char *args, int len, char *cmd)
{
	_printstr(args, 1);
	_printstr(": ", 1);
	print_num(len);
	_printstr(": ", 1);
	_printstr(cmd, 1);
}
