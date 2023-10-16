#include "shell.h"

/**
 * main - main simple shell
 * @ac: argc
 * @argv: argv
 * @env: envirment varible
 *
 * Return: return
 */

int main(int ac, char **argv, char **env)
{
	char *line = NULL;
	char **cmd = NULL;
	int index = 0;
	int stat = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		line = read_line();

		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (stat);
		}
		index++;

		cmd = _tokenizer(line);
		if (cmd == NULL)
			continue;

		if (_strcmp(cmd[0], "exit") == 0)
		{
			freearray(cmd);
			exit(stat);
		}
		if (_strcmp(cmd[0], "env") == 0)
		{
			print_env(env);
			stat = 0;
		}

		stat = execute_cmd(cmd, argv, env, index);
	}
}
