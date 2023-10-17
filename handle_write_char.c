#include "main.h"

/**
 * handle_write_char - a function that handle the string
 * @c: charcter variable
 * @buffer: character variable buffer array to handle print
 * @f1: calculates flags
 * @w1: get width.
 * @p1: ineger precision specification
 * @s1: integer size specifier
 * Return: returns the handle write char
 */
int handle_write_char(char c, char buffer[],
	int f1, int w1, int p1, int s1)
{
	int x = 0;
	char padd = ' ';

	UNUSED(p1);
	UNUSED(s1);

	if (f1 & F_ZERO)
		padd = '0';

	buffer[x++] = c;
	buffer[x] = '\0';

	if (w1 > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (x = 0; x < w1 - 1; x++)
			buffer[BUFF_SIZE - x - 2] = padd;

		if (f1 & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - x - 1], w1 - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - x - 1], w1 - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}
