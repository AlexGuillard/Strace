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

void detect_fonction(struct user_regs_struct *regs, bool s, int pid)
{
    syscall_t system_call = {regs->orig_rax, "?", 6, regs->rax, regs->rdi,
        regs->rsi, regs->rdx, regs->rcx, regs->r8, regs->r9};

    if (system_call.id >= 0 && system_call.id <= 328) {
        system_call.name = strdup(table[system_call.id].name);
        system_call.nb_arg = table[system_call.id].nb_arg;
    }
    if (s == true)
        display_info_string(regs, &system_call, pid);
    else
        display_info_hexa(&system_call);
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
    while (true) {
        if (ptrace(PTRACE_GETREGS, pid, NULL, &regs) == -1)
            exit(84);
        if (ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL) == -1)
            exit(84);
        detect_fonction(&regs, s, pid);
        waitpid(pid, &status, 0);
        if (WIFEXITED(status) || WIFSIGNALED(status))
            break;
    }
}
