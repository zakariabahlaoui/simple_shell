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

	free(_index);
}