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
	char a[52] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
	char b[52] = "NnOoPpQqRrSsTtUuVvWwXxYyZzAaBbCcDdEeFfGgHhIiJjKkLlMm";
	int i, j;

	if (!str)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
			_write(str[i]);
		for (j = 0; j < 52; j++)
		{
			if (str[i] == a[j])
			{
				_write(b[j]);
				break;
			}
		}
	}
	return (i);
}
