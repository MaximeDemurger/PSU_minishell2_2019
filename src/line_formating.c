/*
** EPITECH PROJECT, 2020
** line formating
** File description:
** line formating
*/

#include "stdlib.h"
#include "minishell.h"

char *my_strcpy_formating(char *str, int i)
{
    char *dest = malloc(sizeof(char) * (my_strlen(str) - i));
    int j = 0;

    while (str[i]) {
        dest[j++] = str[i++];
    }
    dest[j] = '\0';
    return dest;
}

int line_size(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != 0) {
        if ((str[i] == ' ' && str[i + 1] == ' ') ||
            (str[i] == '\t' && str[i + 1] == '\t'))
            i++;
        else {
            j++;
            i++;
        }
    }
    return j;
}

char *line_formating2(char *str)
{
    char *dest = malloc(sizeof(char) * (line_size(str) + 1));
    int i = 0;
    int j = 0;

    if (dest == NULL)
        return NULL;
    while (str[i]) {
        if ((str[i] == ' ' && str[i + 1] == ' ') ||
            (str[i] == '\t' && str[i + 1] == '\t'))
            i++;
        else {
            dest[j] = str[i];
            j++;
            i++;
        }
    }
    dest[j] = '\0';
    return dest;
}

char *line_formating(char *str)
{
    int i = 0;
    int first_char = 0;

    if (str[0] == ' ')
        first_char = 1;
    while (first_char == 1) {
        if (str[i] == ' ' || str[i] == '\t')
            i++;
        if (str[i] != ' ')
            first_char = 0;
    }
    str = my_strcpy_formating(str, i);
    str = line_formating2(str);
    return str;
}