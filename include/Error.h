#ifndef ERROR_H
#define ERROR_H
#include <iostream>

using namespace std;
class Error
{
private:
    /* data */
    int TYPE, lineNumber;
    char *errorMessage;

public:
    Error()
    {
    }
    Error(int _Type, char *_Message, int _LineNumber);
    int getType();
    char *getMessage();
    int getLineNo();
    void printError();
    // ~Error();
};

// Error::Error()
// {
// }

#endif