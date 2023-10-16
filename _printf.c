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
	for (i = 0, j = 0; format && format[i]; i++)
	{
			if (format[i] == '%')
			{
				i++;
				switch (format[i])
				{
					case 'c':
						x = va_arg(ap, int);
						if (x)
						{
							write(1, &x, 1);
							j++;
						}
						break;
					case 's':
						str = va_arg(ap, char *);
						if (!str)
							str = "(null)";
						k = 0;
						while (str[k])
							k++;
						j += k;
						write(1, str, k);
						break;
					case '%':
						x = '%';
						write(1, &x, 1);
						j++;
						break;
					default:
						if (!format[i])
							return (j);
						write(1, &format[i - 1], 1);
						write(1, &format[i], 1);
						j += 2;
						break;
				}
			}
			else
			{
				write(1, &format[i], 1);
				j++;
			}
	}
	va_end(ap);
	if (!format)
		return (-1);
	return (j);
}
