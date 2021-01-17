flex lexicalAnalyzer.flex

g++ lexicalAnalyzer.cpp ../Error/Error.cpp ../utilities/SymTab.cpp ../Error/helpers.cpp lex.yy.c -o lexer

./lexer < input_file.cl