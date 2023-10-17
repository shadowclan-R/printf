#include "main.h"
/**
 *  * print_hexa_up - Prints an unsigned number in upper hexadecimal notation
 *   * @types: Lista of arguments
 *    * @buffer: Buffer array to handle print
 *     * @f1:  Calculates active flags
 *      * @w1: get width
 *       * @p1: Precision specification
 *        * @s1: Size specifier
 *         * Return: Number of chars printed
 */
int print_hexa_up(va_list types, char buffer[],
			int f1, int w1, int p1, int s1)
{
		return (print_hexa(types, "0123456789ABCDEF", buffer,
							f1, 'X', w1, p1, s1));
}
