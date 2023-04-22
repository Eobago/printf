#include "main.h"

/**
 * get_precision - gets the precision from the format string
 * @s: the  string
 * @params: the parameters
 * @ap: the argument
 * Return: new pointer
*/

char *get_precision(char *s, params_t *params, va_list ap)
{
	int f = 0;

	if (*s != '.')
		return (s);
	s++;
	if (*s == '*')
	{
		f = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			f = f * 10 + (*s++ - '0');
	}
	params->precision = f;
	return (s);
}
