#ifndef __RSHELLBASE_H__
#define __RSHELLBASE_H__

// #include <iostream>
using namespace std;

class RShellBase
{
public:
    RShellBase();
    virtual bool execute() = 0;
};

#endif // __RSHELLBASE_H__