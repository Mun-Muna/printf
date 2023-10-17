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
	spec specs[] = {{'c', print_char}, {'s', print_string}, {'%', print_mod},
		{'\0', NULL}};

	va_start(ap, format);
	if (!format)
	{
		return (-1);
	}
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
				i++;
				if (!format[i])
					return (-1);
				for (j = 0; j < 3; j++)
				{
					if (format[i] == specs[j].c)
					{
						count += specs[j].f(ap);
						break;
					}
				}
				if (!specs[j].c)
				{
					count += _write(format[i - 1]);
					count += _write(format[i]);
				}
		}
		else
		{
			count += _write(format[i]);
		}
	}
	va_end(ap);
	return (count);
}
