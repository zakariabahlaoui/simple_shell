#include "shell.h"

/**
 * _length - return length the integer that take
 * @n: thr integer
 *
 * Return: return lenght int
 */

static int _length(int n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
/**
 * _calcul -  converts a long integer n into a character array
 * @n: the long integer
 * @len: length
 *
 * Return: return array
 */
char *_calcul(long int n, int len)
{
	int i;
	int r;
	char *buff;

	if (n < 0)
		n = n * (-1);

	buff = (char *)malloc(len + 1);
	i = 0;
	while (i < len)
	{
		r = n % 10;
		n = n / 10;
		buff[i] = r + '0';
		i++;
	}
	buff[i] = 0;
	return (buff);
}

/**
 * _itoa - convert integer to ascci
 * @n: the int
 *
 * Return: return string
 */
char *_itoa(int n)
{
	char *str;
	char *buff;
	int j;
	int length;

	if (n == 0)
		return (strdup("0"));
	length = _length(n);
	str = (char *)malloc(length + 1);
	buff = _calcul(n, length);

	j = 0;
	if (n < 0)
	{
		str = (char *)malloc(length + 2);
		str[j] = '-';
		j++;
	}
	length--;
	while (length >= 0)
	{
		str[j] = buff[length];
		length--;
		j++;
	}
	str[j] = 0;
	_strdel(&buff);
	return (str);
}

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
	int i, d, n, len, f, digit;

	i = 0;
	d = 0;
	n = 0;
	len = 0;
	f = 0;
	digit = 0;

	while (s[len] != '\0')
		len++;

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++d;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}

	if (f == 0)
		return (0);

	return (n);
}
