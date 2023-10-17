#include "main.h"
#include <ctype.h>

/**
 * get_w1 - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: w1.
 */
int get_w1(const char *format, int *i, va_list list)
{
	int k;
	int w1 = 0;

	for (k = *i + 1; format[k] != '\0'; k++)
	{
		if (isdigit(format[k]))
		{
			w1 *= 10;
			w1 += format[k] - '0';
		}
		else if (format[k] == '*')
		{
			k++;
			w1 = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = k - 1;

	return (w1);
}
