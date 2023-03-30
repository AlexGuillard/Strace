/*
** EPITECH PROJECT, 2023
** Strace
** File description:
** strace
*/

#include "strace.h"

static char **get_command(char **av)
{
    int a = 1;
    char *buffer = "";
    char *temp = NULL;
    char **array = NULL;

    if (strcmp(av[1], "-s") == 0)
        a++;
    for (; av[a] != NULL; a++) {
        if (strcmp(av[a], "-s") == 0)
            break;
        temp = my_strcat(buffer, av[a]);
        if (strcmp(buffer, "") != 0) {
            free(buffer);
        }
        buffer = strdup(temp);
        free(temp);
    }
    array = my_str_to_word_array(buffer);
    free(buffer);
    return (array);
}

int strace(int ac, char **av)
{
    bool s = false;
    bool p = false;
    char **command = get_command(av);

    if (option_handling(ac, av, &s, &p) == 84) {
        printf("%s: Error option\n", av[0]);
        return (84);
    }
    if (p == true) {
        handle_core_pid(av, &s);
    } else {
        if (core_command(command, &s) == 84)
            return (84);
    }
    return (0);
}
