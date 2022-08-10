#include "main.h"
#include <unistd.h>

/**
 * _putchar - prints a character to stdout
 * @c: the character to be printed
 *
 * Return: 1 if success, else -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
