/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** 2018
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char *src)
{
    int	i = 0;
    int	j = 0;
    char *str = malloc(sizeof(str) * (my_strlen(dest) + my_strlen(src) + 1));

    while (dest[i] != 0) {
        str[i] = dest[i];
        i++;
    }
    str[i++] = '/';
    while (src[j] != 0)
        str[i++] = src[j++];
    str[i] = 0;
    return (str);
}
