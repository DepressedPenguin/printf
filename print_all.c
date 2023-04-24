#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include "main.h"
/**
 * _print_all - fonctiopn to print all
 * _printf - fonctiopn to printf
 * @format : the format
 *@args : parametr
 *Return: Printed chars.
 */
int _print_all(const char *format, va_list args)
{
int i, printLen = 0;
char *str;
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
i++;
switch (format[i])
		{
	case 'c':
printLen += my_write(va_arg(args, int));
break;
case 's':
str = (char *) va_arg(args, char *);
printLen += write_string(str);
break;
case '%':
printLen += my_write(format[i]);
break;
default:
return (-1);
}
}
else
{
printLen += my_write(format[i]);
}
}
return (printLen);
}
