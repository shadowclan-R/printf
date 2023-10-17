#include "main.h"

/**
 * print_str - a function that prints ascii code in hexa
 * @types: List of arguments
 * @buffer: character variable buffer array to handle print
 * @f1: calculates flags
 * @w1: get width.
 * @p1: ineger precision specification
 * @s1: integer size specifier
 * Return: returns the print non printable
 */
int print_non_printable(va_list types, char buffer[],
	int f1, int w1, int p1, int s1)
{
	int x = 0, offset = 0;
	char *s = va_arg(types, char *);

	UNUSED(f1);
	UNUSED(w1);
	UNUSED(p1);
	UNUSED(s1);

	if (s == NULL)
		return (write(1, "(null)", 6));

	while (s[x] != '\0')
	{
		if (is_printable(s[x]))
			buffer[x + offset] = s[x];
		else
			offset += append_hexa_code(s[x], buffer, x + offset);

		x++;
	}

	buffer[x + offset] = '\0';

	return (write(1, buffer, x + offset));
}
