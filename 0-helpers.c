#include "main.h"

/**
 * isAlpha - check if a char is alphabet
 * @c: chracter to check
 *
 * Return: 0 if false 1 for true
 */
int isAlpha(char c)
{
	return ((c <= 'z' && c >= 'a') ||
			(c <= 'Z' && c >= 'A'));
}

/**
 * isDigit - check if a number is digit
 * @c: character to check
 *
 * Return: 1 for true 0 for false
 */
int isDigit(char c)
{
	if (c < 48 || c > 58)
		return (0);
	return (1);
}

/**
 * setFlags - sets flags to represent the flg
 * Description: flags is an array of length 5
 * flags[0]: is set if (-) is found
 * flags[1]: is set if (+/spc) is found
 * flags[2]: is set if (0) is found
 * flags[3]: is set if (#) is found
 * flags[4]: is set if (digits) is found
 *
 * @flags: pointer to flags array
 * @fmt: pointer to format strings
 * @j: current index on fmt
 * @args: pointer to arguments list
 *
 * Return: number of chars checked
 */
int setFlags(const char *fmt, int *flags, int j, va_list *args)
{
	int i = j;

	while ((!isDigit(fmt[i]) && !isAlpha(fmt[i])) || fmt[i] == '0')
	{
		switch (fmt[i])
		{
		case '-':
			flags[0] = 1;
			break;
		case ' ':
		case '+':
			flags[1] = fmt[i];
			break;
		case '0':
			flags[2] = 1;
			break;
		case '#':
			flags[3] = 1;
			break;
		case '*':
			flags[4] = va_arg(*args, int);
			break;
		default:
			break;
		}
		i++;
	}
	if (isDigit(fmt[i]))
		flags[4] = 0;
	while (isDigit(fmt[i]))
	{
		fmt[4] *= 10;
		fmt[4] += fmt[i++] - '0';
	}
	return (i - j);
}
