#include <stdarg.h>
#include "main.h"

/**
 * format_specifier - checks for foemat specifier
 * @format: pointer to the string to check
 * @args: varable arguement to be retrieved from string passed to printf
 * @resetPtr: to reset if long or unsigned
 * @Ptr_is_long: pointer to chage the value of long
 * @flag: array to hold flags for printf
 *
 * Return: the number of string printed
 */

int format_specifier(int count, const char *format, va_list args, int *reset, int *ptr_is_long, int *ptr_is_short, int *flags)
{
	int n, print_count = 0;
	char ch, *s, buffer[1024];

	/*buffer = malloc(1024);*/
	switch (format[count])
	{
		case 'u':
		case 'i':
		case 'd':
			{
				if (*ptr_is_long)
					n = va_arg(args, long);
				/* else if (*ptr_is_short)
					n = va_arg(args, short);*/
				else
					n = va_arg(args, int);
				signedNumberToString(n, DECIMAL, buffer, format, count);
				print_count = print_string(buffer, flags, 1);
				break;
			}
		case 'c':
			{
				ch = va_arg(args, int);
				_putchar(ch);
				print_count++;
				break;
			}
		case 's':
			{
				s = va_arg(args, char *);
				print_count = print_string(s, flags, 0);
				break;
			}
		case 'p':
			{
				_putchar('0');
				_putchar('x');
				n = va_arg(args, int);
				unsignedNumberToString(n, HEX, buffer, format, count);
				print_count = print_string(buffer, flags, 1);
				break;
			}
		case 'x':
			{
				if (*ptr_is_long)
					n = va_arg(args, unsigned long);
				/* else if (*ptr_is_short)
					n = (short int)va_arg(args, int);*/
				else
					n = va_arg(args, unsigned int);
				unsignedNumberToString(n, HEX, buffer, format, count);
				print_count = print_string(buffer, flags, 1);
				break;
			}
		case 'X':
			{
				if (*ptr_is_long)
					n = va_arg(args, unsigned long);
				/*else if (*ptr_is_short)
					n = va_arg(args, short);*/
				else
					n = va_arg(args, unsigned int);
				unsignedNumberToString(n, HEX, buffer, format, count);
				print_count = print_string(buffer, flags, 1);
				break;
			}
		case 'o':
			{
				if (*ptr_is_long)
					n = va_arg(args, unsigned long);
				/*else if (*ptr_is_short)
					n = va_arg(args, short);*/
				else
					n = va_arg(args, unsigned int);
				unsignedNumberToString(n, OCTAL, buffer, format, count);
				print_count = print_string(buffer, flags, 1);
				break;
			}
		case 'b':
			{
				if (*ptr_is_long)
					n = va_arg(args, long);
				else
					n = va_arg(args, int);
				unsignedNumberToString(n, BINARY, buffer, format, count);
				print_count = print_string(buffer, flags, 1);
				break;
			}
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
		case 'R':
			{
				s = va_arg(args, char *);
				s = rot13(s);
				print_count = print_string(buffer, flags, 0);
				break;
			}
		case 'r':
			{
				s = va_arg(args, char *);
				s = reversed(s);
				print_count = print_string(buffer, flags, 0);
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
				_putchar('%');
				ch = va_arg(args, int);
				_putchar(ch);
				print_count += 2;
				break;
			}
	}
	/*free(buffer);*/
	return (print_count);
}
