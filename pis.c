#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>


int print_char(char c)
{
write(1, &c, sizeof(char));
return (1);
}

int print_str(const char *str)
{
int i;
if (str == NULL)
{
str = "(null)";
}
else
for (i = 0; str[i] != '\0'; i++)
{
print_char(str[i]);
}
return (i);
}
