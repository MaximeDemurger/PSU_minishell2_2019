/*
** EPITECH PROJECT, 2020
** linked list
** File description:
** linked list
*/

#include "minishell.h"
#include <stdlib.h>
#include <stddef.h>

link_t *my_rev_list(link_t *begin)
{
    link_t *tmp = 0;
    link_t *elem = begin;
    link_t *next;

    while (elem->next) {
        next = elem->next;
        elem->next = tmp;
        tmp = elem;
        elem = next;
    }
    elem->next = tmp;
    return elem;
}

int check_semicolon(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] == ';')
            return 0;
        i++;
    }
    return 1;
}

link_t *add_element(link_t *head, char *str)
{
    link_t *tmp = malloc(sizeof(link_t));

    if (!tmp)
        return NULL;
    tmp->str = my_strdup_own(str);
    tmp->next = head;
    return tmp;
}

link_t *add_tablist(char **tab)
{
    int i = 0;
    link_t *tmp = NULL;

    while (tab[i]) {
        tmp = add_element(tmp, tab[i]);
        i++;
    }
    return tmp;
}

link_t *get_path(char *str)
{
    link_t *head = NULL;
    char **tab = NULL;

    if (check_semicolon(str) == 0) {
        tab = my_str_to_word_array(str, ';');
        head = add_tablist(tab);
    } else
        head = add_element(head, str);
    return (my_rev_list(head));
}