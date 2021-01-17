/*
    Author: Rishabh Katna
    Date: 1st Jan 2021

    This file contains some helpers related to Error handling in our lexer
*/
#include "lexicalAnalyzer.h"
#include "Error_Types.h"
#include "Error.h"

void throw_StrConstTooLargeError(int lineNo);

void throw_UnexpectedEndOfStrError(int lineNo);

void throw_Unexpected_EOF(int lineNo);

/*
    Errors Related To Comments are given Below
*/

void throw_InvalidParam(int lineNo);

// Extract Them To another File