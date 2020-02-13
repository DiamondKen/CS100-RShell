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
    RParser(char userInput[]) { input = userInput; };

    virtual string readInput();
    virtual string readHash(queue<char*>);
    virtual queue<char *> readQuote();
protected:
    char *input;
};



#endif