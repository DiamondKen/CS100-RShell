#include "header/ROr.hpp"

bool ROr::execute()
{
    if (lhs->execute())
    {
        return true;
    }
    else
    {
        return rhs->execute();
    }
}