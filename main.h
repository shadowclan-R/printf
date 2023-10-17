#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stadarg.h>

int _putchar(char c);
int _printf(const char *format, ...);

int print_int(va_list args);
int print_dec(va_list args);
int print_unsigned(va_list args);
int print_oct(va_list val);
int print_hex(va_list val)
int print_HEX(va_list val)

#endif
