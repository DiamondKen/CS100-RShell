#ifndef __RSHELLCONN_H__
#define __RSHELLCONN_H__

using namespace std;

#include "RShellBase.hpp"

class RShellConn : public RShellBase
{
public:
    RShellConn(){};
    RShellConn(RShellBase *, RShellBase *);
    // ~RShellConn(){};
    virtual bool execute();

protected:
    RShellBase *lhs;
    RShellBase *rhs;
};

#endif // RSHELLCONN_H