#include "main.h"

/**
 * print_hex - Prints unsigned hexadecimal numbers in lowercase.
 * @ap: The argument pointer.
 * @params: The parameters struct.
 *
 * Return: The number of bytes printed.
 */
int print_hex(va_list ap, params_t *params)
{
    unsigned long num;
    int count = 0;
    char *str;

    if (params->l_modifier)
        num = (unsigned long)va_arg(ap, unsigned long);
    else if (params->h_modifier)
        num = (unsigned short int)va_arg(ap, unsigned int);
    else
        num = (unsigned int)va_arg(ap, unsigned int);

    str = convert(num, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
    if (params->hashtag_flag && num)
    {
        *--str = 'x';
        *--str = '0';
    }
    params->unsign = 1;
    return (count += print_number(str, params));
}

/**
 * print_HEX - Prints unsigned hexadecimal numbers in uppercase.
 * @ap: The argument pointer.
 * @params: The parameters struct.
 *
 * Return: The number of bytes printed.
 */
int print_HEX(va_list ap, params_t *params)
{
    unsigned long num;
    int count = 0;
    char *str;

    if (params->l_modifier)
        num = (unsigned long)va_arg(ap, unsigned long);
    else if (params->h_modifier)
        num = (unsigned short int)va_arg(ap, unsigned int);
    else
        num = (unsigned int)va_arg(ap, unsigned int);

    str = convert(num, 16, CONVERT_UNSIGNED, params);
    if (params->hashtag_flag && num)
    {
        *--str = 'X';
        *--str = '0';
    }
    params->unsign = 1;
    return (count += print_number(str, params));
}

/**
 * print_binary - Prints unsigned binary numbers.
 * @ap: The argument pointer.
 * @params: The parameters struct.
 *
 * Return: The number of bytes printed.
 */
int print_binary(va_list ap, params_t *params)
{
    unsigned int num = va_arg(ap, unsigned int);
    char *str = convert(num, 2, CONVERT_UNSIGNED, params);
    int count = 0;

    if (params->hashtag_flag && num)
        *--str = '0';
    params->unsign = 1;
    return (count += print_number(str, params));
}

/**
 * print_octal - Prints unsigned octal numbers.
 * @ap: The argument pointer.
 * @params: The parameters struct.
 *
 * Return: The number of bytes printed.
 */
int print_octal(va_list ap, params_t *params)
{
    unsigned long num;
    char *str;
    int count = 0;

    if (params->l_modifier)
        num = (unsigned long)va_arg(ap, unsigned long);
    else if (params->h_modifier)
        num = (unsigned short int)va_arg(ap, unsigned int);
    else
        num = (unsigned int)va_arg(ap, unsigned int);

    str = convert(num, 8, CONVERT_UNSIGNED, params);

    if (params->hashtag_flag && num)
        *--str = '0';
    params->unsign = 1;
    return (count += print_number(str, params));
}
