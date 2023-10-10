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
