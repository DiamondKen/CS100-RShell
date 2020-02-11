#ifndef __RSEPARATOR_H__
#define __RSEPARATOR_H__

#include "RShellConn.hpp"

class RSeparator : public RShellConn
{
public:
    RSeparator(RShellBase *myLhs, RShellBase *myRhs) : RShellConn{myLhs,myRhs}{};
    // RSeparator(RShellBase *, RShellBase *);
    bool execute();
};

#endif // RSEPATRTOR_H