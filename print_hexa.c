#include "main.h"

/**
 * print_hexa - a function that prints the hexadecimal
 * @types: List of arguments
 * @map_to: character variable array
 * @buffer: character variable buffer array to handle print
 * @f1: calculates flags
 * @flag_ch: character variable
 * @w1: get width.
 * @p1: ineger precision specification
 * @s1: integer size specifier
 * Return: returns the print hexadecimal
 */
int print_hexa(va_list types, char map_to[], char buffer[],
			int f1, char flag_ch, int w1, int p1, int s1)
{
	int x = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int init_num = number;

	UNUSED(w1);

	number = convert_size_unsign(number, s1);

	if (number == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[x--] = map_to[number % 16];
		number /= 16;
	}

	if (f1 & F_HASH && init_num != 0)
	{
		buffer[x--] = flag_ch;
		buffer[x--] = '0';
	}

	x++;

	return (write_unsign(0, x, buffer, f1, w1, p1, s1));
}
