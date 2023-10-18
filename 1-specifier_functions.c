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
/**
 * print_octal - prints int in octal
 * @ap: list of arguments
 *
 * Return: number of characters printed
 */
int print_octal(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	int i, count = 0;
	char arr[64];

	if (n == 0)
		return (_write('0'));
	for (i = 0; n > 0; i++)
	{
		if (n % 8 == 0)
			arr[i] = '0';
		else
			arr[i] = (n % 8) + '0';
		n /= 8;
	}
	while ((--i) >= 0)
	{
		count += _write(arr[i]);
	}
	return (count);
}
/**
 * print_hexa - prints int in hexadecimal
 * @ap: list of arguments            	
 *
 * Return: number of characters print
 */
int print_hexa(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	int i, count = 0;
	char arr[64];

	if (n == 0)
		return (_write('0'));
	for (i = 0; n > 0; i++)
	{
		if (n % 16 == 0)
			arr[i] = '0';
		else
		{
			if ((n % 16) < 10)
				arr[i] = (n % 16) + '0';
			else
				arr[i] = (n % 16) + 'W';
		}
		n /= 16;
	}
	while ((--i) >= 0)
	{
		count += _write(arr[i]);
	}
	return (count);
}
/**
 * print_HEXA - prints int in hexadecimal
 * @ap: list of arguments            	
 *
 * Return: number of characters print
 */
int print_HEXA(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	int i, count = 0;
	char arr[64];

	if (n == 0)
		return (_write('0'));
	for (i = 0; n > 0; i++)
	{
		if (n % 16 == 0)
			arr[i] = '0';
		else
		{
			if ((n % 16) < 10)
				arr[i] = (n % 16) + '0';
			else
				arr[i] = (n % 16) + '7';
		}
		n /= 16;
	}
	while ((--i) >= 0)
	{
		count += _write(arr[i]);
	}
	return (count);
}
