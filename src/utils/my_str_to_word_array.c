/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** emacs
*/

#include <stddef.h>
#include <stdlib.h>

int count_words(char const *str, char separator)
{
    int	i = 0;
    int	compt = 0;

    while (str[i] != '\0') {
        if (str[i] == separator && str[i + 1] != separator) {
            compt++;
        }
        i++;
    }
    compt++;
    return (compt);
}

char **malloc_line(char const *str, char separator)
{
    char **new = malloc(sizeof(char *) *
                        (count_words(str, separator) + 1));
    int	i = 0;
    int compteur = 0;
    int i_tab = 0;

    while (str[i] != '\0') {
        if (str[i] == separator && str[i + 1] != separator) {
            new[i_tab] = malloc(sizeof(char) *(compteur + 1));
            i_tab++;
            compteur = 0;
        } else
            compteur++;
        i++;
    }
    new[i_tab] = malloc(sizeof(char) *(compteur + 1));
    return (new);
}

char **my_str_to_word_array(char const *str, char separator)
{
    int index = 0;
    int ligne = 0;
    int caract = 0;
    char **tab = malloc_line(str, separator);

    while (str[index] != '\0') {
        if (str[index] == separator && str[index + 1] != separator) {
            tab[ligne][caract] = '\0';
            ligne++;
            caract = 0;
        } else {
            tab[ligne][caract] = str[index];
            caract++;
        }
        index++;
    }
    tab[ligne][caract] = '\0';
    ligne++;
    tab[ligne] = NULL;
    return (tab);
}
