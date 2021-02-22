%{
<<<<<<< HEAD
    #include <string>
    // #include "../../include/cool_parser.hpp"
    #include "../../include/cool_parser.hpp"
    #include "../../include/cool-tree.h"
    #include "../../include/cool.h"
=======
    #include "../../include/lexicalAnalyzer.h"
    #include <string.h>
    #include "../../include/Error.h"
    #include "../../include/Error_Types.h"
    #include "../../include/Error_helpers.h"
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
    #include "../../include/StringTab.hpp"
    // #include "Error_Types.h"
    
    extern YYSTYPE yylval;
    const int MAX_SIZE = 1024;
    char *literal;
    char *temp;

    int stringLength = (int)(temp - literal);

    /*
<<<<<<< HEAD
        Maintain the curr_lineno and the currentColNumber;

    */
    int curr_lineno = 1;
=======
        Maintain the currentLineNumber and the currentColNumber;

    */
    int currentLineNumber = 1;
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a

    /*
        Comment can have depth
        // When we get a new comment start, we cannot have depth_comment
        // Comment can not have a large depth as expected
        // That may introduce some errors
        // Later
        // So better make it now
    */
    int commentDepth = 0;

    void dumpBuffers()
    {
        literal = nullptr;
        temp = nullptr;
    }


    // Each ID has unique countValue
    // INT/STR/ID
    int entryId = 0;





%}



%x COMMENT
%x STRING_LITERAL
%x STRING_ERROR
%x SINGLE_LINE_COMMENT
<<<<<<< HEAD
=======
%option stack
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a

/*
 * Define names for regular expressions here.
 */

/* OPERATORS */
DARROW              =>
ASSIGN		        <-

DIGIT 		        [0-9]
INTEGER		        [0-9]+
/* Define BOOLEAN */

OBJECTID	        [a-z]([A-Za-z_0-9])*


/* Define Types and TypeIDs */
TYPES               [A-Z]([A-Z0-9_a-z])*



/* COMMENTS */
OPEN_COMMENT	\(\*
CLOSE_COMMENT	\*\)
LINE_COMMENT	--.*

/* PUNCTATION MARKS */
OPEN_PAREN    \(
CLOSE_PAREN   \)
SEMI_COLON    ;
COMMA	      ,
COLON	      :
TIMES	      "*"
PLUS	      "+"
MINUS	      "-"
SLASH	      "/"
EQUAL	      "="
OPEN_BRACKET	 "{"
CLOSE_BRACKET	 "}"
LESS_THAN		          "<"
LESS_THAN_EQ    		 <=
GREATER_THAN            ">"
GREATER_THAN_EQ         ">="
DOT		 "."
TILDA		 "~"
AT		 "@"


ALL_CHAR	 .
ESC_CHAR	 \\[^tfbn]
ESC_TAB 	 \\t
ESC_BSP		 \\b
ESC_BS		 \\\\
ESC_FF		 \\f
ESC_NL		 \\n
ESC_NEWLINE	 \\\n

/* WHITESPACE */
WHITESPACE	[ \f\t\v\r]
NEWLINE		\n

IDENTIFIER [a-zA-Z][a-zA-Z0-9_]+

/* Define all the characters related to string constants  -->  Done */ 
/* Write for comments */
/* Error Handling   */
/* 1 --> String */ 
/* Error .. String Constant Too Large */
/* I am not able to Write StringEntry or IntEntry */
STRING_START  \"



%%

{OPEN_COMMENT}              {
                                BEGIN(COMMENT);
                                commentDepth++;
                            }

<COMMENT>{OPEN_COMMENT}     {
                                commentDepth++;
                            }
<<<<<<< HEAD
<COMMENT>{NEWLINE}          { curr_lineno++; }
=======
<COMMENT>{NEWLINE}          { currentLineNumber++; }
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
<COMMENT>{CLOSE_COMMENT}    {
                                commentDepth--;
                                if(commentDepth == 0)
                                    BEGIN(INITIAL);
                            }     
<INITIAL>{CLOSE_COMMENT}    {
<<<<<<< HEAD
                                // throw_InvalidParam(curr_lineno);
                                yylval.error_msg = "Invalid parameter";
                                return ERROR;
                            }
<COMMENT><<EOF>>            {
                                // throw_Unexpected_EOF(curr_lineno);
                                yylval.error_msg = "Unexpted EOF";
=======
                                throw_InvalidParam(currentLineNumber);
                                return ERROR;
                            }
<COMMENT><<EOF>>            {
                                throw_Unexpected_EOF(currentLineNumber);
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
                                BEGIN(INITIAL);
                                return ERROR;
                            }
<COMMENT>.                  ;


{LINE_COMMENT}              BEGIN(SINGLE_LINE_COMMENT);

<SINGLE_LINE_COMMENT>{NEWLINE}      {
<<<<<<< HEAD
                                        curr_lineno++;
=======
                                        currentLineNumber++;
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
                                        BEGIN(INITIAL);
                                    }

<SINGLE_LINE_COMMENT>.              ;

<<<<<<< HEAD
<INITIAL>{NEWLINE}         { curr_lineno++; }
=======
<INITIAL>{NEWLINE}         { currentLineNumber++; }
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
<INITIAL>{WHITESPACE}+      ;


class             return CLASS;
else              return ELSE;
fi                return FI;
if                return IF;
in                return IN;
inherits          return INHERITS;
isvoid            return ISVOID;
let               return LET;
loop              return LOOP;
pool                return POOL;
then                return THEN;
while               return WHILE;
case                return CASE;
esac                return ESAC;
new                 return NEW;
of              return OF;
not             return NOT;

