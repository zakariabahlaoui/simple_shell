#include "shell.h"

/**
 * _strcpy -  copies the string pointed to by src
 * @src: the string want to copy
 * @dest: the copy string
 *
 * Return: return a aray string
 *
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2
 */

int _strcmp(char *s1, char *s2)
{
	int i;
	int j;

	j = 0;
	while (s2[j] != 0)
	{
		j++;
	}
	i = 0;
	while (s1[i] != 0)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);

		i++;
	}
	if (j > i)
		return (s1[i] - s2[i]);

	return (0);
}

/**
 * _strlen -  returns the length of a string.
 * @s: the string
 *
 * Return: return int
 *
 */

int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;

	return (i);
}

/**
 * _strcat - concatenates two strings
 * @dest: the first string
 * @src: ehe second to concatenate
 *
 * Return: Always 0.
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	j = 0;

	while (dest[i] != '\0')
		i++;

	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';

	return (dest);
}
