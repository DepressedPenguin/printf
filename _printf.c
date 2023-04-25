#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
/**
 * _printf - Printf function
 * @format: format string
 * @...: variable arguments list
 *
 * Return: the number of characters printed, or -1 if an error occurred
 */

int _printf(const char *format, ...)
{
va_list args;
int len;
if (!format || (format[0] == '%' && !format[1]))
return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
return (-1);
va_start(args, format);
len = _print_all(format, args);

va_end(args);
return (len);
}
