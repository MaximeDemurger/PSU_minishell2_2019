/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** 2018
*/

#include <unistd.h>

int my_putchar(char c)
{
    if (!(write (1, &c, 1)))
        return 1;
    return 0;
}
