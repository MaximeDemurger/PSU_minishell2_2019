/*
** EPITECH PROJECT, 2019
** revstr
** File description:
** revstr
*/

#include <fcntl.h>
#include <stddef.h>

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i = 0;
    int len = 0;
    char c;

    if (!str)
        return NULL;
    len = my_strlen(str) - 1;
    while (i < len) {
        c = str[i];
        str[i] = str[len];
        str[len] = c;
        i++;
        len--;
    }
    return str;
}
