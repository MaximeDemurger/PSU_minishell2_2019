/*
** EPITECH PROJECT, 2020
** char is alpha
** File description:
** car
*/

int my_char_isalpha(char a)
{
    if ((a < 'a' || a > 'z') || (a < 'A' || a > 'Z'))
        return 1;
    return 0;
}