#include "../include/Error.h"
#include <iostream>

using namespace std;

Error::Error(int _Type, char *_Message, int _LineNumber)
    : TYPE(_Type), lineNumber(_LineNumber), errorMessage(_Message)
{
}

int Error::getType()
{
    return this->TYPE;
}

char *Error::getMessage()
{
    return this->errorMessage;
}

int Error::getLineNo()
{
    return lineNumber;
}

void Error::printError()
{
    cout << "------------------------((Error Occured))---------------------------" << endl;
    cout << "Error Code : " << getType() << endl;
    cout << "Error Message : " << getMessage() << endl;
    cout << "Error occured at line number : " << getLineNo() << endl;
    cout << "--------------------------------------------------------------------" << endl;
}