/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** set_env.c
*/

#include <stdlib.h>
#include <zconf.h>
#include <stdio.h>
#include "minishell.h"

char *choose_one(all_t *all)
{
    char *str = NULL;

    if (tab_size(all->rules) == 3) {
        str = malloc(sizeof(char) * (my_strlen(all->rules[1]) +
                                            my_strlen(all->rules[2]) + 2));
        if (str == NULL)
            return NULL;
        str = my_strcat_env(all->rules[1], "=");
        str = my_strcat_env(str, all->rules[2]);
    } else if (tab_size(all->rules) == 2) {
        str = malloc(sizeof(char) * (my_strlen(all->rules[1]) + 2));
        if (str == NULL)
            return NULL;
        str = my_strcat_env(all->rules[1], "=");
    }
    printf("%s\n", str);
    return str;
}

char **otherwise(all_t *all)
{
    int i = 0;
    int j = 0;
    char **new_env = malloc(sizeof(char *) * (tab_size(all->envcpy) + 2));

    while (all->envcpy[i]) {
        new_env[i] = my_strdup(all->envcpy[i]);
        i++;
    }
    new_env[i] = choose_one(all);
    new_env[i + 1] = NULL;
    return new_env;
}

char **set_env(all_t *all)
{
    char **new_env = NULL;
    int i = 0;

    if (tab_size(all->rules) > 3) {
        my_putstr("setenv: Too many arguments.\n");
    } else if (my_str_isalpha_num(all->rules[2]) < 0 &&
                all->rules[2][my_strlen(all->rules[2])] == '\n') {
        my_putstr("setenv: Variable name must contain "
                  "alphanumeric characters.\n");
    } else
        new_env = otherwise(all);
    return new_env;
}