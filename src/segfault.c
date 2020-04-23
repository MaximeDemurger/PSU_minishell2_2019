/*
** EPITECH PROJECT, 2020
** segfault
** File description:
** segault
*/

#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int check_error(int status)
{
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == 8)
            my_putstr("Floating exception");
        else
            my_putstr(convert_to_string(WTERMSIG(status)));
        if (WCOREDUMP(status) == 0)
            my_putstr(" (core dumped)");
        write(1, "\n", 1);
        return 1;
    }
    return 0;
}