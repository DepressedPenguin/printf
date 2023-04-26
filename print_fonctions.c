#include "main.h"
/**
 * print_b - fonction to entry.
 * @args: agruments
 * Return: number of characters
 */
int print_b(va_list args)
{
unsigned int n, m, i, sum;
unsigned int a[32];
int len;
n = va_arg(args, unsigned int);
m = 2147483648;
a[0] = n / m;
for (i = 1; i < 32; i++)
{
m /= 2;
a[i] = (n / m) % 2;
}
for (i = 0, sum = 0, len = 0; i < 32; i++)
{
sum += a[i];
if (sum || i == 31)
{
my_write('0' + a[i]);
len++;
}
}
return (len);
}
