/*
** EPITECH PROJECT, 2023
** gestion core
** File description:
** core
*/

#include "strace.h"

static int detection_pid_pos(char **av)
{
    int pos_pid = 0;

    for (int i = 0; av[i]; i++)
        if (strcmp(av[i], "-p") == 0)
            pos_pid = i + 1;
    return pos_pid;
}

static void init_trace(int *pid, struct user_regs_struct *regs)
{
    if (ptrace(PTRACE_SETOPTIONS, *pid, NULL, PTRACE_O_TRACEEXIT) == -1) {
        printf("error trace exit\n");
        exit(84);
    }
    if (ptrace(PTRACE_GETREGS, pid, NULL, &regs) == -1)
        exit(84);
    if (ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL) == -1)
        exit(84);
}

void handle_core_pid(char **av, bool *s)
{
    struct user_regs_struct regs;
    int pos_pid = detection_pid_pos(av);
    int pid = atoi(av[pos_pid]);
    int status = 0;

    ptrace(PTRACE_ATTACH, pid, NULL, NULL);
    waitpid(pid, &status, 0);
    while (true) {
        init_trace(&pid, &regs);
        detect_fonction(&regs, s, &pid);
        waitpid(pid, &status, 0);
        if (WIFEXITED(status) || WIFSIGNALED(status)) {
            printf("+++ exited with %d +++\n", WEXITSTATUS(status));
            break;
        }
    }
}
