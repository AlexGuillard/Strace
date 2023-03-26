/*
** EPITECH PROJECT, 2023
** Unix_Programming
** File description:
** strace
*/

#ifndef STRACE_H_
    #define STRACE_H_
    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>

// Function prototype
    int option_handling(int ac, char **av, bool *s, bool *p);
    int strace(int ac, char **av);

#endif /* !STRACE_H_ */
