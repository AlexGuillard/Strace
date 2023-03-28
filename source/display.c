/*
** EPITECH PROJECT, 2023
** display fonction
** File description:
** display
*/

#include "strace.h"

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
