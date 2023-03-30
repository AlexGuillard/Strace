/*
** EPITECH PROJECT, 2023
** Unix_Programming
** File description:
** display_info_hexa
*/

#include "strace.h"

static int get_number_arg(syscall_t *system_call, int i)
{
    switch (i) {
    case 0:
        return system_call->rdi;
    case 1:
        return system_call->rsi;
    case 2:
        return system_call->rdx;
    case 3:
        return system_call->rcx;
    case 4:
        return system_call->r8;
    case 5:
        return system_call->r9;
    default:
        return 0;
    }
}

void display_info_hexa(syscall_t *system_call)
{
    if (strcmp(system_call->name, "?") == 0)
        return;
    printf("%s(", system_call->name);
    for (int i = 0; i < system_call->nb_arg; i++) {
        if (system_call->nb_arg > 1)
            printf("%#x", get_number_arg(system_call, i));
        if (i + 1 < system_call->nb_arg)
            printf(", ");
    }
    printf(") = %#x\n", system_call->rax);
}
