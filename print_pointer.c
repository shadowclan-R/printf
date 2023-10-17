#include "main.h"

/**
 * print_pointer - a function that prints a pointer
 * @types: List of arguments
 * @buffer: character variable buffer array to handle print
 * @f1: calculates flags
 * @w1: get width.
 * @p1: ineger precision specification
 * @s1: integer size specifier
 * Return: returns the pointer
 */
int print_pointer(va_list types, char buffer[],
	int f1, int w1, int p1, int s1)
{
	char c = 0, p = ' ';
	int ind = BUFF_SIZE - 2, len = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *ad = va_arg(types, void *);

	UNUSED(w1);
	UNUSED(s1);

	if (ad == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(p1);

	num_addrs = (unsigned long)ad;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		len++;
	}

	if ((f1 & F_ZERO) && !(f1 & F_MINUS))
		p = '0';
	if (f1 & F_PLUS)
		c = '+', len++;
	else if (f1 & F_SPACE)
		c = ' ', len++;

	ind++;

	return (write_pointer(buffer, ind, len,
		w1, f1, p, c, padd_start));
}
