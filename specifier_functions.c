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

	write(1, &c, 1);
	return (1);
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
		i++;
	write(1, str, i);
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

	write(1, &c, 1);
	return (1);
}
