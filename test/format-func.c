#include <stdarg.h>
#include <stdint.h>
#include "main.h"

int print_str(const char *format, int count, va_list args, int *flag)
{
	char *s;
	const char *tmp = format;

	count = 0;
	(void) tmp;
	s = va_arg(args, char *);
	return (print_string(s, flag, count));
}

int print_int(const char *format, int count, va_list args, int *flag)
{
	int n;
	char buffer[1024];

	n = va_arg(args, long);
	signedNumberToString(n, DECIMAL, buffer, format, count);

	return (print_string(buffer, flag, 1));

}

int print_unsigned(const char *format, int count, va_list args, int *flag)
{
	uint64_t n;
	char buffer[1024];
	int base;

	base = (format[count] == 'u') ? DECIMAL : HEX;
	n = va_arg(args, uint64_t);
	unsignedNumberToString(n, base, buffer, format, count);
	return (print_string(buffer, flag, 1));


}

int print_addr(const char *format, int count, va_list args, int *flag)
{
	void *n;
	char buffer[1024];

	_putchar('0');
	_putchar('x');
	n = va_arg(args, void *);
	unsignedNumberToString((int64_t)n, HEX, buffer, format, count);
	return (print_string(buffer, flag, 1));
}

int print_oct_bin(const char *format, int count, va_list args, int *flag)
{
	uint64_t n;
	char buffer[1024];
	int base;

	base = (format[count] == 'b') ? BINARY : OCTAL;
	n = va_arg(args, uint64_t);
	unsignedNumberToString(n, base, buffer, format, count);
	return (print_string(buffer, flag, 1));

}

int print_rot13(const char *format, int count, va_list args, int *flag)
{
	char *s;
	const char *tmp = format;
	
	(void) tmp;
	count = 0;
	s = va_arg(args, char *);
	s = rot13(s);
	return (print_string(s, flag, count));
}

int print_reverse(const char *format, int count, va_list args, int *flag)
{
	char *s;
	const char *tmp = format;

	(void) tmp;
	count = 0;
	s = va_arg(args, char *);
	s = reversed(s);
	return (print_string(s, flag, count));
}
