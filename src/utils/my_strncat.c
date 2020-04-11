/*
** EPITECH PROJECT, 2018
** my_strncat
** File description:
** 2018
*/

int my_strlen(char const *str)
{
    int i;

    i = 0;
    while (str [i] != '\0')
        i++;
    return (i);
}

char *my_strncat(char *dest, char *src, int nb)
{
    int len;
    int i;

    len = my_strlen(dest);
    i = 0;
    while (i < nb && src[i]) {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    return (dest);
}