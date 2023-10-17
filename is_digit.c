#include "main.h"

/**
 * is_digit - a function that verifies if a char is a digit
 * @c: character variable
 * Return: if c is a digit returns 1 otherwise 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
