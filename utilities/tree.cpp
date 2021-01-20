#include "../include/tree.hpp"

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