#include <unistd.h>
/**
 * _write: write to stdout
 * @c : character to be printed
 *
 * Return: 1 if success.
 */
int _write(char c)
{
	return(write(1, &c, 1));
}
