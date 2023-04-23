#include "main.h"
/**
  *_write - writes c to stdout
  *@c: the char printed
  *Return: 1 is success, -1 upon failure
  */
int _write(char c)
{
	return (write(1, &c, 1));
}
/**
 *printf_int - prints an int
 *@arg_list: list of args
 *Return: The number of characters printed
*/
int printf_int(va_list arg_list)
{
	int count = 1;
	int num;
	unsigned int unum, temp;

	num = va_arg(arg_list, int);
	unum = num;

	if (num < 0)
	{
		_write('-');
		unum = -num;
		count++;
	}

	temp = unum;
	while (temp > 9)
	{
		temp /= 10;
		count++;
	}
	printf_int_rec(unum);
	return (count);
}
/**
 *printf_int_rec - print int recusively
 *@unum: int to print
 */
void printf_int_rec(unsigned int unum)
{
	if (unum / 10)
		printf_int_rec(unum / 10);

	_write((unum % 10) + '0');
}
/**
  *_printf_char - prints a character
  *@arg_list: a list args
  *Return: the number of character printed always 1
  */
int _printf_char(va_list arg_list)
{
	_write(va_arg(arg_list, int));
	return (1);
}

/**
  *_printf_str - prints a string
  *@arg_list: a list of args
  *Return: the number of characters printed
  */
int _printf_str(va_list arg_list)
{
	char *str = va_arg(arg_list, char *);
	int i = 0;

	if (str != NULL)
	{
		while (str[i])
		{
			_write(str[i]);
			i++;
		}
	return (i);
	}
	_write('(');
	_write('n');
	_write('u');
	_write('l');
	_write('l');
	_write(')');
	return (6);
}
