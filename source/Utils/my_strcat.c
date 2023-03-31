/*
** EPITECH PROJECT, 2023
** Unix_Programming
** File description:
** my_strcat but spécific for this projet
*/

#include "strace.h"

char *my_strcat(char *first, char *second)
{
    char *buffer = NULL;
    int i = 0;

    buffer = malloc(sizeof(char) * (strlen(first) + strlen(second) + 2));
    if (buffer == NULL)
        return (NULL);
    for (; i != strlen(first); i++)
        buffer[i] = first[i];
    buffer[i] = ' ';
    i++;
    for (int a = 0; i <= (strlen(first) + strlen(second)); a++, i++)
        buffer[i] = second[a];
    buffer[i] = '\0';
    return (buffer);
}
