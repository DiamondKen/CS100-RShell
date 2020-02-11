#include "../header/RSeparator.hpp"
#include "../header/RShellBase.hpp"

// RSeparator::RSeparator(RShellBase *myLhs, RShellBase *myRhs)
// {
//     lhs = myLhs;
//     rhs = myRhs;
// }

bool RSeparator::execute()
{
    return lhs->execute() && rhs->execute();
}