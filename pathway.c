#include "shell.h"

/**
 * path_finder - interface for functions that will be able to
 * locate the full path of program
 * @cmd: Represents a command
 * Return: (0)sucess a string with the full path of the program
 */
char *path_finder(char *cmd)
{
	char *constr, **p_tokens, *str = "PATH";
	int index;
	char *dir;

	index = locate_path(str);
	p_tokens = tokenize_path(index, str);
	if (p_tokens == NULL)
	{
		return (NULL);
	}

	dir = search_dir(p_tokens, cmd);
	if (dir == NULL)
	{
		free_db(p_tokens);
		return (NULL);
	}

	constr = create_path(dir, cmd);
	if (constr == NULL)
	{
		free_db(p_tokens);
		return (NULL);
	}

	free_db(p_tokens);
	return (constr);
}
/**
 * locate_path - Finds the index of an environmental variable.
 * @str: Environmental variable that needs to be found.
 * Return: Upon success returns the index of the environmental variable.
 * otherwise returns -1.
 */

int locate_path(char *str)
{
	int i;
	int len;
	int j;

	len = _strlen(str);
	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; j < len; j++)
		{
			if (environ[i][j] != str[j])
				break;
		}
		if (j == len && environ[i][j] == '=')
			return (i);
	}
	return (-1);
}

/**
 * tokenize_path - Separates a string representing paths as an array
 * of strings contining the path directories.
 * @index: Index of the path in the environment variables.
 * @str: string to separate and tokenize.
 * Return: Upon success a NULL terminated array of pointer to strings
 */

char **tokenize_path(int index, char *str)
{
	char *env_var;
	int token_count;
	const char *sep = ":\n";
	char **p_tokens;
	int len;

	len = _strlen(str);
	token_count = 0;

	env_var = environ[index] + (len + 1);
	p_tokens = int_token(env_var, sep, token_count);
	if (p_tokens == NULL)
		return (NULL);

	return (p_tokens);
}

/**
 * search_dir - Looks through directories
 * @path_tokens: A pointer to an array of strings
 * @cmd: Represents a command
 * Return: Upon success a string with the upper most directory containing
 * the command file. Otherwise returns NULL.
 */

char *search_dir(char **path_tokens, char *cmd)
{
	int i, s;
	char *cwd;
	char *buf;
	size_t size;
	struct stat stat_buf;

	buf = NULL;
	size = 0;
	cwd = getcwd(buf, size);
	if (cwd == NULL)
		return (NULL);
	if (cmd[0] == '/')
		cmd += 1;
	for (i = 0; path_tokens[i] != NULL; i++)
	{
		s = chdir(path_tokens[i]);
		if (s == -1)
		{
			perror("ERROR!");
			return (NULL);
		}
		s = stat(cmd, &stat_buf);
		if (s == 0)
		{
			chdir(cwd);
			free(cwd);
			return (path_tokens[i]);
		}
	}
	chdir(cwd);
	free(cwd);
	return (NULL);
}

/**
 * create_path - Combines two strings one representing the path directory and
 * one representing the command file.
 * @dir: Represents a directory in the path.
 * @cmd: Represents a file in a directory of the path.
 * Return: Upon success a string representing the full path of a command.
 * Otherwise NULL.
 */

char *create_path(char *dir, char *cmd)
{
	int i, j, dir_len, cmd_len, len;
	char *built;

	if (dir == NULL || cmd == NULL)
		return (NULL);
	dir_len = _strlen(dir) + 1;
	cmd_len = _strlen(cmd) + 1;
	len = dir_len + cmd_len;

	built = malloc(sizeof(char) * len);
	if (built == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
	{
		for (j = 0; dir[j] != '\0'; j++, i++)
			built[i] = dir[j];
		built[i] = '/';
		i++;
		for (j = 0; cmd[j] != '\0'; j++, i++)
			built[i] = cmd[j];
	}
	built[--i] = '\0';
	return (built);
}
