---

# ALX Software Engineering Programme: Printf Project

## Overview

This project introduces a programme written in the C programming language for structured output conversion. Developed as an important component of the low-level programming and algorithm track at ALX Software Engineering Programme, this software emulates the behavior of the C standard library function, `printf`.

## Dependencies

The `_printf` function was meticulously crafted and tested on an Ubuntu 20.04.1 LTS machine, utilizing `gcc` version 9.4.0.

## Usage

To seamlessly employ the `_printf` function, provided that the dependencies mentioned above have been installed, follow these steps:

1. Compile all `.c` files in the repository.
2. Include the `main.h` header file in your C program.
3. Create your program's `main` function.

Example `main.c`:

```
#include "main.h"

int main(void)
{
    _printf("Printf, C-Project!");

    return (0);
    }
    ```

To compile the program:

```
$ gcc *.c -o your_program_name
```

To execute your program:

```
$ ./a.out
```

Example Output:

```
Printf, C-Project!
```

## Description

Based on a 'format' string, the '_printf' function outputs output to the standard output stream. This format string specifies how the following parameters are processed for output.

**Prototype:** `int _printf(const char *format, ...);`

### Return Value

Upon successful execution, `_printf` returns the count of characters printed, excluding the null byte used to terminate output to strings. In the case of an output error, the function returns `-1`.

### The Argument String's Format

The 'format' string is a string of characters that can include one or more directives. Characters not followed by '%' are transferred to the output stream exactly as they are. Conversion requirements are preceded by the symbol '%' and followed by a conversion specifier. There may be zero or more flags, an optional minimum field width, an optional accuracy, and an optional length modifier between '%' and the conversion specifier. Arguments must match the conversion specifier and are handled in the order in which they occur.

#### Specifiers for Conversion

The conversion specifier, which begins with '%', specifies the type of conversion to be performed. The following conversion specifiers are supported by the '_printf' function:

- `%d`, `%i`: Format an `int` argument as a signed decimal or integer.

Example:

```
int main(void)
{
    _printf("%d\n", 15);
    }
    ```

Output:

```
15
```

- `%b`: Format an `unsigned int` argument as an unsigned decimal.

Example:

```
int main(void)
{
    _printf("%b\n", 7);
    }
    ```

Output:

```
111
```

- `%o`, `%u`, `%x`, `%X`: Format an `unsigned int` argument as octal (`%o`), decimal (`%u`), or hexadecimal (`%x` or `%X`) representations without sign. For `%x`, lowercase letters `abcdef` are used, while `%X` employs uppercase `ABCDEF`.

Example:

```
int main(void)
{
    _printf("%o\n", 77);
    }
    ```

Output:

```
115
```

- `%c`: Format an `int` argument as an `unsigned char`.

Example:

```
int main(void)
{
    _printf("%c\n", 48);
    }
    ```

Output:

```
0
```

- `%s`: Format a `const char *` argument as a string.

Example:

```
int main(void)
{
    _printf("%s\n", "Printf, C-Project!");
    }
    ```

Output:

```
Printf, C-Project!
```

- `%r`: Similar to `%s`, but reverses the string.

Example:

```
int main(void)
{
    _printf("%r\n", "Hello, World");
    }
    ```

Output:

```
dlroW ,olleH
```

- `%R`: Format a `const char *` argument as ROT13 encoded.

Example:

```
int main(void)
{
    _printf("%R\n", "Hello, World");
    }
    ```

Output:

```
Uryyb, Jbeyq
```

- `%p`: Format a pointer argument to output its memory address in hexadecimal format, preceded by `0x`.

Example:

```
int main(void)
{
    char *str = "Hello, World";
        _printf("%p\n", (void *)str);
	}
	```

Output:

```
0x561a6d7bab5d
```

- `%%`: Outputs the character `%`. No argument is transformed.

Example:

```
int main(void)
{
    _printf("%%\n");
    }
    ```

Output:

```
%
```

#### Flags

The following flags can be applied:

- `+`: Forces a plus or minus sign (`+` or `-`) to precede the result for positive numbers. By default, only negative numbers are prefixed with `-`.

- `(space)`: Inserts a blank space before the value if no sign is present.

- `#`: With `o`, `x`, or `X` specifiers, it prefixes the value with `0`, `0x`, or `0X`, respectively, for non-zero values. With `e`, `E`, or `f` specifiers, it ensures that the output contains a decimal point even if no digits follow. For `g` or `G`, it behaves like `e` or `E`, but it does not remove trailing zeros.

## conclusion

This revised README provides a more polished and professional presentation of the `printf` project, making it easier for users and developers to understand and utilize the `_printf` function. If you have any further questions or require additional assistance, please feel free to ask.
