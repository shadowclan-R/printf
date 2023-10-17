#include "main.h"

void print_buffer(char buffer[], int *buf);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int f1, w1, p1, s1, buf = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buf++] = format[i];
			if (buf == BUFF_SIZE)
				print_buffer(buffer, &buf);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buf);
			f1 = get_f1(format, &i);
			w1 = get_w1(format, &i, list);
			p1 = get_p1(format, &i, list);
			s1 = get_s1(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				f1, w1, p1, s1);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buf);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buf: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buf)
{
	if (*buf > 0)
		write(1, &buffer[0], *buf);

	*buf = 0;
}

