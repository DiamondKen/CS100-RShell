#include "../header/RShellExec.hpp"
#include "../header/RShellBase.hpp"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <iostream>
#include <string.h>
#include <string>
#include "../header/RExit.hpp"

using namespace std;

bool RShellExec::execute()
{
    flagDivider();
    pid_t pid = fork();
    int status;

    if (pid == -1)
    {
        cout << "Error: command failed" << endl;
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        int size = flags.size();
        char *argv_list[size + 2];
        argv_list[0] = realCommand;

        // TEST COMMAND
        if (strcmp(realCommand, "test") == 0 || strcmp(realCommand, "[") == 0)
        {
            if (strcmp(realCommand, "test") == 0)
            {
                if (flags.size() == 1)
                {
                    if (testFileDir("-e", flags.front()))
                    {
                        cout << "(True)" << endl;
                        exit(0);
                    }
                    else
                    {
                        cout << "(False)" << endl;
                        exit(EXIT_FAILURE);
                    }
                }
                else
                {
                    char *testFlag = flags.front();
                    flags.pop();
                    if (testFileDir(testFlag, flags.front()))
                    {
                        cout << "(True)" << endl;
                        exit(0);
                    }
                    else
                    {
                        cout << "(False)" << endl;
                        exit(EXIT_FAILURE);
                    }
                }
            }
            else if (strcmp(realCommand, "[") == 0)
            {
                if (flags.size() == 3)
                {
                    char *testFlag = flags.front();
                    flags.pop();
                    if (testFileDir(testFlag, flags.front()))
                    {
                        cout << "(True)" << endl;
                        exit(0);
                    }
                    else
                    {
                        cout << "(False)" << endl;
                        exit(EXIT_FAILURE);
                    }
                }
                else if (flags.size() == 2)
                {
                    if (strcmp(flags.front(), "-e") == 0 || strcmp(flags.front(), "-f") == 0 || strcmp(flags.front(), "-d") == 0)
                    {
                        char *testFlag = flags.front();
                        flags.pop();
                        int length = strlen(flags.front());
                        string sPath = flags.front();
                        char *myPath = new char[length];
                        strcpy(myPath, sPath.substr(0, length - 1).c_str());
                        if (testFileDir(testFlag, myPath))
                        {
                            cout << "(True)" << endl;
                            exit(0);
                        }
                        else
                        {
                            cout << "(False)" << endl;
                            exit(EXIT_FAILURE);
                        }
                    }
                    else
                    {
                        if (testFileDir("-e", flags.front()))
                        {
                            cout << "(True)" << endl;
                            exit(0);
                        }
                        else
                        {
                            cout << "(False)" << endl;
                            exit(EXIT_FAILURE);
                        }
                    }
                }
                else if (flags.size() == 1)
                {
                    int length = strlen(flags.front());
                    string sPath = flags.front();
                    char *myPath = new char[length];
                    strcpy(myPath, sPath.substr(0, length - 1).c_str());
                    if (testFileDir("-e", myPath))
                    {
                        cout << "(True)" << endl;
                        exit(0);
                    }
                    else
                    {
                        cout << "(False)" << endl;
                        exit(EXIT_FAILURE);
                    }
                }
            }
        }
        else if (strcmp(realCommand, "exit") == 0)
        {
            exit(0);
        }
        else
        {
            for (int i = 1; i < size + 2; i++)
            {
                argv_list[i] = flags.front();
                flags.pop();
            }
            argv_list[size + 1] = NULL;

            // EXIT COMMAND

            execvp(argv_list[0], argv_list);
            cout << "Error: command failed" << endl;
            exit(EXIT_FAILURE);
        }
    }

    waitpid(pid, &status, 0);
    int exitStatus = WEXITSTATUS(status);
    if (exitStatus == EXIT_FAILURE)
    {
        return false;
    }
    if (strcmp(realCommand, "exit") == 0)
    {
        exit(0);
    }
}

void RShellExec::flagDivider()
{
    char *commandDupli = strdup(command);
    char *theFlag = strtok(commandDupli, " ");
    while (theFlag != NULL)
    {
        // if(theFlag[0] == '"')
        // {
        //     theFlag[0] = "";
        // }
        flags.push(theFlag);
        theFlag = strtok(NULL, " ");
    }
    realCommand = flags.front();
    flags.pop();
}

bool RShellExec::testFileDir(char *flag, char *path)
{
    struct stat fileStatus;
    if (strcmp(flag, "-e") == 0)
    {
        if (stat(path, &fileStatus) >= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (strcmp(flag, "-f") == 0)
    {
        if (stat(path, &fileStatus) >= 0)
        {
            return S_ISREG(fileStatus.st_mode);
        }
    }
    else if (strcmp(flag, "-d") == 0)
    {
        if (stat(path, &fileStatus) >= 0)
        {
            return S_ISDIR(fileStatus.st_mode);
        }
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
