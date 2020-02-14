#include "../header/RAnd.hpp"

// RAnd::RAnd(RShellBase *myLhs, RShellBase *myRhs)
// {
//     lhs = myLhs;
//     rhs = myRhs;
// }

bool RAnd::execute()
{
    if (lhs->execute())
    {
        return rhs->execute();
    }
    else
    {
        return false;
    }
}
