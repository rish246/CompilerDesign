#include "../../include/lexicalAnalyzer.h"
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
// #define yylval YYLVAL;
extern int yylineno;
extern int yylex();
extern char *yytext;
extern int curr_lineno;
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
        // if (isKeyword(newToken))
        // {
        //     cout << "Keyword Found = " << yytext << " at line number " << curr_lineno << endl;
        // }

        //     if (newToken == BOOL_CONST)
        //     {
        //         cout << "NewToken = " << newToken << "\t" << yytext << endl;
        //         bool valueOfToken = yylval.boolean;
        //         if (valueOfToken)
        //         {
        //             cout << "TOken is true" << endl;
        //         }
        //         else
        //         {
        //             cout << "Token is false" << endl;
        //         }
        //     }

        //     else if (newToken == INT_CONST)
        //     {
        //         int valueOfToken = atoi(yylval.symbol->getValue());
        //         cout << "Integer Token = " << (valueOfToken) << endl;
        //     }

        //     else if (newToken == STR_CONST)
        //     {
        //         cout << "found the string :" << yylval.symbol->getValue() << endl;
        //     }

        //     else if (newToken == ERROR)
        //     {
        //         // printError(yylval.error);
        //         cout << "------ Error :: " << yylval.error_msg << " at line number " << curr_lineno << endl;
        //     }
        //     // Wait.. What the Hell is this
        //     // Why is it forming an ObjectId Rather Than a TypeID
        //     else if (newToken == OBJECTID)
        //     {
        //         cout << "Object ID : " << yytext << endl;
        //     }
        //     else if (newToken == TYPEID)
        //     {
        //         cout << "Found Type ID : " << yylval.symbol->getValue() << endl;
        //     }
        //     else if (newToken == LE)
        //     {
        //         cout << yytext << endl;
        //     }
        //     else
        //     {
        //         cout << (char)newToken << endl;
        //     }

        newToken = yylex();
        // }
    }
}

// We dont have a way to characterize types
// Why are we Taking Both Types of IDS as Same
// Implementation is Wrong.. Simply
// My Lexer should work now
// Entries are working ... Nice
// making them work together