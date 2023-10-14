#include "shell.h"

char *get_path(char **cmd, char **env)
{
	char *all_path = NULL, *path = NULL, *tmp = NULL;
	char **split_path = NULL;
	int i = 0;

	if (!cmd)
		return NULL;

	all_path = ft_getenv("PATH", env);
	if (all_path == NULL)
		return (all_path);

	split_path = ft_split(all_path, ':');

	while (split_path[i])
	{
		tmp = ft_strjoin(split_path[i], "/");
		path = ft_strjoin(tmp, cmd[0]);
		_strdel(&tmp);
		if (access(path, F_OK | X_OK) == 0)
		{
			freearray(split_path);
			_strdel(&all_path);
			return (path);
		}
		_strdel(&path);
		i++;
	}
	freearray(split_path);
	_strdel(&all_path);
	return (NULL);
}

/**
 * execute_cmd - take array 2D have a string token to
 * command and execute it using exeve
 * @cmd: the 2D array
 * @argv: argv
 * @env: environment variable
 *
 * Return: is void
 */

void execute_cmd(char **cmd, char **argv, char **env, int index)
{
	pid_t id;
	int status;
	char *path = NULL;

	if (cmd[0][0] == '/')
		path = strdup(cmd[0]);
	else
		path = get_path(cmd, env);

	if (path == NULL)
	{
		print_error(argv[0], cmd[0], index);
	}
	id = fork();

	if (id == 0)
	{
		if (execve(path, cmd, env) == -1)
		{
			_strdel(&path);
			freearray(cmd);
		}
	}
	else
	{
		waitpid(id, &status, 0);
		freearray(cmd), cmd = NULL;
		_strdel(&path);
	}
}

// int main(int argc, char **argv, char **env)
// {
// 	char *cmd[] = {"ls", NULL};

// 	execute_cmd(cmd, argv, env);
// }
