#include "main.h"
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
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					{
					char *str = va_arg(args, char *);

					while (*str != '\0')
					{
						count += _putchar(*str);
						str++;
					}
					}
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					_putchar('%');
					_putchar(*format);
					count += 2;
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
