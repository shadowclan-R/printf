#include "main.h"

/**
 * print_str - a function that prints a string
 * @types: List of arguments
 * @buffer: character variable buffer array to handle print
 * @f1: calculates flags
 * @w1: get width.
 * @p1: ineger precision specification
 * @s1: integer size specifier
 * Return: returns the number of string
 */
int print_str(va_list types, char buffer[],
	int f1, int w1, int p1, int s1)
{
	int l = 0, x;
	char *s = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(f1);
	UNUSED(w1);
	UNUSED(p1);
	UNUSED(s1);
	if (s == NULL)
	{
		s = "(null)";
		if (p1 >= 6)
			s = "      ";
	}

	while (s[l] != '\0')
		l++;

	if (p1 >= 0 && p1 < l)
		l = p1;

	if (w1 > l)
	{
		if (f1 & F_MINUS)
		{
			write(1, &s[0], l);
			for (x = w1 - l; x > 0; x--)
				write(1, " ", 1);
			return (w1);
		}
		else
		{
			for (x = w1 - l; x > 0; x--)
				write(1, " ", 1);
			write(1, &s[0], l);
			return (w1);
		}
	}

	return (write(1, s, l));
}
