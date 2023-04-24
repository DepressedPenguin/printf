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
	int i, lenPrint = 0;
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
					lenPrint += write_string(str);
					break;
				case '%':
					lenPrint += my_write('%');
					break;
				default:
					break;
			}
		}
		else
			lenPrint += my_write(format[i]);
	}

	return (lenPrint);
}
