#include <stdarg.h>
#include <stdint.h>
#include "main.h"

/**
 * print_unsigned - prints a usigned number
 * @format: formats in str
 * @count: current index
 * @args: argument list
 * @flag: flags array
 * @short_long: length modifier
 *
 * Return: number of characters printed
 */
int print_unsigned(const char *format, int count,
		va_list args, int *short_long, int *flag)
{
	uint64_t n;
	char buffer[1024];
	int base;

	base = (format[count] == 'u') ? DECIMAL : HEX;
	if (*short_long == LONG)
		n = va_arg(args, unsigned long int);
	else
		n = va_arg(args, unsigned int);
	if (*short_long == SHORT)
		n = (unsigned short) n;
	unsignedNumberToString(n, base, buffer, format[count], flag);
	return (print_string(buffer, flag, 1));


}

/**
 * print_addr - prints an address
 * @format: formats in str
 * @count: current index
 * @args: argument list
 * @flag: flags array
 * @short_long: length modifier
 *
 * Return: number of characters printed
 */
int print_addr(const char *format, int count, va_list args,
		int *short_long, int *flag)
{
	void *n;
	char buffer[1024];
	int print_count = 0;
	(void) short_long;

	n = va_arg(args, void *);
	if (n == NULL)
		return (print_string("(nil)", flag, 1));
	print_count += _putchar('0');
	print_count += _putchar('x');
	unsignedNumberToString((uint64_t)n, HEX, buffer, format[count], flag);
	print_count += print_string(buffer, flag, 1);
	return (print_count);
}

/**
 * print_oct_bin - prints octal and binary
 * @format: formats in str
 * @count: current index
 * @args: argument list
 * @flag: flags array
 * @short_long: length modifier
 *
 * Return: number of characters printed
 */
int print_oct_bin(const char *format, int count, va_list args,
		int *short_long, int *flag)
{
	uint64_t n;
	char buffer[1024];
	int base;

	base = (format[count] == 'b') ? BINARY : OCTAL;
	if (*short_long == LONG)
		n = va_arg(args, unsigned long int);
	else
		n = va_arg(args, unsigned int);
	if (*short_long == SHORT)
		n = (unsigned short) n;
	unsignedNumberToString(n, base, buffer, format[count], flag);
	return (print_string(buffer, flag, 1));

}

/**
 * print_rot13 - prints a string in rot13
 * @format: formats in str
 * @count: current index
 * @args: argument list
 * @flag: flags array
 * @short_long: length modifier
 *
 * Return: number of characters printed
 */
int print_rot13(const char *format, int count, va_list args,
		int *short_long, int *flag)
{
	const char *tmp = format;
	char *s;
	int retval;
	(void) short_long;
	(void) tmp;

	count = 0;
	s = va_arg(args, char *);
	s = rot13(s);
	retval = print_string(s, flag, count);
	free(s);
	return (retval);
}

/**
 * print_reverse - prints a string in reverse
 * @format: formats in str
 * @count: current index
 * @args: argument list
 * @flag: flags array
 * @short_long: length modifier
 *
 * Return: number of characters printed
 */
int print_reverse(const char *format, int count, va_list args,
		int *short_long, int *flag)
{
	char *s;
	const char *tmp = format;
	int retval;
	(void) short_long;

	(void) tmp;
	count = 0;
	s = va_arg(args, char *);
	s = reversed(s);
	retval = print_string(s, flag, count);
	free(s);
	return (retval);
}
