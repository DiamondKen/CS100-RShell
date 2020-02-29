#ifndef __RSHELLBASE_HPP__
#define __RSHELLBASE_HPP__

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