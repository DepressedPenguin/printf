int _printf(const char *format, ...)
{
va_list_argsl;
int_lenP;
va_start(argsl, format);
if (!format)
	return (-1);
va_start(argsl, format);
lenp= _print_format(format, argsl);
va_end(args1);
return (lenP);
}

