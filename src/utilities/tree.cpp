#include "../../include/tree.h"
#include <iostream>
extern int node_lineno;

tree_node::tree_node()
{
    this->line_number = node_lineno;
    node_lineno++;
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

