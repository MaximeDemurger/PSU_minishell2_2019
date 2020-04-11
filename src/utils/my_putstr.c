/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** display characters of a string
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_putstr(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 84;
    i = my_strlen(str);
    write(1, str, i);
    return (0);
}
