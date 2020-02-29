#ifndef __RSHELLEXEC_HPP__
#define __RSHELLEXEC_HPP__

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
    bool testFileDir(char *, char *);
    char *getRealCommand() { return realCommand; };
    queue<char *> getFlags() { return flags; };

protected:
    char *command;
    char *realCommand;
    queue<char *> flags;
};

#endif // __RSHELLEXEC_H__