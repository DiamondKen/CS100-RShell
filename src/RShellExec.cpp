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
#include "../header/RExit.hpp"

bool RShellExec::execute()
{
    flagDivider();
    pid_t pid = fork();
    int status;

    if (pid == -1)
    {
        cout << "Error: command failed" << endl;
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        char *argv_list[flags.size() + 2];
        argv_list[0] = realCommand;
        for(int i = 1; i< flags.size() + 2; i++)
        {
            argv_list[i] = flags.front();
            flags.pop();
        }
        argv_list[flags.size() + 2] = NULL;
        execvp(argv_list[0], argv_list);
        exit(0);
    }

    waitpid(pid, &status, 0);
    if(strdup(realCommand) == "exit")
    {
        exit(0);
    }
}

void RShellExec::flagDivider()
{
    char *commandDupli = strdup(command);
    char *theFlag = strtok(commandDupli, " ");
    while (theFlag != NULL)
    {
        flags.push(theFlag);
        theFlag = strtok(NULL, " ");   
    }
    realCommand = flags.front();
    if(realCommand == "echo")
    {
        
    }
    flags.pop();
}