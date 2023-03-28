/*
** EPITECH PROJECT, 2023
** gestion core
** File description:
** core
*/

#include "strace.h"
#include "../include/syscall.h"

int detection_pid_pos(char **av)
{
    int pos_pid = 0;

    for (int i = 0; av[i]; i++)
        if (strcmp(av[i], "-p") == 0)
            pos_pid = i + 1;
    return pos_pid;
}

int get_number_arg(syscall_t system_call, int i)
{
    if (i == 1)
        return system_call.rdi;
    if (i == 2)
        return system_call.rsi;
    if (i == 3)
        return system_call.rdx;
    if (i == 4)
        return system_call.rcx;
    if (i == 5)
        return system_call.r8;
    if (i == 6)
        return system_call.r9;
    return 0;
}

void display_info(syscall_t system_call)
{
    printf("%s(", system_call.name);
    for (int i = 0; i < system_call.nb_arg; i++) {
        if (get_number_arg(system_call, i) != 0)
            printf("%#x", get_number_arg(system_call, i));
        if (i + 1 < system_call.nb_arg)
            printf(", ");
    }
    printf(") = %#x\n", system_call.rax);
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

void handle_core_command(char **av, bool s)
{

}
