/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_cd.c
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/errno.h>
#include "minishell.h"

int my_cd(all_t *all, char **env)
{
    errno = 0;
    if ((tab_size(all->rules) == 1) ||
    (all->rules[1][0] == '~' && all->rules[1][1] == '\0'))
        chdir(tild_home(env));
    else if (chdir(all->rules[1]) == -1) {
        if (errno == EACCES) {
            my_putstr("error: Permission denied.\n");
            return 1;
        }
        if (errno == ENOENT) {
            my_putstr(all->rules[1]);
            my_putstr(": No such file or directory\n");
        }
        if (errno == ENOTDIR) {
            my_putstr(all->rules[1]);
            my_putstr(": Not a directory\n");
        }
    }
    all->exe = 0;
    return (0);
}