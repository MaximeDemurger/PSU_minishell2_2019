/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_strdup.c
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup_own(char const *src)
{
    char *dest = NULL;
    int i = 0;
    int j = 0;

    if (src == NULL)
        return NULL;
    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (dest == NULL)
        return NULL;
    if (src[0] == ' ')
        i = 1;
    while (src[i] != 0) {
        dest[j] = src[i];
        i++;
        j++;
    }
    if (dest[j - 1] == ' ')
        dest[j - 1] = '\0';
    else
        dest[j] = '\0';
    return dest;
}

char *my_strdup(char const *src)
{
    char *dest = NULL;
    int i = 0;

    if (src == NULL)
        return NULL;
    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (dest == NULL)
        return NULL;
    while (src[i] != 0) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}