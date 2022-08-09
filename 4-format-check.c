#include "main.h"

/**
 * format_specifier - function to check for specifier
 * @count: current position of the string pointed to by format
 * @format: pointer to the string to be printed
 * @args: retrieved arguement
 * @reset: to reset the flag
 * @ptr_is_long: to set the long variable to 1
 * @ptr_is_short: to set variable to short
 * @flags: flag
 * @short_long: length modifier
 * Return: the length of string printed
 */

int format_specifier(int count, const char *format, va_list args, int *reset,
		int *ptr_is_long, int *ptr_is_short, int *short_long, int *flags)
{
	int i, print_count = 0;
	char *testDefault = "sdicuSpxXobprR";

	switch (format[count])
	{
		case 'l':
			{
				*ptr_is_long = 1, *reset = 0;
				*short_long = LONG;
				goto end;
			}
		case 'h':
			{
				*ptr_is_short = 1, *reset = 0;
				*short_long = SHORT;
				goto end;
			}
		case '%':
			{
				print_count += _putchar('%');
				goto end;
			}
		default:
			{
				for (i = 0; testDefault[i]; i++)
				{
					if (format[count] == testDefault[i])
						goto stop;
				}
				print_count += _putchar('%');
				print_count += _putchar(format[count]);
				goto end;
			}
	}
stop:
	print_count += check_specifier(format, count, args, flags, short_long);
end:
	return (print_count);
}

/**
 * check_specifier - checks format specifier
 * @format: pointer to string
 * @count: current position of string
 * @args: arguement retrieved
 * @flags: flag
 * @short_long: length modifier
 * Return: length of string printed
 */

int check_specifier(const char *format, int count, va_list args,
		int *flags, int *short_long)
{
	int func_index;
	char specifierFormat = format[count];

	specifierStruct specifierFunc[] = {
		{"s", print_str},
		{"S", print_str},
		{"d", print_int},
		{"i", print_int},
		{"c", print_char},
		{"u", print_unsigned},
		{"p", print_addr},
		{"x", print_unsigned},
		{"X", print_unsigned},
		{"o", print_oct_bin},
		{"b", print_oct_bin},
		{"R", print_rot13},
		{"r", print_reverse},
		{NULL, NULL}
	};

	for (func_index = 0; specifierFunc[func_index].specifier != NULL;
			func_index++)
	{
		if (specifierFunc[func_index].specifier[0] == specifierFormat)
			return (specifierFunc[func_index].func(format, count,
						args, short_long, flags));
	}
	return (0);
}


/**
 * print_char - prints a string
 * @format: formats in str
 * @count: current index
 * @args: argument list
 * @short_long: length modifier
 * @flag: flags array
 *
 * Return: number of characters printed
 */
int print_char(const char *format, int count, va_list args,
		int *short_long, int *flag)
{
	char ch;
	const char *tmp = format;

	(void) count;
	(void) tmp;
	(void) short_long;
	(void) flag;
	ch = (char)va_arg(args, int);
	return (_putchar(ch));
}
