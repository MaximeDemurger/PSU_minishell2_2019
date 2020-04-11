/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** struct.h
*/

#ifndef PSU_MINISHELL1_2019_STRUCT_H
#define PSU_MINISHELL1_2019_STRUCT_H

typedef struct s_all
{
    char **envcpy;
    char *user;
    char *path_exe;
    char **rules;
    char *exe;
    char **arr;
}all_t;

typedef struct link_s {
    char *str;
    struct link_s *next;
} link_t;

#endif //PSU_MINISHELL1_2019_STRUCT_H
