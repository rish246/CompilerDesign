/*
    Author: Rishabh Katna
    Date: 1st Jan 2021

    This file contains some helpers related to Error handling in our lexer
*/
#include "../lexicalAnalyzer.h"
#include "./Error_Types.h"
#include "./Error.h"
void throw_StrConstTooLargeError(int lineNo)
{
    int Error_Type = STRING_CONSTANT_TOO_LONG;
    const char *message = "String Constant too Long";

    Error *newError = new Error(Error_Type, (char *)message, lineNo);
    yylval.error = newError;
}

void throw_UnexpectedEndOfStrError(int lineNo)
{
    int Error_type = INVALID_END_OF_STRING;
    const char *error_message = "Invalid end of string";
    Error *newError = new Error(Error_type, (char *)error_message, lineNo);
    yylval.error = newError;
}

void throw_Unexpected_EOF(int lineNo)
{
    int Error_Type = UNEXPECTED_EOF;
    const char *message = "Unexted EOF";

    Error *newError = new Error(Error_Type, (char *)message, lineNo);
    yylval.error = newError;
}

/*
    Errors Related To Comments are given Below
*/

void throw_InvalidParam(int lineNo)
{
    int Error_Type = INVALID_PARAMETER;
    const char *message = "Invalid Parameter";

    Error *newError = new Error(Error_Type, (char *)message, lineNo);
    yylval.error = newError;
}