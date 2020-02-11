#ifndef __RSHELLBASE_H__
#define __RSHELLBASE_H__

// #include <iostream>
using namespace std;

class RShellBase
{
public:
    RShellBase(){};
    virtual ~RShellBase(){};
    // RShellBase(char *);
    virtual bool execute() = 0;

// protected:
//     char *command;
};

#endif // __RSHELLBASE_H__