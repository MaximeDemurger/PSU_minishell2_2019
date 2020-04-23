/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_cd.c
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/errno.h>
#include <stdlib.h>
#include "minishell.h"

int cd_less(char **env, int passed)
{
    int i = 0;
    char *str = NULL;

    if (passed == 0) {
        my_putstr(": No such file or directory.\n");
        return 0;
    }
    while (env[i]) {
        if (my_strncmp("OLDPWD", env[i], 6) == 0) {
            str = my_strcpy_n_take(env[i], 7);
        }
        i++;
    }
    chdir(str);
    return 0;
}

char *modify_old(char *oldpwd, char *oldenv, int size)
{
    int i = 0;
    int j = 0;
    char *str = NULL;

    str = malloc(sizeof(char) * (my_strlen(oldpwd) + size));
    while (oldenv[i]) {
        str[i] = oldenv[i];
        i++;
    }
    while (oldpwd[j]) {
        str[i] = oldpwd[j];
        j++;
        i++;
    }
    str[i] = '\0';
    return str;
}

char **modify_pwd(char **env)
{
    int i = 0;
    char *oldpwd = NULL;
    char curennt[1024];

    while (env[i]) {
        if (my_strncmp("PWD", env[i], 3) == 0) {
            oldpwd = my_strcpy_n_take(env[i], 4);
            getcwd(curennt, 1024);
            env[i] = modify_old(curennt, "PWD=", 4);
        }
        i++;
    }
    i = 0;
    while (env[i]) {
        if (my_strncmp("OLDPWD", env[i], 6) == 0) {
            free(env[i]);
            env[i] = modify_old(oldpwd, "OLDPWD=", 8);
        }
        i++;
    }
    return env;
}

int principal_cd(all_t *all, int *passed)
{
    int in = 0;

    if (chdir(all->rules[1]) == -1) {
        in = 1;
        if (errno == ENOENT) {
            my_putstr(all->rules[1]);
            my_putstr(": No such file or directory.\n");
        }
        if (errno == ENOTDIR) {
            my_putstr(all->rules[1]);
            my_putstr(": Not a directory.\n");
        }
        if (errno == EACCES)
            my_putstr("error: Permission denied.\n");
    }
    *passed = 1;
    return in;
}

int my_cd(all_t *all, char **env)
{
    errno = 0;
    int in = 0;
    static int passed = 0;

    if (all->rules[1][0] == '~' && all->rules[1][1] == '\0') {
        chdir(tild_home(env));
        passed = 1;
    } else if (all->rules[1][0] == '-' && all->rules[1][1] == '\0')
        cd_less(env, passed);
    else if (principal_cd(all, &passed) == 1)
        in = 1;
    if (in == 0)
        all->envcpy = modify_pwd(env);
    all->exe = 0;
    return (0);
}