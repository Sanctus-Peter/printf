#include <limits.h>
#include <stdio.h>
#include "main.h"
#include <stdint.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;
    char buff[30];
    char *my = "+12345";
    int f[5] = {0,0,1,0,15};
	char *ptr = "hello";
	int (*ptr_func)(char *) = upper_strlen;

	printf("testing pointers: %p, %p \n", ptr, ptr_func);
	_printf("testing pointers: %p, %p \n", ptr, ptr_func);
	_printf("Characters: %c %c done.\n", 'a', 65);
	_printf("Decimals: %d %ld done\n", 1977, 650000L);
	_printf("Some different radicals: %d %x %X done.\n", 100, 100, 100);
	_printf("%s \n", "Alx is Amaizing");
	_printf("testing other possible integer: %d %d\n", INT_MAX, INT_MIN);
    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n\n", "mahadi");
    _printf("Unknown:[%R]\n\n", "mahadi");

    print_string(my, f, 1);
signedNumberToString(234,16,buff, "X", 0);
    _printf("\nTesting: %s\n", buff);
    return (0);
}
