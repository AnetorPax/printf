#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _str_format - Prints output according to a format.
 * @format: The format string.
 * @args: the list of arguments
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _str_format(const char *format, va_list args)
{
	int count = 0;
	char c, *str;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				c = (char)va_arg(args, int);
				count += _putchar(c);
				break;
			case 's':
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				count += _puts(str);
				break;
			case '%':
				count += _putchar('%');
				break;
			default:
				count += _putchar('%');
				count += _putchar(*format);
				break;
			}
		}
		else
		{
			count += _putchar(*format);
		}

		format++;
	}
	return (count);
}
