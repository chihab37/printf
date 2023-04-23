#include "main.h"
/**
  *my_print_char - prints character passed in as arg
  *@args: va_list arg
  *@count: current count of arguments printed
  *Return: count
  */
int my_print_char(va_list args, int count)
{
	count += _putchar(va_arg(args, int));
	return (count);
}

/**
  *my_print_string - print a string passed in as arg
  *@args: va_list arg
  *@count: ...
  *Return: count
  */

int my_print_string(va_list args, int count)
{
	char *str = va_arg(args, char *);
		while (*str != '\0')
		{
			count += _putchar(*str);
			str++;
		}
	return (count);
}
/**
  *my_print_percent - print percent sign
  *@count: ...
  *Return: count
  */

int my_print_percent(int count)
{
	count += _putchar('%');
	return (count);
}

/**
  *my_print_default - print a default character if an invalid format spec
  *is provided
  *@count: ...
  *Return: count
  */

int my_print_default(char format, int count)
{
	_putchar('%');
	_putchar(format);
	count += 2;
	return (count);
}

/**
  *_printf - produce output according to a format
  *@format: character string containing zero or more directives
  *Return: number of characters printed
  */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += my_print_char(args, count);
					break;
				case 's':
					count = my_print_string(args, count);
					break;
				case '%':
					count += my_print_percent(count);
					break;
				default:
					count = my_print_default(*format, count);
					break;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
