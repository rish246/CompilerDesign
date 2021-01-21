# Lexer Implementation for our Programming Language

### Download necessary libraries
`sudo apt-get install flex bison`

**To run the files in the project, Follow the following commands:**
1. `flex lexicalAnalyzer.flex`
1. `g++ lexicalAnalyzer.cpp ./Error/Error.cpp lex.yy.c -o lexer`
2. `./lexer < input_file.cl`

#### `To change the output produced by the lexer, you can change the output produced by lexicalAnalyzer.cpp`
