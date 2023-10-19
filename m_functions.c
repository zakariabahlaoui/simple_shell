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
 * Return: return status
 */

int print_error(char *sh, char **cmd, int index)
{
	char *_index = 0;
	int negative = 1;

	if ((_strcmp(cmd[0], "exit") == 0) && cmd[1] != NULL)
		negative = _atoi(cmd[1]);

	if (negative > -1)
	{
		_index = _itoa(index);
		write(STDERR_FILENO, sh, _strlen(sh));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, _index, _strlen(_index));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, cmd[0], _strlen(cmd[0]));
		write(STDERR_FILENO, ": not found", 11);
		write(STDERR_FILENO, "\n", 1);
		_strdel(&_index);
		return (127);
	}
	return (2);
}

/**
 * print_env - print env
 * @env: env
 *
 * Return: is void
 */

void print_env(char **env)
{
	int i = 0;
	int len = 0;

	while (env[i])
	{
		len = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * f_exit - exit the program
 * @cmd: commamd
 * @argv: argv
 * @status: status
 * @index: index
 *
 * Return: is void
 */

void f_exit(char **cmd, char **argv, int *status, int index)
{
	int stat_exit = 0;
	char *_index;
	char *msg = ": Illegal number: ";

	if (cmd[1] == NULL)
	{
		freearray(cmd);
		exit(*status);
	}
	else
	{
		stat_exit = _atoi(cmd[1]);
		if (stat_exit > 0)
		{
			freearray(cmd);
			exit(stat_exit);
		}
		else if (stat_exit < 1)
		{
			_index = _itoa(index);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, _index, _strlen(_index));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, cmd[0], _strlen(cmd[0]));
			write(STDERR_FILENO, msg, _strlen(msg));
			write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
			write(STDERR_FILENO, "\n", 1);
			_strdel(&_index);
			*status = 2;
		}
	}
}
