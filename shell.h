#ifndef _SHELL_H
#define _SHELL_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <signal.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
* struct builtin - structure representing a built-in command and
* its corresponding function.
* @num: name of the built-in command.
* @cmd_func: point er to the function that executes the built-in command
*/
typedef struct builtin
{
char *num;
void (*cmd_func)(char *);
} builtin_res;
extern char **environ;

int _strlen(char *);
int _putchar(char);
int _strcmp(char *, char *);

char *_strdup(char *);
void _printstr(char *, int);
int print_num(int nin);
void free_db(char **);
void free_sng(int, ...);
void print_err(char *, int, char *);
void handle_exec_error(char *, int, char *);

void (*builtin_handler(char *))(char *);
void cmd_env(char *);
void cmd_exit(char *);
int execute_builtin(char **, char *);

#endif
