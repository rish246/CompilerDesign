flex lexicalAnalyzer.flex

<<<<<<< HEAD
g++ ../utilities/StringTable.cpp  lexicalAnalyzer.cpp lex.yy.c -o lexer

# ./lexer < $*

=======
g++ lexicalAnalyzer.cpp ../../Error/Error.cpp ../utilities/StringTable.cpp ../../Error/helpers.cpp lex.yy.c -o lexer

./lexer < input_file.cl
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
