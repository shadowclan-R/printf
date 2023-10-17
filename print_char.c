#include "main.h"
/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @f1:  Calculates active flags
 * @w1: Width
 * @p1: Precision specification
 * @s1: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
	int f1, int w1, int p1, int s1)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, f1, w1, p1, s1));
}
