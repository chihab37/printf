#ifndef _PRINTF_H_
#define _PRINTF_H_

#include <stdarg.h>
#include <stdio.h>
int my_print_char(va_list args, int count);
int my_print_string(va_list args, int count);
int my_print_percent(int count);
int my_print_default(char format, int count);
int _putchar(char c);
int _printf(const char *format, ...);

#endif
