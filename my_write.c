#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include "main.h"
/**
 * my_write - writes a character to standard output
 * @c: the character to write
 *
 * Return: the number of bytes written (1) on success, or -1 on failure
 */
int my_write(char c)
{
    if (write(1, &c, 1) != 1) {
        return -1;
    }
    return 1;
}

/**
 * write_string - writes a null-terminated string to standard output
 * @str: the string to write
 *
 * Return: the number of bytes written on success, or -1 on failure
 */
int write_string(const char *str)
{
    if (str == NULL) {
        return -1;
    }

    size_t len = 0;
    while (*str != '\0') {
        if (my_write(*str) == -1) {
            return -1;
        }
        str++;
        len++;
    }

    return len;
}
