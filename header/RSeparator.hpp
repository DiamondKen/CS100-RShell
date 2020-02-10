#ifndef __RSEPARATOR_H__
#define __RSEPARATOR_H__

#include "RShellConn.hpp"

class RSeparator : public RShellConn
{
public:
    // RSeparator(RShellBase *lhs, RShellBase *rhs);
    bool execute();
};

#endif // RSEPATRTOR_H