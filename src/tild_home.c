/*
** EPITECH PROJECT, 2019
** path exe
** File description:
** path exe
*/

#include <stdlib.h>
#include "minishell.h"

char *tild_home(char **env)
{
    char *str = NULL;
    int i = 0;

    while (env[i]) {
        if (my_strncmp(env[i], "HOME", 4) == 0)
            str = my_strcpy_n_take(env[i], 5);
        i++;
    }
    return (str);
}
