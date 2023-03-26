/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "strace.h"
#include <stdbool.h>

static void display_help_message(char **av)
{
    printf("USAGE: ");
    printf("%s", av[0]);
    printf(" [-s] [-p <pid>|<command>]\n");
}

int main(int ac, char **av)
{
    if (ac == 1) {
        printf("%s: No arguments\n", av[0]);
        return (84);
    }
    if (ac > 1 && strcmp(av[1], "--help") == 0) {
        display_help_message(av);
        return (0);
    }
    return (0);
}
