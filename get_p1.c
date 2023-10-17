#include "main.h"
#include <ctype.h>

/**
 * get_p1 - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: P1.
 */
int get_p1(const char *format, int *i, va_list list)
{
	int k = *i + 1;
	int p1 = -1;

	if (format[k] != '.')
		return (p1);

	p1 = 0;

	for (k += 1; format[k] != '\0'; k++)
	{
		if (isdigit(format[k]))
		{
			p1 *= 10;
			p1 += format[k] - '0';
		}
		else if (format[k] == '*')
		{
			k++;
			p1 = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = k - 1;

	return (p1);
}
