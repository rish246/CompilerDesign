flex lexicalAnalyzer.flex

g++ ../utilities/StringTable.cpp  lexicalAnalyzer.cpp lex.yy.c -o lexer

# ./lexer < $*

