/*
** EPITECH PROJECT, 2023
** Unix_Programming
** File description:
** detect_fonction
*/

#include "strace.h"

void detect_fonction(struct user_regs_struct *regs, bool *s, int *pid)
{
    syscall_t system_call = {regs->orig_rax, "?", 6, regs->rax, regs->rdi,
        regs->rsi, regs->rdx, regs->rcx, regs->r8, regs->r9};

    if (system_call.id >= 0 && system_call.id <= 328) {
        system_call.name = strdup(table[system_call.id].name);
        system_call.nb_arg = table[system_call.id].nb_arg;
    }
    if (*s == true)
        display_info_string(regs, &system_call, pid);
    else
        display_info_hexa(&system_call);
}
