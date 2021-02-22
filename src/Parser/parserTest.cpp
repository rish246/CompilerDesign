#include <iostream>

// include all the files related to the parser
#include "../../include/cool_parser.hpp"

// Define all the external values
extern int yyparse();
extern int yylex();
extern int yylineno;
extern int node_lineno;

extern int omerrs;
char *curr_filename;
int main(int args, char **argv)
{

	curr_filename = argv[1];

	// Declare the input filename
	extern FILE *yyin;

	yyin = fopen((const char *)curr_filename, "r");

	// call yyparse()
	int parseErrors = yyparse();
	if (!parseErrors)
	{
		std::cout << "Successfully parsed the input file" << std::endl;
	}
	else
	{
		std::cout << omerrs << " errors were found while parsing the File " << std::endl;
	}
}

// it is compiling for fucks sake
// Now to fix the bugs..