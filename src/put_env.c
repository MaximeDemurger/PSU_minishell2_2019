/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** put_env.c
*/

#include "struct.h"
#include <stddef.h>

int my_printf(char *str, ...);

int print_env(all_t *all, char **env)
{
    int i = 0;

    while (all->envcpy[i] != NULL) {
        my_printf("%s\n", all->envcpy[i]);
        i++;
    }
    all->exe = 0;
    return (0);
}