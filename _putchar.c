#include "main.h"

/**
 * _puts - prints a string with newline
 * @str: the string to print
 * Return:( str-y)
 */

int _puts(char *str)
{
	char *y = str;/*declaration of variables*/

	while (*str)
		_putchar(*str++);
	return (str - y);
}


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, return -1, and error is set appropriately.
 */
int _putchar(int c)
{
	static int p;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || p >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, p);
		p = 0;
	}
	if (c != BUF_FLUSH)
		buf[p++] = c;
	return (1);
}
