#include "main.h"
/**
 * _print_all - Printf function
 * @format: format string
 * @args: variable arguments list
 * Return: the number of characters printed, or -1 if an error occurred
 */
int _print_all(const char *format, va_list args)
{
int lenPrint = 0, i = 0;
char *str;
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
lenPrint += print_integer(args);
break;
case 'b':
lenPrint += print_b(args);
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
