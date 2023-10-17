#include "main.h"
/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @f1: Flags
 * @w1: width
 * @p1: Precision specifier
 * @length: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */
int write_num(int ind, char buffer[],
	int f1, int w1, int p1,
	int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (p1 == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && w1 == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (p1 == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' '; /* width is displayed with padding ' ' */
	if (p1 > 0 && p1 < length)
		padd = ' ';
	while (p1 > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (w1 > length)
	{
		for (i = 1; i < w1 - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (f1 & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(f1 & F_MINUS) && padd == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(f1 & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}
