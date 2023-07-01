#include "main.h"
#include <stdio.h>

/**
 * _print_Unsignd - output unsigned integer
 * @args: list of arguments
 * Return: characters to be printed
 */
int _print_Unsignd(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int divisor = 1;
	int count = 0;

	/* Calculate the divisor to determine the number of digits */
	while (num / divisor > 9)
		divisor *= 10;

	/*x Print each digit */
	while (divisor != 0)
	{
		count += _putchar('0' + (num / divisor));
		num %= divisor;
		divisor /= 10;
	}

	return (count);
}
