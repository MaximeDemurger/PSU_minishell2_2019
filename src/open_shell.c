/*
** EPITECH PROJECT, 2020
** open shell
** File description:
** function
*/

#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"
#include "gnl.h"
#include <unistd.h>
#include <signal.h>

int cmd_check2(all_t *all)
{
    if (my_strncmp("setenv", all->rules[0], 3) == 0)
        all->envcpy = set_env(all, all->envcpy);
    else if (my_strncmp("unsetenv", all->rules[0], 3) == 0)
        all->envcpy = unset_env(all, all->envcpy);
    else
        minishell(all, all->envcpy);
    return 0;
}

int cmd_check(all_t *all)
{
    int k = 0;

    if (my_strncmp("cd", all->rules[0], 2) == 0)
        my_cd(all, all->envcpy);
    if (my_strncmp("exit", all->rules[0], 4) == 0) {
        my_putstr("exit\n");
        exit(0);
    }
    if (my_strncmp("env", all->rules[0], 3) == 0)
        print_env(all, all->envcpy);
    cmd_check2(all);
    return (0);
}

int get_command_from_list(all_t *all)
{
    link_t *list = NULL;

    list = get_path(all->exe);
    free(all->exe);
    while (list) {
        all->exe = my_strdup(list->str);
        all->rules = my_str_to_word_array(all->exe, ' ');
        if (cmd_check(all) == 1)
            return 1;
        list = list->next;
        free(all->exe);
    }
    return 0;
}

int open_shell(char **env)
{
    all_t *all = malloc(sizeof(all_t));

    if (env[0] == NULL || !all)
        return 84;
    all->envcpy = set_path(env, all);
    while (1) {
        if (isatty(STDIN_FILENO) == 1)
            write(1, "$> ", 3);
        if ((all->exe = get_next_line(0)) == NULL)
            return 0;
        if (get_command_from_list(all) == 1)
            return 0;
        while (*all->rules)
            free(*all->rules++);
        free(all->exe);
    }
}