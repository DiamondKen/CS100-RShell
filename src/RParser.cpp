#include "../header/RParser.hpp"
#include <queue>
#include <stack>
#include <iostream>
#include <cstring>

using namespace std;

bool RParser::execCommand(RShellBase *container)
{
    if (container == NULL)
    {
        return false;
    }
    return container->execute();
}

RShellBase *RParser::warpCommand(queue<string> postfixET)
{
    stack<RShellBase *> execStack;
    while (!postfixET.empty())
    {
        if (!isConn(postfixET.front()))
        {
            string temp = postfixET.front();
            char *cstr = strdup(temp.c_str());
            RShellExec *newExec = new RShellExec(cstr);
            execStack.push(newExec);
            postfixET.pop();
        }
        else
        {
            if (postfixET.front() == "&&")
            {
                RShellBase *tempExec2 = execStack.top();
                execStack.pop();
                RShellBase *tempExec1 = execStack.top();
                execStack.pop();
                RAnd *myRAnd = new RAnd(tempExec1, tempExec2);
                execStack.push(myRAnd);
                postfixET.pop();
            }
            else if (postfixET.front() == "||")
            {
                RShellBase *tempExec2 = execStack.top();
                execStack.pop();
                RShellBase *tempExec1 = execStack.top();
                execStack.pop();
                ROr *myROr = new ROr(tempExec1, tempExec2);
                execStack.push(myROr);
                postfixET.pop();
            }
            else if (postfixET.front() == ";")
            {
                RShellBase *tempExec2 = execStack.top();
                execStack.pop();
                RShellBase *tempExec1 = execStack.top();
                execStack.pop();
                RSeparator *myRSeparator = new RSeparator(tempExec1, tempExec2);
                execStack.push(myRSeparator);
                postfixET.pop();
            }
        }
    }
    return execStack.top();
}

bool RParser::isConn(string c)
{
    if (c == "&&" || c == "||" || c == ";")
    {
        return true;
    }
    else
    {
        return false;
    }
}

queue<string> RParser::commandTree(queue<string> infixET)
{
    stack<string> opStack;
    queue<string> postfixET;
    while (!infixET.empty())
    {
        // whitespace
        if (infixET.front() == " ")
        {
            infixET.pop();
        }

        // if it is connector
        else if (isConn(infixET.front()))
        {
            opStack.push(infixET.front());
            infixET.pop();
        }

        // if it is left brace
        else if (infixET.front() == "(")
        {
            opStack.push("(");
            infixET.pop();
        }

        // if it is right brace
        else if (infixET.front() == ")")
        {
            // pop all to ET
            while (!opStack.empty() && opStack.top() != "(")
            {
                postfixET.push(opStack.top());
                opStack.pop();
            }
            // Pop left brace
            if (!opStack.empty())
            {
                opStack.pop();
            }
        }

        else
        {
            postfixET.push(infixET.front());
            infixET.pop();
        }
    }

    while(!opStack.empty())
    {
        postfixET.push(opStack.top());
        opStack.pop();
    }

    return postfixET;
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

queue<string> RParser::readExpression(string input)
{
    int strLen = input.size();
    bool inQuote = false;
    queue<string> infixET;
    int prePos = 0;
    for (int i = 0; i < strLen; i++)
    {
        if (input[i] == '"')
        {
            inQuote = !inQuote;
        }
        else if (inQuote == false)
        {

            if (input[i] == '&' && input[i + 1] == '&')
            {
                string temp = input.substr(prePos, i);
                infixET.push(temp);
                infixET.push("&&");
                i++;
                prePos = i + 1;
            }
            else if (input[i] == '|' && input[i + 1] == '|')
            {
                string temp = input.substr(prePos, i);
                infixET.push(temp);
                infixET.push("||");
                i++;
                prePos = i + 1;
            }
            else if (input[i] == ';')
            {
                string temp = input.substr(prePos, i);
                infixET.push(temp);
                infixET.push(";");
                prePos = i + 1;
            }
            else if (input[i] == '(')
            {
                infixET.push("(");
                prePos = i + 1;
            }
            else if (input[i] == ')')
            {
                if (prePos == i)
                {
                    infixET.push(")");
                    prePos = i + 1;
                }
                string temp = input.substr(prePos, i);
                infixET.push(temp);
                infixET.push(")");
                prePos = i + 1;
            }
        }
    }
    infixET.push(input.substr(prePos, strLen));
    return infixET;
}

string RParser::readHash(string input)
{
    int strLen = input.size();
    bool inQuote = false;
    for (int i = 0; i < strLen; i++)
    {
        if (input[i] == '"')
        {
            inQuote = !inQuote;
        }
        else if (inQuote == false)
        {
            if (input[i] == '#')
            {
                return input.substr(0, i);
            }
        }
    }
    return input;
}

// stack<char *> RParser::readInput(queue<char *> hashContainer)
// {
//     stack<char *> statementStack;
//     char delimiter[] = "&|;()";

//     // Add &,|,;
//     while (hashContainer.size() != 0)
//     {
//         char *tempPtr = strdup(hashContainer.front());
//         string ret = "";
//         if (tempPtr[0] == '"')
//         {
//             ret += tempPtr;
//             hashContainer.pop();
//         }
//         else
//         {
//             char *command = strdup(tempPtr);
//             char *copy = strdup(tempPtr);
//             char *token = strtok(command, delimiter);

//             while (token)
//             {
//                 ret += token;
//             }
//             hashContainer.pop();
//         }
//     }

//     return finalContainer;
// }

// queue<char *> RParser::readQuote(char *input)
// {
//     char delimiter[] = "\"";

//     queue<char *> quoteContainer;
//     char *copy = strdup(input);
//     string ret = "";
//     char *copy2 = strdup(input);
//     char *token = strtok(copy2, delimiter);
//     while (token)
//     {
//         quoteContainer.push(token);
//         if (copy[token - copy2 + strlen(token)] == '"')
//         {
//             quoteContainer.push("\"");
//         }
//         token = strtok(NULL, delimiter);
//     }

//     // debug code
//     // int containerSize = quoteContainer.size();
//     // for (int i = 0; i <= containerSize; i++)
//     // {
//     //     cout << quoteContainer.front() << endl;
//     //     quoteContainer.pop();
//     // }
//     return quoteContainer;
// }
