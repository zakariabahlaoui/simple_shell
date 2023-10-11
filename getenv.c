#include "shell.h"

/**
 * ft_getenv - find the name variable and get the value
 * @name: the name of variable
 * @env: the env
 *
 * Return: the value
 */

char *ft_getenv(char *name, char **env)
{
	char **key;
	char *value;
	int i;

	i = 0;
	while (env[i])
	{
		key = ft_split(env[i], '=');
		if (_strcmp(key[0], name) == 0)
		{
			value = key[1];
		}
		freearray(key);
		i++;
	}

	return (value);
}
