#include "shell.h"

/**
 * ft_substr -  returns str from the string value starting at
 * the character position specified by start.
 * @s: the string
 * @start: the character to start
 * @len: lenght  to str return
 *
 * Return: return str
 */

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	size_t j;
	char *str;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
/**
 * ft_count_word - that funcotin count the word in stiring and tak
 * all the word inside double quote or single quote like a one world
 * @s: string
 * @c: character
 * Return: return  nunber the word i the string
 */
static int ft_count_word(char const *s, char c)
{
	int i;
	int word;
	int quote = 0;

	i = 0;
	word = 0;
	while (s && s[i])
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			quote = !quote;
		}
		if (s[i] != c || quote)
		{
			word++;
			while ((s[i] != c || quote) && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}
/**
 * ft_size_word - that function count the character in one word
 * @s: the string
 * @c: the charchter to split
 * @i: the number to start
 *
 * Return: return the size
 */
static int ft_size_word(char const *s, char c, int i)
{
	int size;
	int quote = 0;

	size = 0;
	while ((s[i] != c || quote) && s[i])
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			quote = !quote;
		}
		size++;
		i++;
	}
	return (size);
}
/**
 * ft_free - free arayy 2D
 * @strs: the array
 * @j: integer
 *
 * Return: is void
 */

static void ft_free(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
}
/**
 * ft_split - split string to a words by the character that give it
 * @s: the string
 * @c: the character for split
 *
 * Return: array 2D
 */
char **ft_split(char const *s, char c)
{
	int i;
	int word;
	char **strs;
	int size;
	int j;

	i = 0;
	j = -1;
	word = ft_count_word(s, c);
	strs = (char **)malloc((word + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	while (++j < word)
	{
		while (s[i] == c)
			i++;
		size = ft_size_word(s, c, i);
		strs[j] = ft_substr(s, i, size);
		if (!strs[j])
		{
			ft_free(strs, j);
			return (NULL);
		}
		i += size;
	}
	strs[j] = 0;
	return (strs);
}
