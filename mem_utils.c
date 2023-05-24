#include "shell.h"

/**
 * free_sng - frees a given number of pointers to strings
 * @num: number of pointers to free
 */

void free_sng(int num, ...)
{
	int dit;
	char *ptr;
	va_list args_list;

	va_start(args_list, num);
	for (dit = 0; dit < num; dit++)
	{
		ptr = va_arg(args_list, char*);

		if (ptr == NULL)
		{
			ptr = "(nil)";
		}
		free(ptr);
	}
	va_end(args_list);
}

/**
 * free_db - frees memory allocated for a double
 * pointer and its elements
 * @db_ptr: double pointer to be freed
*/

void free_db(char **db_ptr)
{
	int i;

	for (i = 0; db_ptr[i] != NULL; i++)
	{
		free(db_ptr[i]);
	}
	free(db_ptr);
}

/**
 * print_num - prints an unsigned number
 * @nin: unsigned int
 * Return: int
 */

int print_num(int nin)
{
	int quo, l;
	unsigned int lat;

	quo = 1;
	l = 0;
	lat = nin;
	while (lat / quo > 9)
	{
		quo *= 10;
	}
	while (quo != 0)
	{
		l += _putchar('0' + lat / quo);
		lat %= quo;
		quo /= 10;
	}
	return (l);
}
