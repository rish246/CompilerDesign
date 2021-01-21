#include "../../include/tree.hpp"

int nodeLineNumber = 1;

tree_node::tree_node()
{
    this->line_number = nodeLineNumber;
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