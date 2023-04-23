/**
 *my_write - fonction to push
 *@c: char
 *Return: Number of chars printed.
 */
int my_write(char c)
{
return (write(1, &c, 1));
}
