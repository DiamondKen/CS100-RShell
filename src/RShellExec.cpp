#include "../header/RShellExec.hpp"
#include "../header/RShellBase.hpp"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <iostream>
#include <string.h>

bool RShellExec::execute()
{
    pid_t pid = fork();
    int status;

    if (pid == -1)
    {
        cout << "Error: command failed" << endl;
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