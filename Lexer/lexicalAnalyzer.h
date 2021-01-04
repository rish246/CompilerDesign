#ifndef LEXICAL_ANALYZER_H
#define LEXICAL_ANALYZER_H
#include "./Error/Error.h"

#define CLASS 258
#define ELSE 259
#define FI 260
#define IF 261
#define IN 262
#define INHERITS 263
#define LET 264
#define LOOP 265
#define POOL 266
#define THEN 267
#define WHILE 268
#define CASE 269
#define ESAC 270
#define OF 271
#define DARROW 272
#define NEW 273
#define ISVOID 274

// STR_const == "This is a string constant"
// INT_const == 43 | 43 etc
// BOOL_const == True or False
// TYPEID -- I don't know (IF TOKEN IS THE NAME OF SOME TYPE.. THEN WHICH TYPE)
// OBJECT_ID --
// NOT not
// ERROR --> WHENEVER ANY ERROR OCCURS, SHIP THIS
// LET_STMT
#define STR_CONST 275
#define INT_CONST 276
#define BOOL_CONST 277
#define TYPEID 278
#define OBJECTID 279
#define ASSIGN 280
#define NOT 281
#define LE 282
#define ERROR 283
#define LET_STMT 285
#define GE 286

#ifndef YYSTYPE
typedef union YYSTYPE
{
    int INT_CONST_VAL;
    bool BOOL_CONST_VAL;
    char *STR_CONST_VAL;
    Error *error;
} YYSTYPE;

// define yylval
extern YYSTYPE yylval;
#endif

#endif