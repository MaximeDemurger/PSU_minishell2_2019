/*
** EPITECH PROJECT, 2019
** lib
** File description:
** libmy.h
*/

#ifndef LIBMY_H
#define LIBMY_H

#ifndef READ_SIZE
#define READ_SIZE 1024
#endif

#include "struct.h"

/* UTILS */
int my_str_isalpha_num(char const *str);
int my_strlen(char const *str);
int my_strncmp(char *dest, char *str, int i);
int tab_size(char **env);
void free_all(all_t *all);
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_printf(char const *str, ...);
char *my_strcat(char *dest, char *str);
char *my_strdup(char const *src);
char *my_strdup_own(char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy_n_take(char *dest, int n);
char **my_str_to_word_array(char const *str, char sep);
char *my_strcat_env(char *dest, char *src);
int my_puterror(char const *str, char const *str2);
int my_char_isalpha(char a);
char *get_next_line(int fd);
/* UTILS */

link_t *get_path(char *str);
char *line_formating(char *str);
int open_shell(char **env);
char **set_path(char **env, all_t *all);
int exec_prg(all_t *all);
char *tild_home(char **env);
char **set_env(all_t *all, char **env);
char **unset_env(all_t *all, char **env);
int print_env(all_t *all, char **env);
int my_cd(all_t *all, char **env);
int minishell(all_t *, char **env);


#endif /* LIBMY_H */
