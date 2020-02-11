#include "../header/ROr.hpp"


// ROr::ROr(RShellBase *myLhs, RShellBase *myRhs)
// {
//     lhs = myLhs;
//     rhs = myRhs;
// }   

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