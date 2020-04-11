/*
** EPITECH PROJECT, 2018
** my_strncpy
** File description:
** my_strncpyy_2018
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy_n_take(char *src, int n)
{
    char *str = malloc(sizeof(char) * 50);
    int i = 0;

    while (src[n]) {
        str[i] = src[n];
        n++;
        i++;
    }
    str[i] = '\0';
    return (str);
}