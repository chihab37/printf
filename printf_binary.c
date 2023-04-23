#include "main.h"
/**
  *printf_binary - prints an integer converted to binary
  *@arg_list: list of variadic args
  *Return: number of chars printed
  */
int printf_binary(va_list arg_list)
{
	unsigned int num = 0;
	int bit_count = 0;
	int int_arg = 0;

	int_arg = va_arg(arg_list, int);
	num = int_arg;
	if (int_arg < 0)
	{
		_write('1');
		int_arg = -int_arg;
		num = int_arg;
		bit_count++;
	}
	while (num > 0)
	{
		num /= 2;
		bit_count++;
	}
	printf_binary_rec(int_arg);
	return (bit_count);
}
/**
  *printf_binary_rec - recursively prints an int in binary
  *@int_arg: int to print
  */
void printf_binary_rec(int int_arg)
{
	unsigned int num = int_arg;

	if (num / 2)
		printf_binary_rec(num / 2);

	_write((num % 2) + '0');
}
