/*
** EPITECH PROJECT, 2023
** Strace
** File description:
** strace
*/

#include "strace.h"

int strace(int ac, char **av)
{
    bool s = false;
    bool p = false;

    if (option_handling(ac, av, &s, &p) == 84) {
        printf("%s: Error option\n", av[0]);
        return (84);
    }
    return (0);
}
