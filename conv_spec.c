#include "main.h"

/**
 * _print_octal - Prints an octal number
 * @args: The va_list containing the unsigned int argument
 *
 * Return: The number of characters printed
 */
int _print_octal(va_list args)
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
		buffer[i++] = num % 8 + '0';
		num /= 8;
	}

	for (j = i - 1; j >= 0; j--)
	{
		count += _putchar(buffer[j]);
	}

	return (count);
}

/**
 * _print_hex - Prints a hexadecimal number (lowercase)
 * @args: The va_list containing the unsigned int argument
 *
 * Return: The number of characters printed
 */
int _print_hex(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int j, i, digit, count = 0;
	char buffer[32];

	if (num == 0)
	{
		count += _putchar('0');
		return (count);
	}


	i = 0;
	while (num > 0)
	{
		digit = num % 16;

		buffer[i++] = (digit < 10) ? digit + '0' : digit - 10 + 'a';
		num /= 16;
	}

	for (j = i - 1; j >= 0; j--)
	{
		count += _putchar(buffer[j]);
	}

	return (count);
}


/**
 * _print_hex_upper - Prints a hexadecimal number (uppercase)
 * @args: The va_list containing the unsigned int argument
 *
 * Return: The number of characters printed
 */
int _print_hex_upper(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int i, j, digit, count = 0;
	char buffer[32];


	if (num == 0)
	{
		count += _putchar('0');
		return (count);
	}


	i = 0;
	while (num > 0)
	{
		digit = num % 16;

		buffer[i++] = (digit < 10) ? digit + '0' : digit - 10 + 'A';
		num /= 16;
	}

	for (j = i - 1; j >= 0; j--)
	{
		count += _putchar(buffer[j]);
	}

	return (count);
}

/**
 * _print_hex_address - Prints the hexadecimal representation of an address.
 * @addr: The address to print.
 *
 * Return: The number of characters printed.
 */
int _print_hex_address(uintptr_t addr)
{
	char buffer[20];  /* Buffer to store the hexadecimal characters */
	int count = 0;
	int i = 0;

	if (addr == 0)
	{
		count += _putchar('0');
		return (count);
	}

	while (addr > 0)
	{
		int rem = addr % 16;

		if (rem < 10)
			buffer[i++] = rem + '0';
		else
			buffer[i++] = rem - 10 + 'a';

		addr /= 16;
	}

	_putchar('0');
	_putchar('x');

	for (i = i - 1; i >= 0; i--)
	{
		count += _putchar(buffer[i]);
	}

	return (count);
}




/**
 * _print_address - Prints the address specifier.
 * @args: The list of arguments
 *
 * Return: The number of characters printed.
 */
int _print_address(va_list args)
{
	uintptr_t addr = (uintptr_t)va_arg(args, void *);

	return (_print_hex_address(addr));
}
