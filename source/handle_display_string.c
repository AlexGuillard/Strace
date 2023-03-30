/*
** EPITECH PROJECT, 2023
** display string format
** File description:
** Handle_display_string
*/

#include "strace.h"

void loop_display_string(long addr_str, char *str)
{
    size_t n = 0;

    while (n != sizeof(addr_str)) {
        if (str[n] == '\n')
            write(1,"\\n", 2);
        else
            write(1, &str[n], 1);
        n++;
    }
    n = 0;
}

void handle_display_string(int *pid, long long int registre)
{
    long addr_str;
    char *str;

    addr_str = ptrace(PTRACE_PEEKTEXT, pid, registre, NULL);
    while (addr_str != -1) {
        str = (char *) &addr_str;
        fflush(stdout);
        loop_display_string(addr_str, str);
        if (memchr(&addr_str, '\0', sizeof(addr_str)) != NULL) {
            break;
        }
        registre += sizeof(addr_str);
        addr_str = ptrace(PTRACE_PEEKTEXT, pid, registre, NULL);
    }
}