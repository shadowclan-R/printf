#include "main.h"

/**
 * print_str - a function that prints rot13 string
 * @types: List of arguments
 * @buffer: character variable buffer array to handle print
 * @f1: calculates flags
 * @w1: get width.
 * @p1: ineger precision specification
 * @s1: integer size specifier
 * Return: returns the rot13 string
 */
int print_rot13string(va_list types, char buffer[],
	int f1, int w1, int p1, int s1)
{
	char c;
	char *s;
	unsigned int x, y;
	int i = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(f1);
	UNUSED(w1);
	UNUSED(p1);
	UNUSED(s1);

	if (s == NULL)
		s = "(AHYY)";
	for (x = 0; s[x]; x++)
	{
		for (y = 0; in[y]; y++)
		{
			if (in[y] == s[x])
			{
				c = out[y];
				write(1, &c, 1);
				i++;
				break;
			}
		}
		if (!in[y])
		{
			c = s[x];
			write(1, &c, 1);
			i++;
		}
	}
	return (i);
}
