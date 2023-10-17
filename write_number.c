#include "main.h"
/**
 * write_number - Prints a string
 * @is_negative: Lista of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @f1:  Calculates active flags
 * @w1: get width.
 * @p1: precision specifier
 * @s1: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int is_negative, int ind, char buffer[],
	int f1, int w1, int p1, int s1)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(s1);

	if ((f1 & F_ZERO) && !(f1 & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (f1 & F_PLUS)
		extra_ch = '+';
	else if (f1 & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, f1, w1, p1,
		length, padd, extra_ch));
}
