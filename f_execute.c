#include "shell.h"

char *ft_strchr(const char *s, int c)
{
	char *v;
	int i;

	i = 0;
	v = (char *)s;

	while (v[i])
	{
		if (v[i] == (char)c)
			return &v[i];
		i++;
	}

	if (c == 0)
		return &v[i];
	return NULL;
}

char *get_path(char **cmd, char **env)
{
	char *all_path, *path, *tmp;
	char **split_path;
	struct stat st;
	int i = 0;

	all_path = ft_getenv("PATH", env);

	split_path = ft_split(all_path, ':');

	while (split_path[i])
	{
		tmp = ft_strjoin(split_path[i], "/");
		path = ft_strjoin(tmp, cmd[0]);
		if (stat(path, &st) == 0)
			break;
		free(tmp), tmp = NULL;
		i++;
	}
	freearray(split_path);
	free(all_path);

	return (path);
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

void execute_cmd(char **cmd, char **argv, char **env)
{
	pid_t id;
	int status;
	char *path;

	if (ft_strchr(cmd[0], '/'))
	{
		path = strdup(cmd[0]);
	}
	else
	{
		path = get_path(cmd, env);
	}

	id = fork();

	if (id == 0)
	{
		if (execve(path, cmd, env) == -1)
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
		free(path);
		path = NULL;
	}
}

// int main(int argc, char **argv, char **env)
// {
// 	char *cmd[] = {"ls", NULL};

// 	execute_cmd(cmd, argv, env);
// }