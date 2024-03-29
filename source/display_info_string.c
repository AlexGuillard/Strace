/*
** EPITECH PROJECT, 2023
** display fonction
** File description:
** display
*/

#include "strace.h"

static void handle_return_args(struct user_regs_struct *regs,
    syscall_t *system_call)
{
    switch (table[system_call->id].rax) {
    case VOID:
        printf(") = ?\n");
        break;
    case PVOID:
        printf(") = %p\n", regs->rax);
        break;
    default:
        printf(") = %i\n", system_call->rax);
        break;
    }
}

static void handle_all_args(struct user_regs_struct *regs,
    syscall_t *system_call, int i, int *pid)
{
    switch (i) {
    case 0:
        return handle_first_argument(regs, system_call, pid);
    case 1:
        return handle_second_argument(regs, system_call, pid);
    case 2:
        return handle_third_argument(regs, system_call, pid);
    case 3:
        return handle_fourth_argument(regs, system_call, pid);
    case 4:
        return handle_fifth_argument(regs, system_call, pid);
    case 5:
        return handle_sixth_argument(regs, system_call, pid);
    default:
        return;
    }
}

void display_info_string(struct user_regs_struct *regs,
    syscall_t *system_call, int *pid)
{
    if (strcmp(system_call->name, "?") == 0)
        return;
    printf("%s(", system_call->name);
    for (int i = 0; i < system_call->nb_arg; i++) {
        if (system_call->nb_arg >= 1)
            handle_all_args(regs, system_call, i, pid);
        if (i + 1 < system_call->nb_arg)
            printf(", ");
    }
    handle_return_args(regs, system_call);
}
