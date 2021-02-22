<<<<<<< HEAD
#include "../../include/tree.h"
#include <iostream>
extern int node_lineno;

tree_node::tree_node()
{
    this->line_number = node_lineno;
    node_lineno++;
=======
#include "../../include/tree.hpp"

int nodeLineNumber = 1;

tree_node::tree_node()
{
    this->line_number = nodeLineNumber;
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
}

int tree_node::get_line_number()
{
    return this->line_number;
}

tree_node *tree_node::set(tree_node *t)
{
    // Set the value of line_number to t->line_number
    this->line_number = t->line_number;
    return this;
}

<<<<<<< HEAD
// What should we do here.. noone knows
char *pad(int n)
{
    char nPad[n];
    for (int i = 0; i < n; i++)
        nPad[i] = ' ';

    return nPad;
}

/////////////////////// DEFINE A COMMON METHOD FOR DUMP AND DUMP_WITH_TYPES ///////////////////////////////////////////
//		NOTE 	: 	THESE METHODS ARE TEMPORARY AND THEY ARE GOING TO BE DELETED AFTER SOME TIME
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void tree_node::dump(std::ostream &stream, int paddingLen)
{
    // This will work for now
    stream << pad(paddingLen) << this->line_number;
}

=======
// Read cool.handout.h and read specs of the different constructors
// Copy cool.handout.h -> Read it
// Copy cool-tree.h and cool-tree.cpp
// Copy the aps package -> Read it
// Read cool-tree.cpp and implementation of constructors in cpp

// Done -> Copying files in my project
// Read
//      -- Cool-tree.handcode.h
//      -- Cool-tree.aps
//      -- Cool-tree.h
//      -- Cool-tree.cc
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
