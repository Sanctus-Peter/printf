#include "main.h"
#include <stdarg.h>
#include <stdint.h>


/**
 * _printf - function to print output to the console
 * @format: pointer to the list of arguemant passed to the function
 *
 * Return: bytes of element printed out, -1 on error
 */

int _printf(const char *format, ...)
{
	int returnValue, val;
	va_list args;

	va_start(args, format);
	val = _vprintf(format, args);
	va_end(args);

	(returnValue) = val;
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
	int state = 0, tmp_count, flag[5], is_long = 0, is_short = 0, reset = 1;
	int count = 0, print_count = 0, identifier_printed;
	int *resetPtr = &reset, *ptr = &is_long, *shortPtr = &is_short;
	/*va_list args;*/

	/*va_copy(args, g_ar);*/
	while (format[count])
	{
		if (state == 0)
		{
			if (format[count] == '%')
				state = 1;
			else
			{
				_putchar(format[count]);
				print_count++;
			}
			count++;
		}
		else
		{
			if (isAlpha(format[count]))
			{
				identifier_printed = format_specifier(count, format, args, resetPtr, ptr, shortPtr,  flag);
				
				if(reset == 1)
				{
					state = 0;
					is_long = 0;
					is_short = 0;
				}
				else
					reset = 1;
				count++;
			}
			else
			{

				flag[0] = flag[1] = flag[2] = flag[3] = flag[4] = 0;
				tmp_count = setFlags(format, flag, count, args);
				count += tmp_count;	
			}
			print_count += identifier_printed;
		}
		/* count++; */
	}
	va_end(args);
	return (print_count);
}
