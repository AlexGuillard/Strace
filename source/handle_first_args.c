/*
** EPITECH PROJECT, 2023
** Unix_Programming
** File description:
** handle_first_args
*/

#include "strace.h"

void handle_first_argument(struct user_regs_struct *regs, int *pid)
{
    if (table[regs->orig_rax].rdi == STRING)
        handle_display_string(pid, regs->rdi);
    else
        printf("%lli", regs->rdi);
    return;
}

void handle_second_argument(struct user_regs_struct *regs, int *pid)
{
    if (table[regs->orig_rax].rsi == STRING)
        handle_display_string(pid, regs->rsi);
    else
        printf("%lli", regs->rsi);
    return;
}

void handle_third_argument(struct user_regs_struct *regs, int *pid)
{
    if (table[regs->orig_rax].rdx == STRING)
        handle_display_string(pid, regs->rdx);
    else
        printf("%lli", regs->rdx);
    return;
}
