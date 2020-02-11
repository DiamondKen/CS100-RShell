#ifndef __ROR_H__
#define __ROR_H__

#include "RShellConn.hpp"

class ROr : public RShellConn
{
public:
    // ROr(RShellBase *, RShellBase *);
    bool execute();
};

#endif // ROR_H