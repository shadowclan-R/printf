#include "main.h"

/**
 * print_percent - a function that prints a percent sign
 * @types: list of arguments
 * @buffer: character variable buffer array to handle print
 * @f1: calculates flags
 * @w1: get width.
 * @p1: ineger precision specification
 * @s1: integer size specifier
 * Return: returns the number of chars printed
 */
int print_per(va_list types, char buffer[],
	int f1, int w1, int p1, int s1)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(f1);
	UNUSED(w1);
	UNUSED(p1);
	UNUSED(s1);
	return (write(1, "%%", 1));
}
