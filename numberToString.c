#include "main.h"
#include <stdint.h>
#include <stdarg.h>

/**
 * unsignedNumberToString - convert an unsigned number to string
 * @number: number to be converted
 * @base: base of the number
 * @buf: pointer to a buffer to hold the convert number for printing
 * @format: pointer to the format specifier
 */

void unsignedNumberToString(uint64_t number, int base, char *buf, const char *format, int count)
{
	char tmp[1024];
	int rem, i = 0, j = 0;

	if (number == 0)
	{
		*buf++ = '0';
		*buf = '\0';
		return;
	}

	while (number)
	{
		rem = number % base;
		if (rem >= 10)
			tmp[i++] = (format[count] == 'X') ? 'A' + (rem - 10) : 'a' + (rem - 10);
		else
			tmp[i++] = '0' + rem;

		number /= base;
	}

	for (j = 0, i--; i >= 0; i--, j++)
		buf[j] = tmp[i];
	buf[j] = '\0';
}

/**
 * signedNumberToString - convert any number to string signed or unsigned
 * @number: number to be converted
 * @base: base of number
 * @buf: pointer to buffer to hold the converted number for printing
 * @format: pointer to the format specifier
 */

void signedNumberToString(int64_t number, int base, char *buf, const char *format, int count)
{
	if (number < 0)
	{
		buf[0] = '-';
		number *= -1;
	}

	unsignedNumberToString(number, base, buf, format, count);
}
