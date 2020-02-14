#ifndef __RSHELLEXEC_H__
#define __RSHELLEXEC_H__

#include "RShellBase.hpp"
#include <queue>
#include <string>
#include <cstring>

using namespace std;

class RShellExec : public RShellBase
{
public:
    // RShellExec():;
    RShellExec(const char *myCommand)
    {
        command = strdup(myCommand);
    }
    virtual bool execute();
    void flagDivider();

protected:
    char *command;
    char *realCommand;
    queue<char *> flags;
};

#endif // __RSHELLEXEC_H__