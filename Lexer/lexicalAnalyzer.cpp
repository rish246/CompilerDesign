#include "lexicalAnalyzer.h"
#include "./Error/Error_Types.h"
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
// #define yylval YYLVAL;
extern int yylineno;
extern int yylex();
extern char *yytext;
extern int currentLineNumber;
YYSTYPE yylval;

using namespace std;

unordered_map<int, string> keywords = {
    {CLASS, "CLASS"},
    {IF, "IF"},
    {FI, "FI"},
    {WHILE, "WHILE"},
    {LOOP, "LOOP"},
    {POOL, "POOL"},
    {IN, "IN"},
    {INHERITS, "INHERITS"},
    {LET, "LET"},
    {THEN, "THEN"},
    {CASE, "CASE"},
    {ESAC, "ESAC"},
    {OF, "OF"},
    {DARROW, "DARROW"},
    {NEW, "NEW"},
    {ISVOID, "ISVOID"},
    {NOT, "NOT"}

};

bool isKeyword(int token)
{
    return !keywords[token].empty();
}

int main()
{
    int newToken = yylex();

    cout << "Token Type \t"
         << "Token" << endl;
    while (newToken)
    {
        if (isKeyword(newToken))
        {
            // cout << "Keyword Found = " << yytext << " at line number " << currentLineNumber << endl;
        }

        if (newToken == BOOL_CONST)
        {
            // cout << "NewToken = " << newToken << "\t" << yytext << endl;
            // bool valueOfToken = yylval.BOOL_CONST_VAL;
            // if (valueOfToken)
            // {
            //     cout << "TOken is true" << endl;
            // }
            // else
            // {
            //     cout << "Token is false" << endl;
            // }
        }

        else if (newToken == INT_CONST)
        {
            int valueOfToken = yylval.INT_CONST_VAL;
            // cout << "Integer Token = " << (valueOfToken) << endl;
        }

        else if (newToken == STR_CONST)
        {
            // cout << "found the string :" << yylval.STR_CONST_VAL << endl;
        }

        else if (newToken == ERROR)
        {
            // printError(yylval.error);
            Error *newError = yylval.error;
            newError->printError();
            break;
        }

        else if (newToken == OBJECTID)
        {
            // cout << "Object ID : " << yytext << endl;
        }
        else if (newToken == TYPEID)
        {
            // cout << "Found Type ID : " << yytext << endl;
        }
        else if (newToken == LE)
        {
            cout << yytext << endl;
        }
        else
        {
            cout << (char)newToken << endl;
        }

        newToken = yylex();
    }
}

// We are now ready to work on the COOL lexer for tommorow
// NICE BOIS
// Complete the assignment here
// As the core compiler is not working properly.
// What happens to normal characters