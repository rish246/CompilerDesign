#include "../include/lexicalAnalyzer.h"
#include "../include/Error_Types.h"
#include "../include/Error.h"
#include "../include/Error_Types.h"

#include <string.h>

extern char *yytext;

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
    char message[] = "Invalid Parameter";
    // Concat YYTEXT in the message will be pretty Great

    int lenFinalMessage = strlen(message) + strlen(yytext) + 4;
    char *finalMessage = new char[lenFinalMessage];

    snprintf(finalMessage, (sizeof(char) * lenFinalMessage), "%s : %s", message, yytext);

    Error *newError = new Error(Error_Type, finalMessage, lineNo);
    yylval.error = newError;
}