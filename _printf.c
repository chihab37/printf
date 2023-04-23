#include "main.h"
/**
  *_printf - produce output according to a format
  *@format: character string containing zero or more directives
  *Return: number of characters printed
  */

int _printf(const char *format, ...)
{
	va_list arg_list;
	int char_count = 0;

	va_start(arg_list, format);
	if (format == NULL)
		return (-1);
	char_count = print_format(format, arg_list);

	va_end(arg_list);
	return (char_count);
}
