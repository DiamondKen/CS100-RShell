#ifndef __RAND_HPP__
#define __RAND_HPP__

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