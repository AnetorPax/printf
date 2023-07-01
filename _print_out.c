#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and error is set appropriately.
 */
int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (write(1, &c, 1));
}


/**
 * _puts - Prints a string with a newline.
 * @str: The string to print.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _puts(char *str)
{
	int len = 0;

	while (*str)
	{
		len += _putchar(*str);
		str++;
	}

/*      len += _putchar('\n'); */

	return (len);
}
