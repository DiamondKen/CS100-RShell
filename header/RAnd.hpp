#ifndef __RAND_H__
#define __RAND_H__

#include "RShellConn.hpp"

class RShellConn;
class RAnd : public RShellConn
{
public:
    RAnd(RShellBase *myLhs, RShellBase *myRhs) : RShellConn{myLhs, myRhs} {} ;
    // RAnd(RShellBase *, RShellBase *);
    bool execute();
};

#endif // RAND_H