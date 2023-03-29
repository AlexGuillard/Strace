/*
** EPITECH PROJECT, 2023
** Unix_Programming
** File description:
** core_command
*/

#include "strace.h"

#include <sys/ptrace.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/user.h>

static void exec_command(char **command)
{
    if (ptrace(PTRACE_TRACEME) == -1) {
        printf("error tracing\n");
        exit(84);
    }
    if (execvp(command[1], command) == -1) {
        printf("error execution\n");
        exit(84);
    }
    exit(0);
}

static int init_tracing(pid_t *child, int *text, struct user_regs_struct *regs)
{
    if (ptrace(PTRACE_GETREGS, *child, NULL, regs) == -1) {
        printf("error trace get_regs\n");
        return (84);
    }
    *text = ptrace(PTRACE_PEEKTEXT, *child, regs->rip, NULL);
    if (*text == -1) {
        printf("error trace text\n");
        return (84);
    }
    if (ptrace(PTRACE_SINGLESTEP, *child, NULL, 0) == -1) {
        printf("error trace single step\n");
        return (84);
    }
    return (0);
}

static int trace_command(pid_t *child, int *status)
{
    struct user_regs_struct regs;
    int text = 0;

    wait4(*child, status, 0, NULL);
    while (42) {
        init_tracing(child, &text, &regs);
        wait4(*child, status, 0, NULL);
        if (WIFSIGNALED(*status) || WIFEXITED(*status)) {
            printf("[%d -> %d] \n", *child, *status);
            break;
        }
    }
    return (0);
}

int core_command(char **command)
{
    pid_t child = 0;
    int status = 0;

    child = fork();
    if (child == -1)
        return (84);
    if (child == 0) {
        exec_command(command);
    } else {
        if (trace_command(&child, &status) == 84)
            return (84);
    }
    return (0);
}
