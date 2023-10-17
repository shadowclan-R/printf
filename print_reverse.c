#include "main.h"

/**
 * print_reverse - a function that prints reverse string
 * @types: List of arguments
 * @buffer: character variable buffer array to handle print
 * @f1: calculates flags
 * @w1: get width.
 * @p1: ineger precision specification
 * @s1: integer size specifier
 * Return: returns the reverse print
 */
int print_reverse(va_list types, char buffer[],
	int f1, int w1, int p1, int s1)
{
	char *s;
	int x, i = 0;

	UNUSED(buffer);
	UNUSED(f1);
	UNUSED(w1);
	UNUSED(s1);

	s = va_arg(types, char *);

	if (s == NULL)
	{
		UNUSED(p1);

		s = ")Null(";
	}
	for (x = 0; s[x]; x++)
		;

	for (x = x - 1; x >= 0; x--)
	{
		char z = s[x];

		write(1, &z, 1);
		i++;
	}
	return (i);
}
