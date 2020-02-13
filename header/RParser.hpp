#ifndef __RPARSER_H__
#define __RPARSER_H__

#include "RShellBase.hpp"
#include "RShellConn.hpp"
#include "RShellExec.hpp"
#include "RAnd.hpp"
#include "ROr.hpp"
#include "RSeparator.hpp"
#include <string>

using namespace std;

class RParser
{
public:
    RParser(string input) { this->input = input; };

    virtual string readInput();
    virtual string readHash();

protected:
    string input;
};



#endif