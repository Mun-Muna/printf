#include "main.h"
#include <unistd.h>
/**
 * print_char - prints corrseponding character in argument list
 * @ap: list of arguments, type va_list
 *
 * Return: number of characters printed
 */
int print_char(va_list ap)
{
	char c = va_arg(ap, int);

	return (write(1, &c, 1));
}
/**
 * print_string - prints corrseponding character in argument list
 * @ap: list of arguments, type va_list
 *
 * Return: number of characters printed
 */
int print_string(va_list ap)
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
	char digit;
	long int n = va_arg(ap, int);

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
