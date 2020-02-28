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
#include <vector>

using namespace std;

class RShellExec;
class RAnd;
class ROr;
class RSeparator;
class RParser
{
public:
    RParser(){};
    bool execCommand(RShellBase *);
    string readHash(string);
    queue<string> readExpression(string);
    // vector<string> readOp(string);
    // vector<string> readStatement(string);
    // vector<char *> readInput(queue<char *>);
    queue<string> commandTree(queue<string>);
    // RShellBase *warpCommand(queue<char *>);
    RShellBase *warpCommand(queue<string>);

    // RShellBase *readPrecedence(queue<char *>);
private:
    bool isConn(string);
};

#endif