#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list ap;
	char *str;
	int i, j;
	char x;

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
					j += sizeof(str);
					write(1, str, sizeof(str));
					break;
				case '%':
					j++;
					x = '%';
					write(1, &x, 1);
					break;
			}
		}
		else
		{
			j++;
			write(1, &format[i], 1);
		}
	}
	return (j);
}
