/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_strcat_env.c
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat_env(char *dest, char *src)
{
    int	i = 0;
    int	j = 0;
    char *str = malloc(sizeof(str) * (my_strlen(dest) + my_strlen(src) + 1));

    while (dest[i] != 0) {
        str[i] = dest[i];
        i++;
    }
    while (src[j]) {
        str[i] = src[j];
        j++;
        i++;
    }
    str[i] = 0;
    return (str);
}
