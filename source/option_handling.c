/*
** EPITECH PROJECT, 2023
** Unix_Programming
** File description:
** option_handling
*/

#include "strace.h"

void options_finder(char **av, bool *s, bool *p, int *option_nb)
{
    for (int a = 0; av[a] != NULL; a++) {
        if (strcmp(av[a], "-s") == 0) {
            *s = true;
        }
        if (strcmp(av[a], "-p") == 0) {
            *p = true;
        }
    }
    if (*s == true)
        *option_nb = *option_nb + 1;
    if (*p == true)
        *option_nb = *option_nb + 1;
}

int pid_checker(char **av)
{
    return (0);
}

int option_handling(int ac, char **av, bool *s, bool *p)
{
    int option_nb = 1;

    options_finder(av, s, p, &option_nb);
    if ((ac - 1) != option_nb)
        return (84);
    if (*p == true) {
        if (pid_checker(av) == 84)
            return (84);
    }
    return (0);
}
