/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_str_isalpha_num.c
*/

#include <stdlib.h>

int my_str_isalpha_num(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 84;
    while (str[i]) {
        if ((str[i] < '0') || (str[i] > '9') ||
            (str[i] < 'A') || (str[i] > 'Z') ||
            (str[i] < 'a') || (str[i] > 'z'))
            return -1;
        i++;
    }
    return 0;
}