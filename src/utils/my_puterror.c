/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_puterror.c
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_puterror(char const *str, char const *str2)
{
    int i = 0;

    if (str == NULL)
        return 84;
    i = my_strlen(str);
    if (!write(2, str, i))
        return 84;
    i = my_strlen(str2);
    if (!write(2, str2, i))
        return 84;
    return (0);
}