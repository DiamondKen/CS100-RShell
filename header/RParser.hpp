#ifndef __RPARSER_H__
#define __RPARSER_H__

#include "RShellBase.hpp"
#include "RShellConn.hpp"
#include "RShellExec.hpp"
#include "RAnd.hpp"
#include "ROr.hpp"
#include "RSeparator.hpp"
#include <string>
#include <queue>

using namespace std;

class RShellExec;
class RAnd;
class ROr;
class RSeparator;
class RParser
{
public:
    RParser(char userInput[]) { input = userInput; };
    virtual bool execCommand(queue<RShellBase *>);
    virtual queue<char *> readQuote();
    virtual queue<char *> readHash(queue<char *>);
    virtual queue<char *> readInput(queue<char *>);
    virtual queue<RShellBase *> warpCommand(queue<char *>);

protected:
    char *input;
};

#endif