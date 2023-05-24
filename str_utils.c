#include "shell.h"

/**
 * _strlen - returns length of a string
 * @s: takes input
 * Return: Always 0
*/
int _strlen(char *s)
{
	int len;

	if (s == NULL)
	{
		return (0);
	}
	for (len = 0; s[len] != '\0'; len++)
		;
	return (len);
}

/**
 * _putchar - Writes a character to stdout
 * @c: Character that will be written to stdout
 * Return: Upon success how many characters were written.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strcmp - compares two strings
 * @a: First string
 * @b: Second string
 * Return: 0 if strings match. -1 Otherwise.
 */

int _strcmp(char *a, char *b)
{
	int _i;

	if (_strlen(a) != _strlen(a))
	{
		return (-1);
	}
	for (_i = 0; a[_i] != '\0'; _i++)
	{
		if (a[_i] != b[_i])
		{
			return (-1);
		}
	}
	return (0);
}
/**
* _strdup - duplicates a string
* @start: original string
* Return: copy of string
*/

char *_strdup(char *start)
{
	int index, length;
	char *end;

	length = _strlen(start);
	end = malloc(sizeof(char) * (length + 1));
	for (index = 0; start[index] != '\0'; index++)
	{
		end[index] = start[index];
	}
	end[index] = '\0';
	return (end);
}

/**
 * _printstr - Prints a string character by character
 * @s: String to be printed
 * @n: if integer is 0 a new line will be printed
 */

void _printstr(char *s, int n)
{
	int ret;

	if (s == NULL)
	{
		s = "(null)";
	}
	for (ret = 0; s[ret] != '\0'; ret++)
	{
		write(STDOUT_FILENO, &s[ret], 1);
	}
	if (n == 0)
	{
		write(STDOUT_FILENO, "\n", 1);
	}
}
