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
// vector<string> RParser::readStatement(string input)
// {
//     vector<string> statement;
//     int strLen = input.size();
//     int prePos = 0;
//     bool isQuote = false;
//     for (int i = 0; i < strLen; i++)
//     {
//         if (input[i] == '"')
//         {
//             isQuote = !isQuote;
//             // for (int j = i; j < strLen; j++)
//             // {
//             //     if (input[j] == '"')
//             //     {
//             //         // temp string for storage
//             //         string temp = input.substr(i, j);
//             //         // conversion between string and char* to store in statement container
//             //         statement.push(temp);
//             //         i = j;
//             //         break;
//             //     }
//             // }
//         }
//         else if (isQuote == false)
//         {
//             if (input[i] == '&' && input[i + 1] == '&')
//             {
//                 // temp string for storage
//                 string temp = input.substr(prePos, i - 1);
//                 // conversion between string and char* to store in statement container
//                 statement.push_back(temp);
//                 i++;
//                 prePos = i + 1;
//             }
//             else if (input[i] == '|' && input[i + 1] == '|')
//             {
//                 // temp string for storage
//                 string temp = input.substr(prePos, i - 1);
//                 // conversion between string and char* to store in statement container
//                 statement.push_back(temp);
//                 i++;
//                 prePos = i + 1;
//             }
//             else if (input[i] == ';')
//             {
//                 // temp string for storage
//                 string temp = input.substr(prePos, i - 1);
//                 // conversion between string and char* to store in statement container
//                 statement.push_back(temp);
//                 prePos = i + 1;
//             }
//             // else if (input[i] == '(' || input[i] == ')')
//             // {
//             //     // if (input[i + 1] == '(' || input[i + 1] == ')')
//             //     // {
//             //     //     prePos = i + 2;
//             //     //     continue;
//             //     // }
//             //     // else
//             //     // {
//             //     string temp = input.substr(prePos, i - 1);
//             //     // conversion between string and char* to store in statement container
//             //     statement.push_back(temp);
//             //     prePos = i + 1;
//             //     // }
//             // }
//             // else if (input[i] == ' ')
//             // {
//             //     continue;
//             // }
//         }
//     }
//     return statement;
// }

// vector<string> RParser::readOp(string input)
// {
//     int strLen = input.size();
//     bool inQuote = false;
//     vector<string> opStack;
//     for (int i = 0; i < strLen; i++)
//     {
//         if (input[i] == '"')
//         {
//             inQuote = !inQuote;
//         }
//         else if (inQuote == false)
//         {

//             if (input[i] == '&' && input[i + 1] == '&')
//             {
//                 opStack.push_back("&&");
//                 i++;
//             }
//             else if (input[i] == '|' && input[i + 1] == '|')
//             {
//                 opStack.push_back("||");
//                 i++;
//             }
//             else if (input[i] == ';')
//             {
//                 opStack.push_back(";");
//             }
//             else if (input[i] == '(')
//             {
//                 opStack.push_back("(");
//             }
//             else if (input[i] == ')')
//             {
//                 opStack.push_back(")");
//             }
//         }
//     }
//     return opStack;
// }
