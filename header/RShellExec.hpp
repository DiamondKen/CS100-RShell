#ifndef __RSHELLEXEC_H__
#define __RSHELLEXEC_H__

#include "RShellBase.hpp"
#include <vector>
#include <string>

using namespace std;

class RShellExec : public RShellBase
{
public:
    RShellExec(char*);
    virtual bool execute();

private:
    vector<string> flags;
};

#endif // __RSHELLEXEC_H__