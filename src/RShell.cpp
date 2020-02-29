#include "RAnd.cpp"
#include "../header/RExit.hpp"
#include "ROr.cpp"
#include "RSeparator.cpp"
#include "RShellBase.cpp"
#include "RShellConn.cpp"
#include "RShellExec.cpp"
#include "RParser.cpp"
#include <cstring>

using namespace std;

int main()
{
    string input;
    while (true)
    {
        cout << "$ ";
        getline(cin, input);
        if (input == "")
        {
            continue;
        }
        // char cInput[input.size() + 1];
        // strcpy(cInput, input.c_str());
        RParser *parser = new RParser();
        parser->execCommand(parser->warpCommand(parser->commandTree(parser->readExpression(parser->readHash(input)))));
    }
}
// RShellBase *RParser::warpCommand(queue<char *> container)
// {
//     queue<RShellBase *> warpExec;
//     queue<char *> statment;
//     stack<char *> ope;

//     while (container.size() != 0)
//     {
//         char *tempPtr = strdup(container.front());
//         if (strchr(tempPtr, '&'))
//         {
//             container.pop();
//             string ret = "";
//             while (container.size() != 0 && !(container.front()[0] == '&' || container.front()[0] == '|' || container.front()[0] == ';'))
//             {
//                 tempPtr = strdup(container.front());
//                 ret += tempPtr;
//                 container.pop();
//                 if (container.size() != 0 && !(container.front()[0] == '&' || container.front()[0] == '|' || container.front()[0] == ';'))
//                 {
//                     ret += " ";
//                 }
//             }
//             RShellExec *retExe = new RShellExec(ret.c_str());
//             RAnd *andExe = new RAnd(warpExec.front(), retExe);
//             warpExec.pop();
//             warpExec.push(andExe);
//         }
//         else if (strchr(tempPtr, '|'))
//         {
//             container.pop();
//             string ret = "";
//             while (container.size() != 0 && !(container.front()[0] == '&' || container.front()[0] == '|' || container.front()[0] == ';'))
//             {
//                 tempPtr = strdup(container.front());
//                 ret += tempPtr;
//                 container.pop();
//                 if (container.size() != 0 && !(container.front()[0] == '&' || container.front()[0] == '|' || container.front()[0] == ';'))
//                 {
//                     ret += " ";
//                 }
//             }
//             RShellExec *retExe = new RShellExec(ret.c_str());
//             ROr *orExe = new ROr(warpExec.front(), retExe);
//             warpExec.pop();
//             warpExec.push(orExe);
//         }
//         else if (strchr(tempPtr, ';'))
//         {
//             container.pop();

//             string ret = "";
//             while (container.size() != 0 && !(container.front()[0] == '&' || container.front()[0] == '|' || container.front()[0] == ';'))
//             {
//                 tempPtr = strdup(container.front());
//                 ret += tempPtr;
//                 container.pop();
//                 if (container.size() != 0 && !(container.front()[0] == '&' || container.front()[0] == '|' || container.front()[0] == ';'))
//                 {
//                     ret += " ";
//                 }
//             }
//             RShellExec *retExe = new RShellExec(ret.c_str());
//             RSeparator *sepExe = new RSeparator(warpExec.front(), retExe);
//             warpExec.pop();
//             warpExec.push(sepExe);
//         }
//         else
//         {
//             string ret = "";
//             while (container.size() != 0 && !(container.front()[0] == '&' || container.front()[0] == '|' || container.front()[0] == ';'))
//             {
//                 tempPtr = strdup(container.front());
//                 ret += tempPtr;
//                 container.pop();
//                 if (container.size() != 0 && !(container.front()[0] == '&' || container.front()[0] == '|' || container.front()[0] == ';'))
//                 {
//                     ret += " ";
//                 }
//             }
//             RShellExec *exe = new RShellExec(ret.c_str());
//             warpExec.push(exe);
//         }
//     }

//     return warpExec.front();
// }
