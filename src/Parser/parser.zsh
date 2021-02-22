# compile all files required for parser
cd ../Lexer
flex -o lex.yy.cpp lexicalAnalyzer.flex

cd ../Parser

bison -d -o cool_parser.cpp cool.y

g++ -w -o parser cool_parser.cpp parserTest.cpp ../utilities/StringTable.cpp ../utilities/tree.cpp ../utilities/cool-tree.cc ../Lexer/lex.yy.cpp

# we are not executing the code because we are not passing the filename
./parser $*
