#ifndef __RSEPARATOR_HPP__
#define __RSEPARATOR_HPP__

#include "RShellConn.hpp"

class RSeparator : public RShellConn
{
public:
    RSeparator(RShellBase *myLhs, RShellBase *myRhs) : RShellConn{myLhs, myRhs} {};
    // RSeparator(RShellBase *, RShellBase *);
    bool execute();
};

#endif // RSEPATRTOR_H