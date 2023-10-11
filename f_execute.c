#include "shell.h"

/**
 * execute_cmd - take array 2D have a string token to
 * command and execute it using exeve
 * @cmd: the 2D array
 * @argv: argv
 * @env: environment variable
 *
 * Return: is void
 */

void execute_cmd(char **cmd, char **argv, char **env)
{
	pid_t id;
	int status;

	id = fork();

	if (id == 0)
	{
		if (execve(cmd[0], cmd, env) == -1)
		{
			perror(argv[0]);
			freearray(cmd);
			exit(0);
		}
	}
	else
	{
		waitpid(id, &status, 0);
		freearray(cmd);
	}
}
