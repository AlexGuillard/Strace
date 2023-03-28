/*
** EPITECH PROJECT, 2023
** gestion core
** File description:
** core
*/

#include "strace.h"

int detection_pid_pos(char **av)
{
    int pos_pid = 0;

    for (int i = 0; av[i]; i++)
        if (strcmp(av[i], "-p") == 0)
            pos_pid = i + 1;
    return pos_pid;
}

void detect_fonction(struct user_regs_struct regs)
{
    syscall_t system_call = {regs.orig_rax, "?", 6, regs.rax, regs.rdi,
    regs.rsi, regs.rdx, regs.rcx, regs.r8, regs.r9};

    for (int i = 0; table[i].id != -1; i++) {
        if (system_call.id == table[i].id) {
            system_call.name = strdup(table[i].name);
            system_call.nb_arg = table[i].nb_arg;
        }
    }
    display_info(system_call);
}

void handle_core_pid(char **av, bool s)
{
    struct user_regs_struct regs;
    int pos_pid = detection_pid_pos(av);
    int pid = atoi(av[pos_pid]);
    int status = 0;
    int text = 0;

    ptrace(PTRACE_ATTACH, pid, NULL, NULL);
    waitpid(pid, &status, 0);
    while (!WIFEXITED(status) && !WIFSIGNALED(status)) {
        ptrace(PTRACE_GETREGS, pid, NULL, &regs);
        ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
        text = ptrace(PTRACE_PEEKTEXT, pid, regs.rip, NULL);
        if ((text & 0xffff) == 0x050F) {
            ptrace(PTRACE_GETREGS, pid, NULL, &regs);
            ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
            detect_fonction(regs);
        }
    }
}
