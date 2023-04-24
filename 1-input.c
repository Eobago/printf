#include "main.h"

/**
 * _printf - prints and input into the standard output
 * @format: the format string
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)

{
	int sum = 0;
	va_list ab;
	char *b, *result;

	params_t params = PARAMS_INIT;

	va_start(ab, format);

	if (!format || (format[0] == '%' && !format[1]))/* checking for NULL char */
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (b = (char *)format; *b; b++)
	{
		init_params(&params, ab);
		if (*b != '%')/*checking for the % specifier*/
		{
			sum += _putchar(*b);
			continue;
		}
		result = b;
		b++;
		while (get_flag(b, &params)) /* while char at b is flag character */
		{
			b++; /* next character */
		}
		b = get_width(b, &params, ab);
		b = get_precision(b, &params, ab);
		if (get_modifier(b, &params))
			b++;
		if (!get_specifier(b))
			sum += print_from_to(result, b,
					params.l_modifier || params.h_modifier ? b - 1 : 0);
		else
			sum += get_print_func(b, ab, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ab);
	return (sum);
}
