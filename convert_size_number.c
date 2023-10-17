#include "main.h"

/**
 * convert_size_number - a function that casts the number to the specified size
 * @num: unsigned long integer variable number to be casted
 * @s1: integer variable number indicating the type to be casted
 * Return: return the casted value of num
 */
long int convert_size_number(long int num, int s1)
{
	if (s1 == S_LONG)
		return (num);
	else if (s1 == S_SHORT)
		return ((short)num);
	return ((int)num);
}
