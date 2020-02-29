#ifndef __ROR_HPP__
#define __ROR_HPP__

#include "RShellConn.hpp"

class ROr : public RShellConn
{
public:
    ROr(RShellBase *myLhs, RShellBase *myRhs) : RShellConn{myLhs, myRhs} {};
    // ROr(RShellBase *, RShellBase *);
    bool execute();
};

#endif // ROR_H