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