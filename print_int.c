#include "main.h"
/**
 * print_int - a function that print integer
 * @types: List of arguments
 * @buffer: character variable buffer array to handle print
 * @f1: calculates flags
 * @w1: get width.
 * @p1: ineger precision specification
 * @s1: integer size specifier
 * Return: Number of int printed
 */
int print_int(va_list types, char buffer[],
	int f1, int w1, int p1, int s1)
{
	int x = BUFF_SIZE - 2;
	int negative = 0;
	long int k = va_arg(types, long int);
	unsigned long int number;

	k = convert_size_number(k, s1);

	if (k == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)k;

	if (k < 0)
	{
		number = (unsigned long int)((-1) * k);
		negative = 1;
	}

	while (number > 0)
	{
		buffer[x--] = (number % 10) + '0';
		number /= 10;
	}

	x++;

	return (write_number(negative, x, buffer, f1, w1, p1, s1));
}
