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
    #include <stdlib.h>
    #include <signal.h>
    #include <unistd.h>
    #include <sys/ptrace.h>
    #include <sys/wait.h>
    #include <sys/user.h>

// Function prototype
    int option_handling(int ac, char **av, bool *s, bool *p);
    int strace(int ac, char **av);
    void handle_core_pid(char **av, bool s);
    void display_info(syscall_t system_call);

#endif /* !STRACE_H_ */
