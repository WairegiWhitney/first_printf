#include "main.h"

/**
 * _printf -Execution of the printf function
 * @format: The format string containing conversion specifiers
 * Return: The number of characters printed (excluding null byte)
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
            write(1, format, 1);
            print_chars++;
        }
        else
        {
            format++;

            if (*format == '\0')
                break;

            if (*format == 'c') // if its a character
            {
                char A = va_arg(my_args, int);
                write(1, &A, 1);
                print_chars++;
            }
            else if (*format == 's') // if its a string 
            {
                char *s = va_arg(my_args, char *);
                int s_len = 0;

                while (s[s_len] != '\0')
                {
                    s_len++;
                }

                write(1, s, s_len);
                print_chars += s_len;
            }
            if (*format == '%') // if its a Percentage sign
            {
                write(1, s, s_len);
                print_chars += s_len;
            }
        }

        format++;
    }
    va_end(my_args);
    return print_chars;
}



