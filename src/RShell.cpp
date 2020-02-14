#include "RAnd.cpp"
#include "RExit.cpp"
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
    do
    {
        cout << "$ ";
        getline(cin, input);
        char cInput[input.size() + 1];
        strcpy(cInput, input.c_str());
        RParser *parser = new RParser(cInput);
        parser->execCommand(parser->warpCommand(parser->readInput(parser->readHash(parser->readQuote()))));
    } while (input != "exit");
}