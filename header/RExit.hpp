#ifndef __REXIT_H__
#define __REXIT_H__

#include "RShellExec.hpp"

class RExit : public RShellExec
{
public:
    RExit();
    bool execute();
};

#endif // REXIT_H