#include "main.h"
/**
  *printf_binary - prints an integer converted to binary
  *@arg_list: list of variadic args
  *Return: number of chars printed
  */
int printf_binary(va_list arg_list)
{
	unsigned int num = va_arg(arg_list, unsigned int);
	unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);
	int count = 0;
	int started = 0;

	while (mask)
	{
		if (num & mask)
		{
			_write('1');
			count++;
			started = 1;
		}
		else if (started || mask == 1)
		{
			_write('0');
			count++;
		}
		mask >>= 1;
	}
	return (count);
}
