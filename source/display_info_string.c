/*
** EPITECH PROJECT, 2023
** display fonction
** File description:
** display
*/

#include "strace.h"

static void handle_all_args(struct user_regs_struct *regs,
    syscall_t *system_call, int i, int *pid)
{
    return;
}

void display_info_string(struct user_regs_struct *regs,
    syscall_t *system_call, int *pid)
{
    if (strcmp(system_call->name, "?") == 0)
        return;
    printf("%s(", system_call->name);
    for (int i = 0; i < system_call->nb_arg; i++) {
        if (system_call->nb_arg > 1)
            handle_all_args(regs, system_call, i, pid);
        if (i + 1 < system_call->nb_arg)
            printf(", ");
    }
    printf(") = %i\n", system_call->rax);
}
