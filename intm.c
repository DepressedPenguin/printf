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

int print_integer(va_list args)
{
int n;
int div;
int len;
unsigned int num;
n = va_arg(args, int);
div = 1;
len = 0;
if (n < 0)
{
len += my_write('-');
num = n * -1;
}
else
num = n;
for (; num / div > 9; )
div *= 10;
for (; div != 0; )
{
len += my_write('0' + num / div);
num %= div;
div /= 10;
}
return (len);
}
