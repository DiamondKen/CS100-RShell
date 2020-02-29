#ifndef __REXIT_HPP__
#define __REXIT_HPP__

#include "RShellExec.hpp"

class RExit : public RShellExec
{
public:
    RExit() : RShellExec("exit(0)"){};
    bool execute()
    {
        exit(0);
        return false;
    };
};

#endif // REXIT_H