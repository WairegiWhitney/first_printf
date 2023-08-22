#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

typedef struct format
{
	char *id;
	int (*f)();
} convert_match;


int _printf(const char *format, ...);
int printf_int(va_list my_args);
int _putchar(char c);
#endif
