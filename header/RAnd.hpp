#ifndef __RAND_H__
#define __RAND_H__

#include "RShellConn.hpp"

class RAnd : public RShellConn
{
public:
    // RAnd(RShellBase *, RShellBase *);
    bool execute();
    
};

#endif // RAND_H