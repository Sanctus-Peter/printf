#include "main.h"
#include <stdint.h>
#include <stdarg.h>

/**
 * unsignedNumberToString - convert an unsigned number to string
 * @number: number to be converted
 * @base: base of the number
 * @buf: pointer to a buffer to hold the convert number for printing
 * @fmt: format chracter
 * @flags: pointer to flags array
 */

void unsignedNumberToString(uint64_t number, int base, char *buf,
		char fmt, int *flags)
{
	char tmp[1024];
	int rem, i = 0, j = 0;

	if (flags[3])
	{
		if (base == OCTAL || base == HEX)
		{
			*buf++ = '0';
			if (base == 16)
				*buf++ = fmt;
		}
	}
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
			tmp[i++] = (fmt == 'X') ? 'A' + (rem - 10) : 'a' + (rem - 10);
		else
			tmp[i++] = '0' + rem;

		number /= base;
	}

	for (j = i - 1; j >= 0; j--)
		*buf++ = tmp[j];
	*buf = '\0';
}

/**
 * signedNumberToString - convert any number to string signed or unsigned
 * @number: number to be converted
 * @base: base of number
 * @buf: pointer to buffer to hold the converted number for printing
 * @fmt: format chracter
 * @flags: pointer to flags array
 */

void signedNumberToString(int64_t number, int base, char *buf,
		char fmt, int *flags)
{
	if (number < 0)
	{
		*buf++ = '-';
		number = -number;
	}
	else if (flags[1])
	{
		*buf++ = flags[1];
	}

	unsignedNumberToString(number, base, buf, fmt, flags);
}

/**
 * getDigitsValue - gets the value of digits
 * @fmt: pointer to string
 * @res: start index
 *
 * Return: value
 */
int getDigitsValue(const char *fmt, int *res, int index)
{
	int i = index;
	
	while (isDigit(fmt[i]))
	{
		*res *= 10;
		*res += fmt[i++] - '0';
	}
	return (i - index);
}
