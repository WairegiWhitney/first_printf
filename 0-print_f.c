#include "main.h"

/**
 * _printf -execution of printf function
 * @format: The format string
 * ...: Variable arguments
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    int print_chars = 0;
    va_list my_args;

    if (format == NULL)
    {
        return -1;
    }

    va_start(my_args, format);

    while (*format)
    {
        if (*format != '%')
        {
             putchar(*format);
            print_chars++;
        }
        else
        {
            format++;

            if (*format == '\0')
	    {
                break;
	    }

            if (*format == 'c')
            {
                char ch = va_arg(my_args, int);
                putchar(ch);
                print_chars++;
            }
            else if (*format == 's')
            {
                char *s = va_arg(my_args, char *);
                int str_len = 0;

                while (s[str_len] != '\0')
                {
                    str_len++;
                }

                putchar(*s);
                print_chars += str_len;
            }
            else if (*format == '%')
            {
                putchar('%');
                print_chars++;
            }
        }

        format++;
    }

    va_end(my_args);
    return print_chars;
}


