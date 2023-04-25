#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

#define BUFFER_SIZE 50

int print_integer_to_buffer(va_list args, char result_buffer[], int flags, int width, int precision, int size)
{
int position = BUFFER_SIZE - 2;
int is_negative = 0;
unsigned int num_value = 0;

if (size == sizeof(char))
{
num_value = (char)va_arg(args, int);
}
else if (size == sizeof(short))
{
num_value = (short)va_arg(args, int);
}
else if (size == sizeof(int))
{
num_value = va_arg(args, int);
}
else if (size == sizeof(long))
{
num_value = va_arg(args, long);
}
if (num_value == 0)
{
result_buffer[position--] = '0';
}
else 
{
if (num_value < 0)
{
is_negative = 1;
num_value = -num_value;
}
for (long unsigned int num = num_value; num > 0; num /= 10)
{
result_buffer[position--] = (num % 10) + '0';
}
if (is_negative)
{
result_buffer[position--] = '-';
}
}
result_buffer[BUFFER_SIZE - 1] = '\0';
int digits_written = BUFFER_SIZE - position - 2;
int result = write_number(result_buffer + position + 1, flags, width, precision, digits_written);
return result;
}
