/*
** EPITECH PROJECT, 2019
** main
** File description:
** main minishell
*/

#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"
#include <unistd.h>

int main(int ac, __attribute__((unused)) char **av, char **env)
{
    if (ac > 1)
        return (84);
    if (open_shell(env) == 0)
        return (0);
    return (0);
}
