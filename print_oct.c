#include "main.h"
/**
 *  * print_oct - Prints an unsigned number in octal notation
 *   * @types: Lista of arguments
 *    * @buffer: Buffer array to handle print
 *     * @f1:  Calculates active flags
 *      * @w1: get width
 *       * @p1: Precision specification
 *        * @s1: Size specifier
 *         * Return: Number of chars printed
 */
int print_oct(va_list types, char buffer[],
			int f1, int w1, int p1, int s1)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(w1);

	num = convert_size_unsign(num, s1);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
	buffer[i--] = (num % 8) + '0';
	num /= 8;
	}

	if (f1 & F_HASH && init_num != 0)
	buffer[i--] = '0';

	i++;

	return (write_unsign(0, i, buffer, f1, w1, p1, s1));
}
