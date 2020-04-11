/*
** EPITECH PROJECT, 2018
** display
** File description:
** display anything
*/

#include <stdarg.h>
#include "minishell.h"

int my_printf(char const *str, ...)
{
    va_list ap;
    int index = 0;

    va_start(ap, str);
    while (str[index] != '\0') {
        if (str[index] != '%')
            my_putchar(str[index]);
        else if (str[index] == '%') {
            index++;
            if (str[index] == 's')
                my_putstr(va_arg(ap, char *));
            else if (str[index] == 'c')
                my_putchar(va_arg(ap, int));
            if (str[index] == 'i' || str[index] == 'd')
                my_put_nbr(va_arg(ap, int));
        } index++;
    }
    va_end (ap);
    return (0);
}
