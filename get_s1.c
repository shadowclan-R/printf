#include "main.h"

/**
 * get_s1 - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: s1.
 */
int get_s1(const char *format, int *i)
{
	int k = *i + 1;
	int s1 = 0;

	if (format[k] == 'l')
		s1 = S_LONG;
	else if (format[k] == 'h')
		s1 = S_SHORT;

	if (s1 == 0)
		*i = k - 1;
	else
		*i = k;

	return (s1);
}
