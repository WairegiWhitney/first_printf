#include "main.h"

/**
 * printf_int - printf function that Prints an integer.
 * @args: Argument to print.
 * Return: Number of characters printed.
 */
int printf_int(va_list my_args)
{
    int intr = va_arg(my_args, int);
    int numbr, ls = intr % 10, digit, exp = 1;
    int i = 1;

    intr /= 10;
    numbr = intr;

    
    if (ls < 0)
    {
        _putchar('-');
        numbr = -numbr;
        intr = -intr;
        ls = -ls;
        i++;
    }

    
    while (numbr / 10 != 0)
    {
        exp *= 10;
        numbr /= 10;
    }

    numbr = intr;

    
    while (exp > 0)
    {
        digit = numbr / exp;
        _putchar(digit + '0');
        numbr -= digit * exp;
        exp /= 10;
        i++;
    }

    
    _putchar(ls + '0');

    return (i);
}

