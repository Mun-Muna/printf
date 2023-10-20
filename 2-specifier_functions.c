#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include <stdio.h>
/**
 * print_rev - prints reversed string
 * @ap: list of arguments
 *
 * Return: number of characters printed
 */
int print_rev(va_list ap)
{
	char *str = va_arg(ap, char*);
	int i, count = 0;

	if (!str)
	{
		str = "(null)";
		return (write(1, str, 6));
	}
	for (i = 0; str[i]; i++)
	{}
	while ((--i) >= 0)
		count += _write(str[i]);
	return (count);
}
/**
 * print_rot13 - print rot13'ed string
 * @ap: list of arguments
 *
 * Return: numbers of characters printed
 */
int print_rot13(va_list ap)
{
	char *str = va_arg(ap, char *);
	int i, count = 0;

	if (!str)
		str = "(null)";
	for (; str[i]; i++)
	{
		if ((str[i] >= 'A' && str[i] <= 'M') || (str[i] >= 'a' && str[i] <= 'm'))
			str[i] += 13;
		else
			if ((str[i] >= 'N' && str[i] <= 'Z') || (str[i] >= 'n' && str[i] <= 'z'))
			str[i] -= 13;
		count += _write(str[i]);
	}
	return (count);
}
