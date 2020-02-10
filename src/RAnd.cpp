#include "header/RAnd.hpp"

bool RAnd::execute()
{
    if(lhs->execute())
    {
        return rhs->execute();
    }
    else
    {
        return false;
    }
}
    
        