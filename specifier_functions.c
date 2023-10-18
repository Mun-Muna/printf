#include "main.h"
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
/**
 * print_c - prints corrseponding character in argument list
 * @ap: list of arguments, type va_list
 *
 * Return: number of characters printed
 */
int print_c(va_list ap)
{
	char c = va_arg(ap, int);

	return (write(1, &c, 1));
}
/**
 * print_str - prints corrseponding character in argument list
 * @ap: list of arguments, type va_list
 *
 * Return: number of characters printed
 */
int print_str(va_list ap)
{
	char *str = va_arg(ap, char *);
	int i = 0;

	if (!str)
		str = "(null)";
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
/**
 * print_mod - prints modulo sign
 * @ap: list of arguments, type va_list
 *
 * Return: number of characters printed
 */
int print_mod(va_list ap)
{
	char c = '%';
	(void) ap;

	return (write(1, &c, 1));
}
/**
 * print_int - prints corresponding integer in argument list
 * @ap: list of arguments, type va_list
 *
 * Return: number of characters printed
 */
int print_int(va_list ap)
{
	int count = 0, i = 1;
	long int n = va_arg(ap, int);
	char digit;

	if (n < 0)
	{
		count += _write('-');
		n = -1 * n;
	}
	for (; n / i > 9; i *= 10)
	{}
	for (; i >= 1; i /= 10)
	{
		digit = ((n / i) % 10) + '0';
		count += _write(digit);
	}
	return (count);
}
/**
 * print_bin - print in binary form
 * @ap: list of arguments of type va_list
 *
 * Return: number of characters printed
 */
int print_bin(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	int i, count = 0;
	char arr[64];

	if (n == 0)
	{
		count = _write('0');
		return (count - 1);
	}
	for (i = 0; n > 0; i++)
	{
		if (n % 2 == 0)
			arr[i] = '0';
		else
			arr[i] = '1';
		n /= 2;
	}
	while ((--i) >= 0)
	{
		count += _write(arr[i]);
	}
	return (count - 1);
}

