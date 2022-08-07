#include "main.h"

int format_specifier(int count, const char *format, va_list args, int *reset,
		int *ptr_is_long, int *ptr_is_short, int *flags)
{
	int i, print_count = 0;
	char ch, *testDefault = "sdiupxXobprR";

	switch (format[count])
	{
		case 'l':
			{
				*ptr_is_long = 1;
				*reset = 0;
				break;
			}
		case 'h':
			{
				*ptr_is_short = 1;
				*reset = 0;
				break;
			}
		case 'c':
			{
				ch = va_arg(args, int);
				_putchar(ch);
				print_count++;
				break;
			}
		case '%':
			{
				_putchar('%');
				print_count++;
				break;
			}
		default:
			{
				for (i = 0; testDefault[i]; i++)
				{
					if (format[count] == testDefault[i])
						goto stop;
				}
				_putchar('%');
				ch = va_arg(args, int);
				_putchar(ch);
				print_count += 2;
				break;
			}
	}
stop:
	print_count = check_specifier(format, count, args, flags);

	return (print_count);
}

int check_specifier(const char *format, int count, va_list args, int *flags)
{
	int func_index;
	char specifierFormat = format[count];

	specifierStruct specifierFunc[] = {
		{"s", print_str},
		{"d", print_int},
		{"i", print_int},
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

	for (func_index = 0; specifierFunc[func_index].specifier != NULL; func_index++)
	{
		if (specifierFunc[func_index].specifier[0] == specifierFormat)
			return (specifierFunc[func_index].func(format, count, args, flags));
	}
	return (0);
}
