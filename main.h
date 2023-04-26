#ifndef main_h
#define main_h
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
int _print_all(const char *format, va_list args);
int _printf(const char *format, ...);
int my_write(char c);
int mywrite(char c);
int write_string(const char *str);
int print_integer(va_list args);
int print_b(va_list args);
#endif