{OPEN_PAREN}    return '(';
{CLOSE_PAREN}   return ')';
{SEMI_COLON}    return ';';
{COMMA}	        return ',';
{COLON}	        return ':';
{TIMES}	        return '*';
{PLUS}	        return '+';
{MINUS}	        return '-';
{SLASH}	        return '/';
{EQUAL}	        return '=';
{OPEN_BRACKET}	 return '{';
{CLOSE_BRACKET}	 return '}';
{LESS_THAN}	     return '<';
{LESS_THAN_EQ}   return LE;
{DOT}		     return '.';
{TILDA}		     return '~';
{GREATER_THAN}   return '>';
<<<<<<< HEAD
=======
{GREATER_THAN_EQ}   return GE;
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
{AT}		        return '@';





{TYPES}             {
                        Entry* sym = new IdEntry(yytext, MAX_SIZE, entryId++);
<<<<<<< HEAD
                        /* printf("-----------------Found a new Id : %s-----------\n", yytext); */
=======
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
                        yylval.symbol = sym;
                        return TYPEID;
                    }


true                {
<<<<<<< HEAD

                        yylval.boolean = true;
                        return BOOL_CONST;
                    }
false               {
                        yylval.boolean = false;
=======
                        yylval.BOOL_CONST_VAL = true;
                        return BOOL_CONST;
                    }
false               {
                        yylval.BOOL_CONST_VAL = false;
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
                        return BOOL_CONST;
                    }


{INTEGER}           {
<<<<<<< HEAD
                        // This is not working for some reason
                        std::string intValue(yytext);


                        Entry* sym = new IntEntry(intValue, intValue.size(), entryId++);

                        yylval.symbol = sym;

                        printf("Int Occured : %s at Line Number : %d\n", yylval.symbol->getValue(), curr_lineno);
=======
                        Entry* sym = new IntEntry(yytext, MAX_SIZE, entryId++);
                        yylval.symbol = sym;

                        printf("Int Occured : %s at Line Number : %d\n", yylval.symbol->getValue(), currentLineNumber);
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a

                        return INT_CONST;
                    }


{STRING_START}      {
                        BEGIN(STRING_LITERAL);
                        literal = new char[MAX_SIZE];
                        temp = literal;
                    }

<STRING_LITERAL>{ESC_NEWLINE}   {
                                    
                                    *temp++ = '\n';
                                }
<STRING_LITERAL>{ESC_TAB}       {
                                    *temp++ = '\t';
                                }

<STRING_LITERAL>\\\"            {
                                    *temp++ = '\"';
                                }


                
                            
<STRING_LITERAL>\"          { 
<<<<<<< HEAD
                                std::string stringValue(literal);
                                
                                Entry* sym = new StringEntry(literal, (temp - literal), entryId++);

                                /* printf("-----------------Found a new StringEntry : %s-----------\n", yytext); */
=======
                                
                                Entry* sym = new StringEntry(literal, strlen(literal), entryId++);
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a

                                yylval.symbol = sym;

                                dumpBuffers();                 
                                BEGIN(INITIAL);

                                return STR_CONST;
                                
                            }

<<<<<<< HEAD

<STRING_LITERAL>{NEWLINE}   {
                                yylval.error_msg = "Unexpted End of string";
=======
<STRING_LITERAL>{NEWLINE}   {
                                throw_UnexpectedEndOfStrError(currentLineNumber);
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
                                dumpBuffers();
                                return ERROR;
    
                                
                            }

<STRING_LITERAL><<EOF>>     {
<<<<<<< HEAD
                                // throw_Unexpected_EOF(curr_lineno);
                                yylval.error_msg = "Unexpected EOF";
=======
                                throw_Unexpected_EOF(currentLineNumber);
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
                                dumpBuffers();
                                BEGIN(INITIAL);
                                return ERROR;
                            }

<STRING_LITERAL>.           {
<<<<<<< HEAD
                                printf("-----------------Found a new StringLiteral : %s------\n", literal);

                                stringLength = int(temp - literal);
                                if(stringLength >= MAX_SIZE) {
                                    // throw_StrConstTooLargeError(curr_lineno);

                                    yylval.error_msg = "String Constant too large";
=======
                                stringLength = int(temp - literal);
                                if(stringLength >= MAX_SIZE) {
                                    throw_StrConstTooLargeError(currentLineNumber);
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
                                    dumpBuffers();
                                    BEGIN(INITIAL);
                                    return ERROR;

                                }
                                *temp++ = *yytext;
                            }






{IDENTIFIER}        {
<<<<<<< HEAD
                        printf("-----------------Found a new Identifier : %s------\n", yytext);

                        
=======
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
                        Entry* sym = new IdEntry(yytext, MAX_SIZE, entryId++);

                        yylval.symbol = sym;
                        return OBJECTID;
                    }

.                   {
                        printf("Unexpected Token Recieved, %s\n", yytext);
<<<<<<< HEAD
                        
                        yylval.error_msg = "Invalid Parameter";
=======
                        throw_InvalidParam(currentLineNumber);
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
                        return ERROR;
                    }
%%
/*
    COMMENTS
    DIFFERENT_SMALL_ERRORS
*/
int yywrap(void) 
{
    return 1;
}

<<<<<<< HEAD
// Something here is causing the seg Fault--> what?
=======
// Construct a symbol Table
// Return the Unexpected Character Error
// Start working on the Parser
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
