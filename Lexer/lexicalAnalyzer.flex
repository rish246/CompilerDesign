%{
    #include "lexicalAnalyzer.h"
    #include <string.h>
    #include "./Error/Error.h"
    #include "./Error/Error_Types.h"
    #include "./Error/Error_helpers.h"
    // #include "Error_Types.h"
    
    extern YYSTYPE yylval;
    const int MAX_SIZE = 1024;
    char *literal;
    char *temp;

    int stringLength = (int)(temp - literal);

    /*
        Maintain the currentLineNumber and the currentColNumber;

    */
    int currentLineNumber = 1;

    /*
        Comment can have depth
        // When we get a new comment start, we cannot have depth_comment
        // Comment can not have a large depth as expected
        // That may introduce some errors
        // Later
        // So better make it now
    */
    int commentDepth = 0;


%}



%x COMMENT
%x STRING_LITERAL
%x STRING_ERROR
%x SINGLE_LINE_COMMENT
%option stack

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
TYPES               "Int"|"Bool"|"String"|"Object"|"SELF_TYPE"|"self"



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
WHITESPACE	[ \f\t\v\r\n]
NEWLINE		\n

IDENTIFIER [a-zA-Z][a-zA-Z0-9_]+

/* Define all the characters related to string constants  -->  Done */ 
/* Write for comments */
/* Error Handling   */
/* 1 --> String */ 
/* Error .. String Constant Too Large */
STRING_START  \"



%%

{OPEN_COMMENT}              {
                                BEGIN(COMMENT);
                                commentDepth++;
                            }

<COMMENT>{OPEN_COMMENT}     {
                                commentDepth++;
                            }
<COMMENT>{NEWLINE}          { currentLineNumber++; }
<COMMENT>{CLOSE_COMMENT}    {
                                commentDepth--;
                                if(commentDepth == 0)
                                    BEGIN(INITIAL);
                            }     
<INITIAL>{CLOSE_COMMENT}    {
                                throw_InvalidParam(currentLineNumber);
                                return ERROR;
                            }
<COMMENT><<EOF>>            {
                                throw_Unexpected_EOF(currentLineNumber);
                                BEGIN(INITIAL);
                                return ERROR;
                            }
<COMMENT>.                  ;


{LINE_COMMENT}              BEGIN(SINGLE_LINE_COMMENT);

<SINGLE_LINE_COMMENT>{NEWLINE}      {
                                        currentLineNumber++;
                                        BEGIN(INITIAL);
                                    }

<SINGLE_LINE_COMMENT>.              ;

<INITIAL>{NEWLINE}         { currentLineNumber++; }
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
{AT}		        return '@';





{TYPES}             {
                        return TYPEID;
                    }


true                {
                        yylval.BOOL_CONST_VAL = true;
                        return BOOL_CONST;
                    }
false               {
                        yylval.BOOL_CONST_VAL = false;
                        return BOOL_CONST;
                    }


{INTEGER}           {
                        yylval.INT_CONST_VAL = atoi(yytext);
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
                                
                                yylval.STR_CONST_VAL = literal;
                                temp = nullptr;
                                literal = nullptr;                                
                                BEGIN(INITIAL);

                                return STR_CONST;
                                
                            }

<STRING_LITERAL>{NEWLINE}   {
                                throw_UnexpectedEndOfStrError(currentLineNumber);

                                literal = nullptr;
                                temp = nullptr;
                                return ERROR;
    
                                
                            }

<STRING_LITERAL><<EOF>>     {
                                throw_Unexpected_EOF(currentLineNumber);

                                temp = nullptr;
                                literal = nullptr;
                                BEGIN(INITIAL);
                                return ERROR;
                            }

<STRING_LITERAL>.           {
                                stringLength = int(temp - literal);
                                if(stringLength >= MAX_SIZE) {
                                    throw_StrConstTooLargeError(currentLineNumber);

                                    literal = nullptr;
                                    temp = nullptr;
                                    BEGIN(INITIAL);
                                    return ERROR;

                                }
                                *temp++ = *yytext;
                            }






{IDENTIFIER}        return OBJECTID;

.                 ;
%%
/*
    COMMENTS
    DIFFERENT_SMALL_ERRORS
*/
int yywrap(void) 
{
    return 1;
}

