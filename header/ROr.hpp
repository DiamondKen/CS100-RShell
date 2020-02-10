#ifndef __ROR_H__
#define __ROR_H__

#include "RShellConn.hpp"

class ROr : public RShellConn
{
public:
    // ROr(RShellBase *lhs, RShellBase *rhs);
    bool execute();
};

#endif // ROR_H