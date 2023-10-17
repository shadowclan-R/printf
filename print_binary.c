#include "main.h"

/**
 * print_binary - a function that prints a binary
 * @types: List of arguments
 * @buffer: character variable buffer array to handle print
 * @f1: calculates flags
 * @w1: get width.
 * @p1: ineger precision specification
 * @s1: integer size specifier
 * Return: returns the number of binary printed
 */
int print_binary(va_list types, char buffer[],
	int f1, int w1, int p1, int s1)
{
	unsigned int x, y, k, s;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(f1);
	UNUSED(w1);
	UNUSED(p1);
	UNUSED(s1);

	x = va_arg(types, unsigned int);
	y = 2147483648;
	a[0] = x / y;
	for (k = 1; k < 32; k++)
	{
		y /= 2;
		a[k] = (x / y) % 2;
	}
	for (k = 0, s = 0, count = 0; k < 32; k++)
	{
		s += a[k];
		if (s || k == 31)
		{
			char b = '0' + a[k];

			write(1, &b, 1);
			count++;
		}
	}
	return (count);
}
