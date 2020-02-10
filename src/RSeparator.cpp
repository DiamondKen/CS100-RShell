#include "RSeparator.hpp"

bool RSeparator::execute()
{
    return lhs->execute() && rhs->execute();
}