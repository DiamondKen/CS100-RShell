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
    RParser(){};
    virtual bool execCommand(RShellBase *);
    virtual queue<char *> readQuote(char *);
    virtual queue<char *> readHash(queue<char *>);
    virtual stack<char *> readOp(string);
    virtual stack<char *> readStatement(string);
    virtual stack<char *> readInput(queue<char *>);
    // virtual RShellBase *warpCommand(queue<char *>);
    virtual RShellBase *warpCommand(stack<char *>, stack<char *>);
    virtual queue<char *> readString(string);
    // virtual RShellBase *readPrecedence(queue<char *>);
};

#endif