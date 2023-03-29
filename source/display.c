/*
** EPITECH PROJECT, 2023
** display fonction
** File description:
** display
*/

#include "strace.h"

int get_number_arg(syscall_t *system_call, int i)
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

void display_arg_string(struct user_regs_struct *regs,
    syscall_t *system_call, int i, int pid)
{
    long addr_str;

    if (i == 0) {
        if (table[system_call->id].rdi == STRING) {
            printf("string: ");
        } else 
        printf("%i", system_call->rdi);
    }
    if (i == 1) {
        if (table[system_call->id].rsi == STRING) {
            printf("string: ");
        } else
            printf("%i", system_call->rsi);
    }
    if (i == 2) {
        if (table[system_call->id].rdx == STRING) {
            printf("string: ");
        } else
            printf("%i", system_call->rdx);
    }
    if (i == 3) {
        if (table[system_call->id].rcx == STRING) {
            printf("string: ");
        } else
            printf("%i", system_call->rcx);
    }
    if (i == 4) {
        if (table[system_call->id].r8 == STRING) {
            printf("string: ");
        } else
            printf("%i", system_call->r8);
    }
    if (i == 5) {
        if (table[system_call->id].r9 == STRING) {
            printf("string: ");
        } else
            printf("%i", system_call->r9);
    }
}

void display_info_string(struct user_regs_struct *regs,
    syscall_t *system_call, int pid)
{
    if (strcmp(system_call->name, "?") == 0)
        return;
    printf("%s(", system_call->name);
    for (int i = 0; i < system_call->nb_arg; i++) {
        if (system_call->nb_arg > 1)
            display_arg_string(regs, system_call, i, pid);
        if (i + 1 < system_call->nb_arg)
            printf(", ");
    }
    printf(") = %i\n", system_call->rax);
}
