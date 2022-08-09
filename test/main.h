#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define DECIMAL 10
#define HEX 16
#define OCTAL 8
#define BINARY 2

/**
 * struct specifierStruct - struct to hold all specifier
 * @specifier: character pointer
 * @func: callback funtion
 */
typedef struct specifierStruct
{
	char *specifier;
	int (*func)(const char *, int, va_list, int *);
} specifierStruct;

int check_specifier(const char *, int, va_list, int *);
int _printf(const char *format, ...);
int isDigit(char);
int isAlpha(char);
int setFlags(const char *, int *, int, va_list);
int print_string(char *, int *, int);
char *rot13(char *s);
int get_index(char *, char);
int _vprintf(const char *, va_list);
int _printf(const char *, ...);
void signedNumberToString(int64_t, int, char *, char, int *);
void unsignedNumberToString(uint64_t, int, char *, char, int *);
int _putchar(char);
int format_specifier(int, const char *, va_list, int *, int *,  int *, int *);
char *reversed(char *);

int print_char(const char *, int, va_list, int *);
int print_int(const char *, int, va_list, int *);
int print_str(const char *, int, va_list, int *);
int print_unsigned(const char *, int, va_list, int *);
int print_addr(const char *, int, va_list, int *);
int print_oct_bin(const char *, int, va_list, int *);
int print_rot13(const char *, int, va_list, int *);
int print_reverse(const char *, int, va_list, int *);
char *upper_str(char *);
int isPrintable(char);
int upper_strlen(char *);
int getDigitsValue(const char *fmt, int *j, int);

#endif
