/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** tab_size.c
*/

#include <stdlib.h>

int tab_size(char **env)
{
    int i = 0;

    while (env[i] != NULL)
        i++;
    return i;
}