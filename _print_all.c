#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 * _print_all - Printf function
 * @format: format string
 * @args: variable arguments list
 *
 * Return: the number of characters printed, or -1 if an error occurred
 */

int _print_all(const char *format, va_list args)
{
int lenPrint = 0;
int i = 0;
char *str;
int number;
char buffer[12];
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
i++;
switch (format[i])
{
case 'c':
lenPrint += my_write(va_arg(args, int));
break;
number = va_arg(args, int);
sprintf(buffer, "%d", number );
lenPrint+= write_string(buffer);
break;
case 's':
str = va_arg(args, char *);
if (str == NULL)
lenPrint += write_string("(null)");
else
lenPrint += write_string(str);
break;
case '%':
lenPrint += my_write('%');
break;
case 'd':
case 'i':
lenPrint += print_integer(va_arg(args, int));
break;
default:
lenPrint += my_write('%');
lenPrint += my_write(format[i]);
break;
}
}
else
lenPrint += my_write(format[i]);
}
return (lenPrint);
}
