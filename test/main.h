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


int _printf(const char *format, ...);
int isDigit(char);
int isAlpha(char);
int setFlags(const char *, int *, int, va_list);
int print_string(char *, int *, int);
char *rot13(char *s);
int get_index(char *, char);
int _vprintf(const char *, va_list);
int _printf(const char *, ...);
void signedNumberToString(int64_t, int, char *, const char *, int);
void unsignedNumberToString(uint64_t, int, char *, const char *, int);
int _putchar(char);
int format_specifier(int, const char *, va_list, int *, int *,  int *, int *);
char *reversed(char *);

#endif
