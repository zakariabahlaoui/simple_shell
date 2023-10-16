#include "shell.h"

/**
 * freearray - this function free array 2D
 * @arr: the array
 *
 * Return: is void
 */

void freearray(char **arr)
{
	int i;

	if (!arr)
		return;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

/**
 * _strdel - free and assign NULL to adress pointer
 * @str: the adress pointer
 *
 * Return: is void
 */

void _strdel(char **str)
{
	if (str == NULL || *str == NULL)
		return;
	free(*str);
	*str = NULL;
}

/**
 * print_error - print error if the path not fund
 * @sh: name the program
 * @cmd: command
 * @index: the index to command
 *
 * Return: is void
 */

void print_error(char *sh, char *cmd, int index)
{
	char *_index;

	_index = _itoa(index);

	write(STDERR_FILENO, sh, _strlen(sh));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, _index, _strlen(_index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": not found", 11);
	write(STDERR_FILENO, "\n", 1);

	free(_index);
}

void print_env(char **env)
{
	int i = 0;
	int len = 0;

	while (env[i])
	{
		len = _strlen(env[i]);
		write(STDERR_FILENO, env[i], len);
		write(STDERR_FILENO, "\n", 1);
		i++;
	}
}