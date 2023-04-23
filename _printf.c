#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
/**
 * _printf - Printf function
 * va_list: args
 * Return: the number of characters printed, or -1 if an error occurred
 *_print_all - fonction to print
 *@format: not null
 *
 */
int _printf(const char *format, ...)
{
va_list args;
int lenPrint;

if (format == NULL)
return (-1);
va_start(args, format);
lenPrint = _print_all(format, args);
va_end(args);
return (lenPrint);
}
