#include"main.h"

/**
 * upper_str - replace non printing chars in s
 * @s: pointer to string
 *
 * Return: pointer to s
 */
char *upper_str(char *s)
{
	int x = 0, i = 0, a[6] = {0, 0, 0, 0, 0, 0};
	char *tmp, buff[3];

	if (!s)
		return (0);
	/* get the length of new string */
	tmp = malloc((upper_strlen(s) + 1) * sizeof(char));
	if (!tmp)
		return (0);
	/* form the new string */
	while (s[i])
	{
		if (isPrintable(s[i]))
		{
			tmp[x++] = s[i++];
		}
		else
		{
			tmp[x++] = '\\';
			tmp[x++] = 'x';
			unsignedNumberToString(s[i], 16, buff, 'X', a);
			if (buff[1] == '\0')
			{
				tmp[x++] = '0';
				tmp[x++] = buff[0];
			}
			else
			{
				tmp[x++] = buff[0];
				tmp[x++] = buff[1];
			}
			i++;
		}
	}
	tmp[x] = '\0';
	return (tmp);
}

/**
 * isPrintable - checks if a char is printable
 * @c: character to check
 *
 * Return: 1 true 0 false
 */
int isPrintable(char c)
{
	if ((c > 0 && c < 32) || c >= 127)
		return (0);
	return (1);
}

/**
 * upper_strlen - get length for special str
 * @s: original string
 *
 * Return: length
 */
int upper_strlen(char *s)
{
	int i = 0, x = 0;

	while (s[i])
	{
		if (isPrintable(s[i]))
			x++;
		else
			x += 4;
		i++;
	}
	return (x);
}
