int _printf(const char *format, ...)
{
	va_list args;
	int lenPrint;
	if (format == NULL)
		return (-1);
	va_start(args, format);

    lenPrint= _print_all(format, args);
    va_end(args);
    return (lenPrint);
}
