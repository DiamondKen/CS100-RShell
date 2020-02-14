#ifndef __REXIT_H__
#define __REXIT_H__

#include "RShellExec.hpp"

class RExit : public RShellExec
{
public:
    RExit();
    bool execute()
    {
        exit(0);
    };
};

#endif // REXIT_H