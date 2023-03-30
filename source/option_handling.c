/*
** EPITECH PROJECT, 2023
** Unix_Programming
** File description:
** option_handling
*/

#include "strace.h"

static void options_finder(char **av, bool *s, bool *p, int *option_nb)
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

static int kill_pid(char **av, int i)
{
    if (av[i + 1] == NULL || atoi(av[i + 1]) == 0)
        return (84);
    if (kill(atoi(av[i + 1]), 0) == 0)
        return (0);
    return (84);
}

static int pid_checker(char **av)
{
    int status = 0;

    for (int a = 0; av[a] != NULL; a++) {
        if (strcmp(av[a], "-p") == 0) {
            status = kill_pid(av, a);
            return (status);
        }
    }
    return (status);
}

int option_handling(int ac, char **av, bool *s, bool *p)
{
    int option_nb = 1;

    options_finder(av, s, p, &option_nb);
    if (*p == false)
        return (0);
    if ((ac - 1) != option_nb)
        return (84);
    if (*p == true) {
        if (pid_checker(av) == 84)
            return (84);
    }
    return (0);
}
