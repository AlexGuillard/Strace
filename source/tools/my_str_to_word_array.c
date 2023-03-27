/*
** EPITECH PROJECT, 2022
** my_str_to_word_array.c
** File description:
** function that splits a string into words with separator '\n'.
*/

#include <stdlib.h>
#include <stdbool.h>

static int check_alpha_char(char const *str, int i)
{
    if (str[i] != ' ' && str[i] != '\n') {
        return (1);
    }
    return (0);
}

static int calculate_nb_word(char const *str)
{
    int nb_word = 0;
    bool word = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (check_alpha_char(str, i) == 1) {
            word = true;
        }
        if ((check_alpha_char(str, i) == 0 && word == true) ||
            (str[i + 1] == '\0' && word == true)) {
            nb_word++;
            word = false;
        }
    }
    return (nb_word);
}

static char *stock_word(char const *str, int size_word, int i)
{
    char *str_word = NULL;

    if (check_alpha_char(str, i) == 1 && str[i + 1] == '\0')
        i++;
    str_word = malloc(sizeof(char) * (size_word + 1));
    if (str_word == NULL)
        return (NULL);
    str_word[size_word] = '\0';
    for (int a = 0; size_word > 0; size_word--, a++)
        str_word[a] = str[i - size_word];
    return (str_word);
}

static char **alloc_words(char const *str, char **array, int a)
{
    bool word = false;
    int size_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (check_alpha_char(str, i) == 1) {
            word = true;
            size_word++;
        }
        if ((check_alpha_char(str, i) == 0 && word == true) ||
            (str[i + 1] == '\0' && word == true)) {
            word = false;
            array[a] = stock_word(str, size_word, i);
            a = (array[a] == NULL) ? -2 : a;
            a++;
            size_word = 0;
        }
        if (a == -1)
            return (NULL);
    }
    return (array);
}

char **my_str_to_word_array(char const *str)
{
    char **array = NULL;

    array = malloc(sizeof(char*) * (calculate_nb_word(str) + 1));
    if (array == NULL)
        return (0);
    array[calculate_nb_word(str)] = NULL;
    array = alloc_words(str, array, 0);
    if (array == NULL)
        return (NULL);
    return (array);
}
