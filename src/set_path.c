/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** set_path.c
*/

#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>

char **set_path(char **env, all_t *all)
{
    int i = 0;
    char **new_env = malloc(sizeof(char *) * (tab_size(env) + 1));

    while (env[i] != NULL) {
        if (my_strncmp(env[i], "PATH", 4) == 0)
            all->arr = my_str_to_word_array(env[i], ':');
        new_env[i] = my_strdup(env[i]);
        i++;
    }
    new_env[i] = NULL;
    return new_env;
}