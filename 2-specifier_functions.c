#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include <stdio.h>
/**
 * print_unsigned - prints unsigned int
 * @ap: list of arguments
 *
 * Return: number of characters printed
 */
int print_rev(va_list ap)
{
	char *str1 = va_arg(ap, char*);
	int i, j, count = 0;
	char *str2;

	if (!str1)
		return (-1);
	for (i = 0; str1[i]; i++)
	{}
	str2 = malloc(i);
	while ((--i) >= 0)
	{
		str2[j] = str1[i];
		count += _write(str2[j]);
		j++;
	}
	return (count);
}
