/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_cd.c
*/

#include <unistd.h>
#include <stdio.h>
#include "minishell.h"

int my_cd(all_t *all, char **env)
{
    if ((tab_size(all->rules) == 1) ||
    (all->rules[1][0] == '~' && all->rules[1][1] == '\0'))
        chdir(tild_home(env));
    else if (chdir(all->rules[1]) == -1) {
        my_puterror("cd: no such file or directory: ", all->rules[1]);
        my_putchar('\n');
    }
    all->exe = 0;
    return (0);
}