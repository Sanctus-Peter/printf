#include "main.h"

/**
 * print_str - prints a string
 * @format: formats in str
 * @count: current index
 * @args: argument list
 * @flag: flags array
 *
 * Return: number of characters printed
 */
int print_str(const char *format, int count, va_list args, int *flag)
{
	char *s;
	int retval;

	s = va_arg(args, char *);
	if (s == NULL)
		return (print_string("(null)", flag, count));
	if (format[count] == 's')
		return (print_string(s, flag, 0));
	s = upper_str(s);
	retval = print_string(s, flag, 0);
	free(s);
	return (retval);
}

/**
 * print_int - prints a string
 * @format: formats in str
 * @count: current index
 * @args: argument list
 * @flag: flags array
 *
 * Return: number of characters printed
 */
int print_int(const char *format, int count, va_list args, int *flag)
{
	long n;
	char buffer[1024];

	n = va_arg(args, int);
	signedNumberToString(n, DECIMAL, buffer, format[count], flag);
	return (print_string(buffer, flag, 1));

}
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
 * flags[5]: is set if (precision) is found
 *
 * @flags: pointer to flags array
 * @fmt: pointer to format strings
 * @j: current index on fmt
 * @args: pointer to arguments list
 *
 * Return: number of chars checked
 */
int setFlags(const char *fmt, int *flags, int j, va_list args)
{
	int i = j;

	flags[0] = flags[1] = flags[2] =
		flags[3] = flags[4] = flags[5] = 0;
	while ((!isDigit(fmt[i]) && !isAlpha(fmt[i]) && fmt[i] != '.') || fmt[i] == '0')
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
			flags[4] = va_arg(args, int);
			break;
		default:
			break;
		}
		i++;
	}
	if (isDigit(fmt[i]))
		flags[4] = 0;
	i += getDigitsValue(fmt, &flags[4], i);
	if (fmt[i] == '.')
	{
		i++;
		i += getDigitsValue(fmt, &flags[5], i);
	}
	return (i - j);
}
