#include "main.h"

#include "main.h"
/**
 * _print_unsigned_decimal - Prints an unsigned decimal number
 * @args: The va_list containing the unsigned int argument
 *
 * Return: The number of characters printed
 */
int _print_unsigned_decimal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int j, i, count = 0;
	char buffer[32];

	if (num == 0)
	{
		count += _putchar('0');
		return (count);
	}

	i = 0;
	while (num > 0)
	{
		buffer[i++] = num % 10 + '0';
		num /= 10;
	}

	for (j = i - 1; j >= 0; j--)
	{
		count += _putchar(buffer[j]);
	}

	return (count);
}

/**
 * _print_decimal - Prints a decimal number
 * @args: The list of arguments
 * Return: Number of characters printed
 */
int _print_decimal(va_list args)
{
	int num;
	int count = 0;
	int divisor = 1;


	num = va_arg(args, int);

	if (num == 0)
	{
		count += _putchar('0');
		return (count);
	}
	if (num < 0)
	{
		num = -num;
		count += _putchar('-');
	}

	while (num / divisor > 9)
		divisor *= 10;

	while (divisor != 0)
	{
		count += _putchar('0' + (num / divisor));
		num %= divisor;
		divisor /= 10;
	}

	return (count);
}

/**
 * spec_format - Handles the conversion specifiers of "d" and "i"
 * @format: the format string
 * @args: the list of arguments
 * Return: number of characters printed
 */
int spec_format(const char *format, va_list args)
{
	int count = 0;
	int i = 0;

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'd' || format[i] == 'i')
				count += _print_decimal(args);
			else
			{
				count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		else
			count += _putchar(format[i]);
		i++;
	}

	return (count);
}
