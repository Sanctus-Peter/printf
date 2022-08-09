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
    int len = 0, len3, len1;
    int len2 = 50, len4 = 50;
    unsigned int ui;
    void *addr;
	char *ptr = "hello";
	int (*ptr_func)(char *) = upper_strlen;
	unsigned int a;
	char *s;
	char *s2;
	char *s3;
	char *s4;
	char c;
	int i;
	int b;

	a = -17;
	c = 'p';

	i = -123455;

	s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit\n";

	s2 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n";

	s3 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n";

	s4 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n";

	b = 98;

	_printf("asdfasdfas\n");
	printf("asdfasdfas\n");
	_printf("--------------\n\n\n");
	_printf("fasdf\n %s\n %c\n %s\n %s\n %s\n %i\n %b\n\n\n", s, c, s2, s3, s4, i, b);
	printf("fasdf\n %s\n %c\n %s\n %s\n %s\n %i\n\n\n", s, c, s2, s3, s4, i);
	_printf("--------------\n\n");
	_printf("%b\n", 98);
	_printf("--------------\n\n\n");

	len = printf("%u\n", a);
	len1 = _printf("%u\n", a);
	printf("%i\n", len);
	_printf("%i\n", len1);
	_printf("%b, %b, %b\n", 98, INT_MAX, 1001101);
	printf("testing pointers: %p, %p, %p \n", ptr, ptr_func, NULL);
	_printf("testing pointers: %p, %p, %p\n", ptr, ptr_func, NULL);
	len = _printf("Characters: %c %c, %cdone.\n", 'a', NULL, 78);
 	len2 = printf("Characters: %c %c, %cdone.\n", 'a', NULL, 78);
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Decimals: %d %ld done\n", 1977, 650000L);
	_printf("Some different radicals: %d %x %X done.\n", 100, 100, 100);
	printf("Some different radicals: %d %x %X done.\n", 100, 100, 100);
	_printf("Some different radicals: %x %x %X done.\n", (unsigned int)INT_MAX + 1024, INT_MIN, INT_MAX);
	printf("Some different radicals: %x %x %X done.\n", (unsigned int)INT_MAX + 1024, INT_MIN, INT_MAX);
	_printf("Some different radicals: %o %o %o done.\n", (unsigned int)INT_MAX + 1024, INT_MIN, INT_MAX);
	printf("Some different radicals: %o %o %o done.\n", (unsigned int)INT_MAX + 1024, INT_MIN, INT_MAX);
	_printf("Some different radicals: %u %u %u done.\n", (unsigned int)INT_MAX + 1024, INT_MIN, INT_MAX);
	printf("Some different radicals: %u %u %u done.\n", (unsigned int)INT_MAX + 1024, INT_MIN, INT_MAX);
	_printf("%s \n", "Alx is Amaizing");
	_printf("testing other possible integer: %d %d\n", INT_MAX, INT_MIN);
    printf("testing other possible integer: %d %d\n", INT_MAX, INT_MIN);
	len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    len4 = printf(NULL);
	len3 = _printf(NULL);
	printf("%d\n", len4);
	_printf("%d\n", len3);
	ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i, %d]\n", len, len, len3);
    printf("Length:[%d, %i, %d]\n", len2, len2, len4);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u, %u]\n", ui, INT_MIN);
    printf("Unsigned:[%u, %u]\n", ui, INT_MIN);
    len = _printf("Unsigned octal:[%o, %o]\n", ui, NULL);
    len1 = printf("Unsigned octal:[%o, %o]\n", ui, NULL);
    len2 = _printf("Unsigned hexadecimal:[%x, %x, %X]\n", ui, NULL, ui);
    len3 =  printf("Unsigned hexadecimal:[%x, %x, %X]\n", ui, NULL, ui);
    _printf("Length:[%d, %i]\n", len, len2);
	printf("Length:[%d, %i]\n", len1, len3);
	len = _printf("String:[%s, %s]\n", "I am a string !", NULL);
    len1 = printf("String:[%s, %s]\n", "I am a string !", NULL);
	printf("%d\n", len1);
	_printf("%d\n", len);
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%c%%%c%%]\n", 'g', 'r');
    len2 = printf("Percent:[%c%%%c%%]\n", 'g', 'r');
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n", "mahadi");
    _printf("Unknown:[%R]\n", "mahadi");

    _printf("\nTesting: [%S]\n", "Best\nSchool");
    printf("Hash: [%#x, %#X, %#o]\n", 969255, 969255, 969255);
    _printf("Hash: [%#x, %#X, %#o]\n", 969255, 969255, 969255);

    printf("space and +: [% 05d, %+i, %+10d]\n", 258455, 258455, 258455);
    _printf("space and +: [% 05d, %+i, %+10d]\n", 258455, 258455, 258455);

    printf("space and +: [% 05d, %+i, %+10d]\n", 255, 255, 255);
    _printf("space and +: [% 05d, %+i, %+10d]\n", 255, 255, 255);
    printf("width: [%6X, %6x, %10s]\n",5, -4568,"ab");
    _printf("width: [%6X, %6x, %10s]\n",5, -4568,"ab");
    _printf("precision: [%012.4d, %.5i, %.1u]\n", 231, 4, 67);
	printf("precision: [%012.4f, %.5f, %.1f]\n", 231.0, 4.0, 67.0);
    return (0);
}
