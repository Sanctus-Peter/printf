#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>

int _vprintf(const char *, va_list);
int _printf(const char *, ...);
void signedNumberToString(int64_t, int, char *, char *);
void unsignedNumberToString(int64_t, int, char *, char *);
int _putchar(char);
int print_string(char *, int *, int);
char *rot13(char *);
int get_index(char *, char);
int isDigit(char);
int isAlpha(char);
int setFlags(char *, int *, va_list);

#endif
