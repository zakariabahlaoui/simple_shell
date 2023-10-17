#include "shell.h"

/**
 * _tokenizer - this function take a string an split it and tokenaz
 *  it and assign it in array 2D
 * @str: the string
 *
 * Return: array 2D
 */

char **_tokenizer(char *str)
{
	char *token_str = NULL, *tmp = NULL, *s = NULL;
	char **cmd = NULL;
	int count = 0, i = 0;

	if (!str)
		return (NULL);

	tmp = strdup(str);
	s = strdup(str);
	token_str = strtok(tmp, " \t\n");
	if (token_str == NULL)
	{
		free(str), str = NULL;
		free(tmp), tmp = NULL;
		free(s), s = NULL;
		return (NULL);
	}
	while (token_str)
	{
		count++;
		token_str = strtok(NULL, " \t\n");
	}
	free(tmp), tmp = NULL;
	cmd = malloc(sizeof(char *) * (count + 1));
	if (!cmd)
	{
		free(str), str = NULL;
		return (NULL);
	}
	token_str = strtok(s, " \t\n");
	while (token_str)
	{
		cmd[i] = strdup(token_str);
		token_str = strtok(NULL, " \t\n");
		i++;
	}
	free(str), free(s);
	str = NULL, s = NULL;
	cmd[i] = NULL;
	return (cmd);
}
