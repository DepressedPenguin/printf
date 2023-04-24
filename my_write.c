#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include "main.h"
/**
 * my_write - fonction to push.
 *@c: char
 *Return: Number of chars printed.
 */
int my_write(char c)
{
return (write(1, &c, 1));
}
/**
 * write_string - hgzgh  ghgd dff
 *@str : strg intg
 *Return: back to zero
 */
int write_string(const char *str)
{
int len = 0;
if (str == NULL)
{
return (-1);
}
while (*str)
{
len += my_write(*str);
str++;
}
return (len);
}
