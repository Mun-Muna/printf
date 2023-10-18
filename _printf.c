#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i, j, count = 0;
	spec specs[] = {{'c', print_c}, {'s', print_str}, {'%', print_mod},
		{'d', print_int}, {'i', print_int}, {'b', print_bin}, {'\0', NULL}};

	va_start(ap, format);
	if (!format)
	{
		return (-1);
	}
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
				return (-1);
			for (j = 0; specs[j].c; j++)
			{
				if (format[i + 1] == specs[j].c)
				{
					count += specs[j].f(ap);
					i++;
					break;
				}
			}
			if (!specs[j].c)
				count += _write(format[i]);
		}
		else
			count += _write(format[i]);
	}
	va_end(ap);
	return (count);
}
