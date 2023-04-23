#include "main.h"
/**
  *print_format - prints a format string
  *@format: format string to print
  *@args: list of variadic arguments
  *Return: number of characters printed
  */
int print_format(const char *format, va_list args)
{
	int count = 0;
	int i = 0;

	while (format && format[i])
	{
		if (format[i] == '%')
		{
		if (format[i + 1] == '\0')
			return (-1);
		i++;
		while (format[i] == ' ')
			i++;
		if (format[i] == '%')
			count += _write(format[i]);

		if (validate_specifier(format[i]) == 0)
			count = print_invalid_specifier(format[i - 1], format[i], count);
		else
			count += print_specfier(format[i], args);
		}
	else
		count += _write(format[i]);
	i++;
	}
	return (count);
}
/**
  *print_specfier - Prints a format specifier
  *@format: format specifier to print
  *@arg_list: list of variadic arguments
  *Return: number of characters printed
  */
int print_specfier(char format, va_list arg_list)
{
	int index = 0;
	int len = 0;

	str_sp typs[] = {
		{"c", _printf_char},
		{"s", _printf_str},
		{"d", printf_int},
		{"i", printf_int},
		{"b", printf_binary},
		{NULL, NULL}
	};
	while (typs[index].specifier)
	{
		if (*typs[index].specifier == format)
			len = typs[index].p(arg_list);

		index++;
	}

	return (len);
}
/**
 *validate_specifier - validates a format specifier character
 *@spec_char: char to validate
 *Return: 1 if the character is a valid format specifier, 0 otherwise
 */
int validate_specifier(char spec_char)
{
	char spec_chars[] = {'c', 's', 'd', 'i', 'b', '%'};
	int index = 0;

	while (spec_chars[index])
	{
		if (spec_chars[index] == spec_char)
			return (1);

		index++;
	}

	return (0);
}
/**
  *print_invalid_specifier - prints an invalid format specifier
  *@prev_char: previous character before the invalid specifier
  *@specifier: invalid format specifier to print
  *@char_count: current number of characters
  *printed before this function is called
  *Return: updated number of characters printed after this function is called
  */
int print_invalid_specifier(char prev_char, char specifier, int char_count)
{
	char_count += _write('%');

	if (prev_char == ' ')
	{
		char_count += _write(' ');
		char_count += _write(specifier);
	}
	else
		char_count += _write(specifier);

	return (char_count);
}
