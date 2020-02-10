#ifndef __RAND_H__
#define __RAND_H__

#include "RShellConn.hpp"

class RAnd : public RShellConn
{
public:
    // RAnd(RShellBase *lhs, RShellBase *rhs);
    bool execute();
    
};

#endif // RAND_H