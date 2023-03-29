/*
** EPITECH PROJECT, 2023
** Unix_Programming
** File description:
** display_info_hexa
*/

#include "strace.h"

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
