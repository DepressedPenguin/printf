#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 * print_integer - Prints a signed integer to standard output
 * @n: The integer to print
 *
 * Return: The number of characters printed
 */
int print_integer(int n)
{
int len = 0;
if (n < 0)
{
len += my_write('-');
n = -n;
}
if (n / 10)
len += print_integer(n / 10);
len += my_write((n % 10) + '0');
return (len);
}

