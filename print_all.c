#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
/**
 * _printf - fonctiopn to printf
 *_print_all - print all fcs
 * @format : the format
 *@args : parametr
 *Return: Printed chars.
 */

int _print_all(const char *format, va_list args)
{
int i, prinLen = 0;
char *str;
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
i++;
switch (format[i])
{
case 'c':
printLen = my_write(va_arg(args, int));
break;
case 's':
str = (char *) va_arg(args, char *);
if (str == NULL)
return (0);
while (*str != 0)
{
printLen += my_write(*str);
str++;
}
break;
case '%':
printLen = my_write(format[i]);
break;
defult:
return  (-1);
}
}
	else
{
		if (format[i] == NULL)
{
			return (0);
}
while (format[i] != 0)
{
printLen += my_write(format([i]);
i++;
}
return (printLen);
}
}
va_end(args);
return (printlen);
}
