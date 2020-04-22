/*
** EPITECH PROJECT, 2020
** segfault
** File description:
** segault
*/

#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"

int check_error(int status)
{
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) != 8)
            my_putstr(convert_to_string(WTERMSIG(status)));
        else
            my_putstr("Floating exception");
        if (WCOREDUMP(status))
            my_putstr(" (core dumped)");
        write(1, "\n", 1);
        return 1;
    }
    return 0;
}