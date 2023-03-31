/*
** EPITECH PROJECT, 2023
** Unix_Programming
** File description:
** handle_last_args
*/

#include "strace.h"

void handle_fourth_argument(struct user_regs_struct *regs,
    syscall_t *system_call, int *pid)
{
    if (table[system_call->id].rcx == STRING)
        handle_display_string(pid, regs->rcx);
    else
        printf("%lli", regs->rcx);
    return;
}

void handle_fifth_argument(struct user_regs_struct *regs,
    syscall_t *system_call, int *pid)
{
    if (table[system_call->id].r8 == STRING)
        handle_display_string(pid, regs->r8);
    else
        printf("%lli", regs->r8);
    return;
}

void handle_sixth_argument(struct user_regs_struct *regs,
    syscall_t *system_call, int *pid)
{
    if (table[system_call->id].r9 == STRING)
        handle_display_string(pid, regs->r9);
    else
        printf("%lli", regs->r9);
    return;
}
