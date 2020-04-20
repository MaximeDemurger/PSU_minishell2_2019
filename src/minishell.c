/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** 2018
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include "minishell.h"

char *without_exec(char *str)
{
    char *dest = NULL;
    int i = 0;
    int j = 2;

    if (str == NULL)
        return NULL;
    dest = malloc(sizeof(char) * (my_strlen(str) - 1));

    while (str[j] != '\0') {
        dest[i] = str[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    free(str);
    return dest;
}

int exe_right(all_t *all, int i)
{
    if ((execve(all->path_exe, all->rules, all->envcpy) > 0) && i == 6) {
        return 1;
    }
    return 0;
}

int exec_prg(all_t *all)
{
    if (my_strncmp(all->exe, "./", 2) == 0) {
        all->rules[0] = without_exec(all->rules[0]);
        if (execve(all->rules[0], all->rules, all->envcpy) < 0) {
            my_puterror("./", all->rules[0]);
            my_puterror(": ", "Permission denied.\n");
            return (1);
        }
        return (0);
    }
    return 0;
}

int minishell(all_t *all, char **env)
{
    int i = 0;

    if (fork() == 0) {
        while (all->arr[i] != 0) {
            all->path_exe = my_strcat(all->arr[i], all->rules[0]);
            if (exe_right(all, i) == 1 || exec_prg(all) == 1) {
                exit(1);
            }
            free(all->path_exe);
            i++;
        }
        my_puterror(all->exe, ": Command not found.\n");
        all->exe = 0;
        exit(0);
    } else {
        wait(NULL);
    }
    all->exe = 0;
    return 0;
}
