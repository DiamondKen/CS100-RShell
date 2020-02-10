#include "header/RShellExec.hpp"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <iostream>

RShellExec::RShellExec(char *command)
{
    pid_t pid = fork();
    int status;

    if (pid == -1)
    {
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        char *argv_list[] = {command, NULL};
        execvp(argv_list[0], argv_list);
        exit(0);
    }

    waitpid(pid, &status, 0);
}