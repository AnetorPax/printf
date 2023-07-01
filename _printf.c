#include "main.h"
/**
 * _printf - Prints output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char specifier;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			specifier = *format;
			count += _format_out(specifier, args);
		}
		else
		{
			count += _putchar(*format);
		}

		format++;
	}
	va_end(args);
	return (count);
}

/**
 * _format_out - Handles the conversion specifiers and outputs the result.
 * @specifier: The conversion specifier character.
 * @args: The list of arguments.
 *
 *
 * Return: The number of characters printed.
 */
int _format_out(char specifier, va_list args)
{
	switch (specifier)
	{
	case 'c':
		return (_putchar(va_arg(args, int)));
	case 's':
		return (_puts(va_arg(args, char *)));
	case 'd':
	case 'i':
		return (_print_decimal(args));
	case '%':
		return (_putchar('%'));
	case 'u':
		return (_print_unsigned_decimal(args));
	case 'o':
		return (_print_octal(args));
	case 'x':
		return (_print_hex(args));
	case 'X':
		return (_print_hex_upper(args));
	case 'S':
		return (_print_string_special(va_arg(args, char *)));
	case 'b':
		return (_print_binary(args));
	case 'p':
		return (_print_address(args));
	default:
		return (_putchar('%') + _putchar(specifier));
	}
}
