#include "main.h"
#include <unistd.h>

/**
 * _putchar - print a character
 * @c: character to print
 * Return: 0
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - print a string with flags
 * @str: pointer to str
 * @flags: pointer to flags array
 * @n: indicate if str is number
 *
 * Return: number of chars printed
 */
int print_string(char *str, int *flags, int n)
{
	int i = 0, j = 0, count;
	char pad;

	if (!str)
		return (0);
	while (str[i])
		i++;
	i = flags[5] ? i + flags[5] + 1 : i;
	count = flags[4] > i ? flags[4] : i;
	pad = flags[2] ? '0' : ' ';
	if (count > i && n && flags[2] &&
			(str[0] == '+' || str[0] == '-' || str[0] == ' '))
	{
		_putchar(str[0]);
		j++;
	}

	while (flags[4] > i && !flags[0])
	{
		_putchar(pad);
		flags[4]--;
	}

	while (str[j])
		_putchar(str[j++]);

	if (flags[5] && n)
		_putchar('.');
	while (flags[5] && n)
	{
		_putchar('0');
		flags[5]--,	flags[4]--;
	}

	while (flags[4] > i && flags[0])
	{
		_putchar(' ');
		flags[4]--;
	}
	return (count);
}

/**
 * rot13 - encode a string using ROT-13
 * @s: pointer to the  string
 * Return: pointer to the string
 */

char *rot13(char *s)
{
	int x = 0, index;
	char *chars = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
	char *res;

	if (!s)
		return (0);
	while (s[x])
		x++;
	res = malloc((x + 1) * sizeof(char));
	if (!res)
		return (0);
	x = 0;
	while (s[x])
	{
		index = get_index(chars, s[x]);
		if (index > -1)
		{
			/* rotate */
			index = (index + 26) % 52;
			res[x] = chars[index];
		}
		else
		{
			res[x] = s[x];
		}
		x++;
	}
	return (res);
}

/**
 * get_index - finds an index of a char
 * @c: key
 * @s: haystack
 * Return: index of c or -1
 */
int get_index(char *s, char c)
{
	int i = 0;

	while (s[i])
		if (s[i++] == c)
			return (i - 1);
	return (-1);
}

/**
 * reversed - reverses a string
 * @s: pointer to string
 *
 * Return: pointer to s
 */
char *reversed(char *s)
{
	int x = 0, i = 0;
	char *tmp;

	if (!s)
		return (0);
	/* get the length os s */
	while (s[x])
		x++;
	tmp = malloc((x + 1) * sizeof(char));
	if (!tmp)
		return (0);
	x--;
	/* reverse the string */
	while (x >= 0)
		tmp[i++] = s[x--];
	tmp[i] = '\0';
	return (tmp);
}
