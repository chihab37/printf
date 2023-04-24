#include "main.h"
/**
  *_printf_unsigned - print an unsigned decimal integer
  *@arg_list: vardi list
  *Return: number of chars printed
  */
int _printf_unsigned(va_list arg_list)
{
	unsigned int num = va_arg(arg_list, unsigned int);
	int count = 0;
	char buffer[20];
	int i = 0;

	if (num == 0)
	{
		_write('0');
		return (1);
	}

	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}

	while (--i >= 0)
	{
		_write(buffer[i]);
		count++;
	}

	return (count);
}
/**
  *_printf_octal - print an unsigned octal integer
  *@arg_list: va list
  *Return: number of chars printed
  */
int _printf_octal(va_list arg_list)
{
	unsigned int num = va_arg(arg_list, unsigned int);
	int count = 0;
	char buffer[20];
	int i = 0;

	if (num == 0)
	{
		_write('0');
		return (1);
	}

	while (num > 0)
	{
		buffer[i++] = (num % 8) + '0';
		num /= 8;
	}

	while (--i >= 0)

	{
		_write(buffer[i]);
		count++;
	}
	return (count);
}
