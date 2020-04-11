/*
** EPITECH PROJECT, 2019
** my_str
** File description:
** 2018
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while ((s1[i] == s2[i]) && s2[i] && s1[i])
        i++;
    return (s1[i] - s2[i]);
}

int my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;

    while (i < n -1 && (s1[i] == s2[i]) && s2[i] && s1[i])
        i++;
    return (s1[i] - s2[i]);
}
