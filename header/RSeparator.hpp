#ifndef __RSEPARATOR_H__
#define __RSEPARATOR_H__

#include "RShellConn.hpp"

class RSeparator : public RShellConn
{
public:
    bool execute();
};

#endif // RSEPATRTOR_H