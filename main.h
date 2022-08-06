#ifndef MAIN_H
#define MAIN_H
#include<stdarg.h>

int _printf(const char *format, ...);
int isDigit(char);
int isAlpha(char);
int setFlags(char *, int *, int, va_list *);
int print_string(char *, int *, int);
char *rot13(char *s);
int get_index(char *, char);

#endif
