#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
/**
 * _print_all - fonctiopn to print all
 * _printf - fonctiopn to printf
 * @format : the format
 *@args : parametr
 *Return: Printed chars.
 */
int _print_all(const char *format, va_list args)
{
int printLen = 0;
for (; *format; ++format)
{
if (*format == '%')
{
switch (*++format)
{
case 'c':
	printLen += my_write(va_arg(args, int));
break;
case 's':
{
const char *str = va_arg(args, const char *);
if (!str)
return (-1);
while (*str)
	printLen += my_write(*str++);
}
break;
case '%':
printLen += my_write('%');
break;
default:
return (-1);
}
}
else
{
printLen += my_write(*format);
}
}
va_end(args);
return (printLen);
}
