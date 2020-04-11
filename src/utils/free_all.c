/*
** EPITECH PROJECT, 2019
** free
** File description:
** all
*/

#include <stdlib.h>
#include "minishell.h"

void free_all(all_t *all)
{
    free(all->arr);
    free(all->user);
    free(all);
}
