/*
** EPITECH PROJECT, 2020
** line separator 
** File description:
** line separator
*/

#include <stdlib.h>

int my_strlen_modif(char const *str)
{
    int i = 1;
    int j = 0;

    while (str[i] == ' ')
        i++;
    while (str[i + j])
        j++;
    return j;
}

char *str_modified(char *str)
{
    char *dest = malloc(sizeof(char) * (my_strlen_modif(str) + 1));
    int i = 1;
    int j = 0;

    while (str[i] == ' ')
        i++;
    while (str[i]) {
        dest[j++] = str[i++];
    }
    return dest;
}

char *line_separator(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[0] == ';')
            str = str_modified(str);
        i++;
    }
    return str;
}