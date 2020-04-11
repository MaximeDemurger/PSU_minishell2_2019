/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** unsetenv.c
*/

#include "minishell.h"
#include <stdlib.h>

int strlen_equal(char const *str)
{
    int i = 0;

    while (str[i] != '=')
        i++;
    return i;
}

int strcmp_unset(char const *check, char const *arg)
{
    int i = 0;
    char *without_equal = NULL;

    if (check == NULL)
        return 84;
    without_equal = malloc(sizeof(char) * (strlen_equal(check) + 1));
    while (check[i] != '=') {
        without_equal[i] = check[i];
        i++;
    }
    without_equal[i] = '\0';
    return (my_strcmp(without_equal, arg));
}

int find_line(all_t *all)
{
    int i = 0;

    while (all->envcpy[i]) {
        if (strcmp_unset(all->envcpy[i], all->rules[1]) == 0) {
            return i;
        }
        i++;
    }
    return (0);
}

char *in_loop(all_t *all, int *i, char **dest, int j)
{
    if ((strcmp_unset(all->envcpy[*i], all->rules[1]) == 0) &&
                                    (tab_size(all->envcpy) > *i))
        *i += 1;
    else if ((strcmp_unset(all->envcpy[*i], all->rules[1]) == 0) &&
             (tab_size(all->envcpy) == *i)) {
        dest[j] = NULL;
    } else
        dest[j] = my_strdup(all->envcpy[*i]);
    return dest[j];
}

char **unset_env(all_t *all, char **env)
{
    int i = 0;
    int j = 0;
    char **dest = NULL;

    if (find_line(all) == 0)
        return all->envcpy;
    dest = malloc(sizeof(char *) * (tab_size(all->envcpy)));
    while (all->envcpy[i]) {
        if ((dest[j] = in_loop(all, &i, dest, j)) == NULL)
            return dest;
        i++;
        j++;
    }
    dest[j] = NULL;
    return dest;
}