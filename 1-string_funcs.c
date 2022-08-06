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

	while (str[i])
		i++;
	count = flags[4] > i ? flags[4] : i;
	pad = flags[2] ? '0' : ' ';
	if (count > i && (str[0] == '+' || str[0] == '-' || str[0] == ' ') && n)
	{
		_putchar(src[0]);
		j++;
		flags[4]--;
	}

	/* pad right allignment */
	while (flags[4] > i && !flags[0])
	{
		_putchar(pad);
		flags[4]--;
	}
	/* print string */
	while (str[j])
		_putchar(str[j++]);
	/* pad left alligmment */
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

	while (s[x])
	{
		index = get_index(chars, s[x]);
		if (index > -1)
		{
			/* rotate */
			index = (index + 26) % 52;
			s[x] = chars[index];
		}
		x++;
	}
	return (s);
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
