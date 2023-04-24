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
    char *str;
    int lenPrint = 0, i;

    if (format == NULL)
        return (-1);

    va_start(args, format);

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
                default:
                    lenPrint += my_write('%');
                    lenPrint += my_write(format[i]);
                    break;
            }
        }
        else
            lenPrint += my_write(format[i]);
    }

    va_end(args);

    return (lenPrint);
}

