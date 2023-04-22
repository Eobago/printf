#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 * Return: 1 if digit, else 0
 */

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: integer length of string
 */

int _strlen(char *s)
{
	int q = 0;

	while (*s++)
		q++;
	return (q);
}

/**
 * print_number - prints a number with options
 * @str:  string
 * @params: the parameter struct
 * Return: chars printed
 */

int print_number(char *str, params_t *params)
{
	unsigned int r = _strlen(str);
	int lad = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (lad)
	{
		str++;
		r--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (lad)
		*--str = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - prints a number with options
 * @str: the base number as  string
 * @params: the parameter
 *
 * Return: chars printed
 */

int print_number_right_shift(char *str, params_t *params)
{
	unsigned int p = 0, lad, lad2, p = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	lad = lad2 = (!params->unsign && *str == '-');
	if (lad && p < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		lad = 0;
	if ((params->plus_flag && !lad2) ||
		(!params->plus_flag && params->space_flag && !lad2))
		p++;
	if (lad && pad_char == '0')
		n += _putchar('-');
	if (params->plus_flag && !lad2 && pad_char == '0' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !lad2 &&
		!params->unsign && params->zero_flag)
		n += _putchar(' ');
	while (p++ < params->width)
		n += _putchar(pad_char);
	if (lad && pad_char == ' ')
		n += _putchar('-');
	if (params->plus_flag && !lad2 && pad_char == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !lad2 &&
		!params->unsign && !params->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_left_shift - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 * Return: chars printed
 */

int print_number_left_shift(char *str, params_t *params)
{
	unsigned int n = 0, lad, lad2, p = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	lad = lad2 = (!params->unsign && *str == '-');
	if (lad && p < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		lad = 0;

	if (params->plus_flag && !lad2 && !params->unsign)
		n += _putchar('+'), p++;
	else if (params->space_flag && !neg2 && !params->unsign)
		n += _putchar(' '), p++;
	n += _puts(str);
	while (p++ < params->width)
		n += _putchar(pad_char);
	return (n);
}
