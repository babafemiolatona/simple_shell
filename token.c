#include "shell.h"

/**
 * int_token - interact with other token functions
 * @line: string to tokenize
 * @sep: delimiter used to split the string into tokens
 * @token_iterator: expected number of tokens in the resulting array
 * Return: If successful, the function returns a dynamically
 * allocated array of strings representing the tokens
 */

char **int_token(char *line, const char *sep, int token_iterator)
{
	char **args_arr;

	token_iterator = countToken(line, sep);
	if (token_iterator == -1)
	{
		free(line);
		return (NULL);
	}
	args_arr = split_str(token_iterator, line, sep);
	if (args_arr == NULL)
	{
		free(line);
		return (NULL);
	}

	return (args_arr);
}

/**
 * split_str - splits a string using a specified delimiter
 * and returns the resulting array of tokens
 * @str: The string to tokenize.
 * @sep: The delimiter used to split the string into tokens.
 * @token_len: The expected number of tokens in the resulting array
 * Return: If successful, the function returns a dynamically allocated
 * array of strings representing the tokens.
 */

char **split_str(int token_len, char *str, const char *sep)
{
	int index;
	char **buff, *tok, *sep_cp;

	sep_cp = _strdup(str);
	buff = malloc(sizeof(char *) * (token_len + 1));
	if (buff == NULL)
	{
		return (NULL);
	}
	tok = strtok(sep_cp, sep);
	for (index = 0; tok != NULL; index++)
	{
		buff[index] = _strdup(tok);
		tok = strtok(NULL, sep);
	}
	buff[index] = NULL;
	free(sep_cp);
	return (buff);
}

/**
 * countToken - counts tokens in the input string.
 * @lin: input string
 * @sep: delimeter to separate tokens.
 * Return: success on total count of the tokens.
 * Otherwise -1.
 */

int countToken(char *lin, const char *sep)
{
	char *s;
	char *tok;
	int index;

	s = _strdup(lin);
	if (s == NULL)
	{
		return (-1);
	}
	tok = strtok(s, sep);
	for (index = 0; tok != NULL; index++)
	{
		tok = strtok(NULL, sep);
	}
	free(s);
	return (index);
}
