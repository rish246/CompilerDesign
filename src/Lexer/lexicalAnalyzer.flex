%{
    #include <string>
    // #include "../../include/cool_parser.hpp"
    #include "../../include/cool_parser.hpp"
    #include "../../include/cool-tree.h"
    #include "../../include/cool.h"
    #include "../../include/StringTab.hpp"
    // #include "Error_Types.h"
    
    extern YYSTYPE yylval;
    const int MAX_SIZE = 1024;
    char *literal;
    char *temp;

    int stringLength = (int)(temp - literal);

    /*
        Maintain the curr_lineno and the currentColNumber;

    */
    int curr_lineno = 1;

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
<COMMENT>{NEWLINE}          { curr_lineno++; }
<COMMENT>{CLOSE_COMMENT}    {
                                commentDepth--;
                                if(commentDepth == 0)
                                    BEGIN(INITIAL);
                            }     
<INITIAL>{CLOSE_COMMENT}    {
                                // throw_InvalidParam(curr_lineno);
                                yylval.error_msg = "Invalid parameter";
                                return ERROR;
                            }
<COMMENT><<EOF>>            {
                                // throw_Unexpected_EOF(curr_lineno);
                                yylval.error_msg = "Unexpted EOF";
                                BEGIN(INITIAL);
                                return ERROR;
                            }
<COMMENT>.                  ;


{LINE_COMMENT}              BEGIN(SINGLE_LINE_COMMENT);

<SINGLE_LINE_COMMENT>{NEWLINE}      {
                                        curr_lineno++;
                                        BEGIN(INITIAL);
                                    }

<SINGLE_LINE_COMMENT>.              ;

<INITIAL>{NEWLINE}         { curr_lineno++; }
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
{AT}		        return '@';





{TYPES}             {
                        Entry* sym = new IdEntry(yytext, MAX_SIZE, entryId++);
                        /* printf("-----------------Found a new Id : %s-----------\n", yytext); */
                        yylval.symbol = sym;
                        return TYPEID;
                    }


true                {

                        yylval.boolean = true;
                        return BOOL_CONST;
                    }
false               {
                        yylval.boolean = false;
                        return BOOL_CONST;
                    }


{INTEGER}           {
                        // This is not working for some reason
                        std::string intValue(yytext);


                        Entry* sym = new IntEntry(intValue, intValue.size(), entryId++);

                        yylval.symbol = sym;

                        printf("Int Occured : %s at Line Number : %d\n", yylval.symbol->getValue(), curr_lineno);

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
                                std::string stringValue(literal);
                                
                                Entry* sym = new StringEntry(literal, (temp - literal), entryId++);

                                /* printf("-----------------Found a new StringEntry : %s-----------\n", yytext); */

                                yylval.symbol = sym;

                                dumpBuffers();                 
                                BEGIN(INITIAL);

                                return STR_CONST;
                                
                            }


<STRING_LITERAL>{NEWLINE}   {
                                yylval.error_msg = "Unexpted End of string";
                                dumpBuffers();
                                return ERROR;
    
                                
                            }

<STRING_LITERAL><<EOF>>     {
                                // throw_Unexpected_EOF(curr_lineno);
                                yylval.error_msg = "Unexpected EOF";
                                dumpBuffers();
                                BEGIN(INITIAL);
                                return ERROR;
                            }

<STRING_LITERAL>.           {
                                printf("-----------------Found a new StringLiteral : %s------\n", literal);

                                stringLength = int(temp - literal);
                                if(stringLength >= MAX_SIZE) {
                                    // throw_StrConstTooLargeError(curr_lineno);

                                    yylval.error_msg = "String Constant too large";
                                    dumpBuffers();
                                    BEGIN(INITIAL);
                                    return ERROR;

                                }
                                *temp++ = *yytext;
                            }






{IDENTIFIER}        {
                        printf("-----------------Found a new Identifier : %s------\n", yytext);

                        
                        Entry* sym = new IdEntry(yytext, MAX_SIZE, entryId++);

                        yylval.symbol = sym;
                        return OBJECTID;
                    }

.                   {
                        printf("Unexpected Token Recieved, %s\n", yytext);
                        
                        yylval.error_msg = "Invalid Parameter";
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

// Something here is causing the seg Fault--> what?