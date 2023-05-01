#include "main.h"

/**
 * _printf - prints and input into the standard output
 * @format: the format string
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)

{
	int sum = 0;
	va_list ap;
	char *q, *start;

	params_t params = PARAMS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))/* checking for NULL char */
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (q = (char *)format; *q; p++)
	{
		init_params(&params, ap);
		if (*q != '%')/*checking for the % specifier*/
		{
			sum += _putchar(*q);
			continue;
		}
		start = q;
		q++;
		while (get_flag(q, &params)) /* while char at q is flag character */
		{
			q++; /* next character */
		}
		q = get_width(q, &params, ap);
		q = get_precision(q, &params, ap);
		if (get_modifier(q, &params))
			q++;
		if (!get_specifier(q))
			sum += print_from_to(start, q,
					params.l_modifier || params.h_modifier ? q - 1 : 0);
		else
			sum += get_print_func(q, ap, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sum);
}
