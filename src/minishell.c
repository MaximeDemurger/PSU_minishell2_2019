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
#include <errno.h>
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
        if (errno == EACCES) {
            my_putstr(all->rules[0]);
            my_putstr(": Permission denied.\n");
        } else if (errno == 8) {
            my_putstr(all->rules[0]);
            my_putstr(": Exec format error. Wrong Architecture.\n");
        }
        return 1;
    }
    return 0;
}

int exec_prg(all_t *all)
{
    if (my_strncmp(all->exe, "./", 2) == 0) {
        all->rules[0] = without_exec(all->rules[0]);
        if (execve(all->rules[0], all->rules, all->envcpy) == -1) {
            if (errno == EACCES) {
                my_putchar('./');
                my_putstr(all->rules[0]);
                my_putstr(": Permission denied.\n");
            } else if (errno == 8) {
                my_putchar('./');
                my_putstr(all->rules[0]);
                my_putstr(": Exec format error. Wrong Architecture.\n");
            }
            return 1;
        }
        return (0);
    }
    return 0;
}

int execve_function(all_t *all)
{
    int i = 0;

    while (all->arr[i] != 0) {
        all->path_exe = my_strcat(all->arr[i], all->rules[0]);
        if (exe_right(all, i) == 1 || exec_prg(all) == 1) {
            return 1;
        }
        free(all->path_exe);
        i++;
    }
    my_putstr(all->exe);
    my_putstr(": Command not found.\n");
    all->exe = 0;
    return 0;
}

int minishell(all_t *all)
{
    int returned = 0;
    int wstatus = 0;
    pid_t pid = fork();

    if (pid == 0) {
        returned = execve_function(all);
        if (returned == 0)
            exit(0);
        else
            exit(1);
    } else {
        pid = waitpid(pid, &wstatus, 0);
        if (check_error(wstatus) == 1)
            return 1;
    }
    all->exe = 0;
    return 0;
}
