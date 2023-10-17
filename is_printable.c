#include "main.h"

/**
 * is_printable - a function that evaluates if a char is printable
 * @c: character variable
 * Return: if c is printable returns 1 otherwise 0
 */
int is_printable(char c)
{

	if (c >= 32 && c < 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
