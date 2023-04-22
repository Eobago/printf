#include "main.h"

/**
 * get_specifier - finds the format function
 * @s: string of the format
 * Return: the number of bytes printed
 */

int (*get_specifier(char *s))(va_list ap, params_t *params)

{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};

	int p = 0;

	while (specifiers[p].specifier)
	{
		if (*s == specifiers[p].specifier[0])
		{
			return (specifiers[p].f);
		}
		p++;
	}
	return (NULL);
}

/**
 * get_print_func - finds the format function
 * @s: string of the format
 * @ap: argument pointer
 * @params: the parameters
 * Return:  bytes number printed
 */

int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*g)(va_list, params_t *) = get_specifier(s);

	if (g)
		return (g(ap, params));
	return (0);
}

/**
 * get_flag - finds the flag functions
 * @s: the format string
 * @params: the parameters
 * Return: if flag was valid
 */

int get_flag(char *s, params_t *params)

{
	int p = 0;

	switch (*s)
	{
		case '+':
			p = params->plus_flag = 1;
			break;
		case ' ':
			p = params->space_flag = 1;
			break;
		case '#':
			p = params->hashtag_flag = 1;
			break;
		case '-':
			p = params->minus_flag = 1;
			break;
		case '0':
			p = params->zero_flag = 1;
			break;
	}
	return (p);
}

/**
 * get_modifier - finds the modifier function
 * @s: string
 * @params: parameter
 * Return:when modifier was valid
 */

int get_modifier(char *s, params_t *params)
{
	int q = 0;

	switch (*s)
	{
		case 'h':
			q = params->h_modifier = 1;
			break;
		case 'l':
			q = params->l_modifier = 1;
			break;
	}
	return (q);
}

/**
 * get_width - gets the width from the format string
 * @s: the string
 * @params: the parameters
 * @ap: the argument pointer
 * Return: new pointer
 */

char *get_width(char *s, params_t *params, va_list ap)

	/* should this function use char **s and modify the pointer? */
{
	int g = 0;

	if (*s == '*')
	{
		g = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			g = g * 10 + (*s++ - '0');
	}
	params->width = g;
	return (s);
}
