#include "main.h"

/**
 * print_unsign - a function that prints a unsigned number
 * @types: List of arguments
 * @buffer: character variable buffer array to handle print
 * @f1: calculates flags
 * @w1: get width.
 * @p1: ineger precision specification
 * @s1: integer size specifier
 * Return: returns the number of unsigned
 */
int print_unsign(va_list types, char buffer[],
			int f1, int w1, int p1, int s1)
{
	int x = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);

	number = convert_size_unsign(number, s1);

	if (number == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[x--] = (number % 10) + '0';
		number /= 10;
	}

	x++;

	return (write_unsign(0, x, buffer, f1, w1, p1, s1));
}
