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
    int len = 0, len3;
    int len2 = 50, len4 = 50;
    unsigned int ui;
    void *addr;
	char *ptr = "hello";
	int (*ptr_func)(char *) = upper_strlen;

	_printf("%b, %b, %b\n", 98, INT_MAX, 1001101);
	/* printf("testing pointers: %p, %p, %p \n", ptr, ptr_func, NULL); */
	_printf("testing pointers: %p, %p, %p\n", ptr, ptr_func, NULL);
	len = _printf("Characters: %c %c, %cdone.\n", 'a', NULL, 78);
/* 	len2 = printf("Characters: %c %c, %cdone.\n", 'a', NULL, 78); */
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Decimals: %d %ld done\n", 1977, 650000L);
	_printf("Some different radicals: %d %x %X done.\n", 100, 100, 100);
	_printf("%s \n", "Alx is Amaizing");
	_printf("testing other possible integer: %d %d\n", INT_MAX, INT_MIN);
    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
/*    len4 = printf(NULL); */
	len3 = _printf(NULL);
	ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i, %d]\n", len, len, len3);
    printf("Length:[%d, %i, %d]\n", len2, len2, len4);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("String:[%s, %s]\n", "I am a string !", NULL);
    /* printf("String:[%s, %s]\n", "I am a string !", NULL); */
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n", "mahadi");
    _printf("Unknown:[%R]\n", "mahadi");

    _printf("\nTesting: [%S]\n", "Best\nSchool");
    printf("Hash: [%#x, %#X, %#o]\n", 255, 255, 255);
    _printf("Hash: [%#x, %#X, %#o]\n", 255, 255, 255);

    printf("space and +: [% 05d, %+i, %+10d]\n", 255, 255, 255);
    _printf("space and +: [% 05d, %+i, %+10d]\n", 255, 255, 255);
    return (0);
}
