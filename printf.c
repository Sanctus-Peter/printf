#include "main.h"
#include <stdarg.h>
#include <stdint.h>

int _vprintf(const char *, va_list);

/**
 * _printf - function to print output to the console
 * @format: pointer to the list of arguemant passed to the function
 *
 * Return: bytes of element printed out, -1 on error
 */

int _printf(const char *format, ...)
{
	int returnValue;
	va_list args;

	va_start(args, format);
	returnValue = _vprintf(format, args);
	va_end(args);

	return (returnValue);
}

/**
 * _vprintf - helper function for printf, takes the arguement passed to printf,
 *				and does the actual printing
 * @format: pointer to the list of arguement passed to printf to be printd
 * @args: place holder for the arguement passed of type va_list
 *
 * Return: bytes of element printed, -1 if no parameter is supplied
 */

int _vprintf(const char *format, va_list args)
{
	/* to keep track of format specifier */
	int state = 0;
	int print_count = 0, reset_flag, identifier_printed;

	while (*format)
	{
		if (state == 0)
		{
			if (*format == '%')
				state = 1;
			else
			{
				print_count++;
				_putchar(*format);
			}
		}
		else
		{
			identifier_printed = format_specififer(format, args);
			
		}
	}
}
