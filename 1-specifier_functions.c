#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <stdio.h>
/**
 * print_unsigned - prints unsigned int
 * @ap: list of arguments
 *
 * Return: number of characters printed
 */
int print_unsigned(va_list ap)
{
	int count = 0, i = 1;
	unsigned int n = va_arg(ap, unsigned int);
	char digit;

	for (; n / i > 9; i *= 10)
	{}
	for (; i >= 1; i /= 10)
	{
		digit = ((n / i) % 10) + '0';
		count += _write(digit);
	}
	return (count);
}
