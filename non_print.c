#include "main.h"

/**
 * _print_string_special - Prints the string with special handling for
 * non-printable characters.
 * @str: The input string.
 *
 * Return: The number of characters printed.
 */
int _print_string_special(char *str)
{
	int count = 0;

	if (str == NULL)
	{
		return (_puts("(null)"));
	}

	while (*str)
	{
		if (_is_non_printable(*str))
		{
			count += _putchar('\\');
			count += _putchar('x');
			count += _putchar(_to_hex(*str >> 4));
			count += _putchar(_to_hex(*str & 0x0F));
		}
		else
		{
			count += _putchar(*str);
		}

		str++;
	}

	return (count);
}

/**
 * _is_non_printable - Checks if a character is non-printable.
 * @c: The character to check.
 *
 * Return: 1 if non-printable, 0 otherwise.
 */
int _is_non_printable(char c)
{
	return (c < 32 || c >= 127);
}

/**
 * _to_hex - Converts a number to its hexadecimal representation.
 * @num: The number to convert.
 *
 * Return: The hexadecimal representation as a character.
 */
char _to_hex(int num)
{
	return ((num < 10) ? (num + '0') : (num - 10 + 'A'));
}

/**
 * _print_binary - Prints an unsigned int argument as binary.
 * @args: The list of arguments.
 *
 * Return: The number of characters printed.
 */
int _print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int i, count = 0, num_bits = 0;
	int bit = 0, flag = 0;

	if (num == 0)
	{
		count += _putchar('0');
		return (count);
	}

	num_bits = sizeof(unsigned int) * 8;
	for (i = num_bits - 1; i >= 0; i--)
	{
		bit = (num >> i) & 1;
		if (bit || flag)
		{
			count += _putchar(bit + '0');
			flag = 1;
		}
	}

	return (count);
}
