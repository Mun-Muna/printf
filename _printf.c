#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i, j, k;
	char x;
	char *str;

	va_start(ap, format);
	for (i = 0; format && format[i]; i++)
	{
		j = 0;
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			switch (format[i])
			{
				case 'c':
					j++;
					x = va_arg(ap, int);
					write(1, &x, 1);
					break;
				case 's':
					str = va_arg(ap, char *);
					k = 0;
					while (str[k])
						k++;
					j += k;
					write(1, str, k);
					break;
				case '%':
					j++;
					x = '%';
					write(1, &x, 1);
					break;
				default:
					j += 2;
					write(1, &format[i - 1], 1);
					write(1, &format[i], 1);
			}
		}
		else
		{
			j++;
			write(1, &format[i], 1);
		}
	}
	va_end(ap);
	return (j);
}
