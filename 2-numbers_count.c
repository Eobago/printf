#include "main.h"

/**
 * convert - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 * @params: paramater struct
 *
 * Return: string
 */
char *convert(long int num, int base, int flags, params_t *params)
{
	static char *rail;
	static char buffer[50];
	char sign = 0;
	char *str;
	unsigned long n = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	rail = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	str = &buffer[49];
	*str = '\0';

	do	{
		*--str = rail[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--str = sign;
	return (str);
}

/**
 * print_unsigned - prints unsigned integer numbers
 * @ap: argument pointer
 * @params: the parameters
 * Return: bytes printed
 */
int print_unsigned(va_list ap, params_t *params)
{
	unsigned long m;

	if (params->m_modifier)
		m = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		m = (unsigned short int)va_arg(ap, unsigned int);
	else
		m = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (print_number(convert(m, 10, CONVERT_UNSIGNED, params), params));
}



/**
 * print_address - prints address
 * @ap: argument pointer
 * @params: the parameters
 * Return: bytes printed
 */

int print_address(va_list ap, params_t *params)
{
	unsigned long int p = va_arg(ap, unsigned long int);
	char *tsr;

	if (!p)
		return (_puts("(nil)"));

	tsr = convert(p, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--tsr = 'x';
	*--tsr = '0';
	return (print_number(tsr, params));
}
