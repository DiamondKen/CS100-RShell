#ifndef __RSHELLCONN_HPP__
#define __RSHELLCONN_HPP__

using namespace std;

#include "RShellBase.hpp"

class RShellConn : public RShellBase
{
public:
    // RShellConn(){};
    RShellConn(RShellBase *myLhs, RShellBase *myRhs)
    {
        lhs = myLhs;
        rhs = myRhs;
    };

    // ~RShellConn(){};
    virtual bool execute() = 0;

protected:
    RShellBase *lhs;
    RShellBase *rhs;
};

#endif // RSHELLCONN_H