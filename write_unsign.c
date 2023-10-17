#include "main.h"
/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @f1: Flags specifiers
 * @w1: Width specifier
 * @p1: Precision specifier
 * @s1: Size specifier
 *
 * Return: Number of written chars.
 */
int write_unsign(int is_negative, int ind,
	char buffer[],
	int f1, int w1, int p1, int s1)
{
	/* The number is stored at the bufer's right and starts at position i */
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(s1);

	if (p1 == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (p1 > 0 && p1 < length)
		padd = ' ';

	while (p1 > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((f1 & F_ZERO) && !(f1 & F_MINUS))
		padd = '0';

	if (w1 > length)
	{
		for (i = 0; i < w1 - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (f1 & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else /* Asign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

