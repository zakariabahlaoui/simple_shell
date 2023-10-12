#include "shell.h"

/**
 * read_line - get the line after prompet and assignet in string
 *
 * Return: the line
 */

char *read_line(void)
{
	char *line = NULL;
	size_t length = 0;
	size_t i;

	i = getline(&line, &length, stdin);

	if (i == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
