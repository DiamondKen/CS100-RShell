#include "../header/RShellExec.hpp"
#include "../header/RShellBase.hpp"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
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
        int size = flags.size();
        char *argv_list[size + 2];
        argv_list[0] = realCommand;
        for (int i = 1; i < size + 2; i++)
        {
            argv_list[i] = flags.front();
            flags.pop();
        }
        argv_list[size + 1] = NULL;
        if (strcmp(realCommand,"exit") == 0)
        {
            exit(0);
        }
        execvp(argv_list[0], argv_list);
        cout << "Error: command failed" << endl;
        exit(-1);
    }

    waitpid(pid, &status, 0);
    int exitStatus = WEXITSTATUS(status);
    if(exitStatus == -1)
    {
        return false;
    }
    if (strcmp(realCommand,"exit") == 0)
    {
        exit(0);
    }
    if(strcmp(realCommand,"test") == 0)
    {
        if (this->execute() == false)
        {
            cout <<"(False)" << endl;
        }
        else
        {
            cout << "(True)" << endl;
        }

    }
}

void RShellExec::flagDivider()
{
    char *commandDupli = strdup(command);
    char *theFlag = strtok(commandDupli, " ");
    while (theFlag != NULL)
    {
        // if(theFlag[0] == '"')
        // {
        //     theFlag[0] = "";
        // }
        flags.push(theFlag);
        theFlag = strtok(NULL, " ");
    }
    realCommand = flags.front();
    flags.pop();
}

bool RShellExec::testFileDir()
{
    
}