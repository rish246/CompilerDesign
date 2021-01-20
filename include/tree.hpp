#ifndef TREE_H
#define TREE_H

#include <iostream>
/*

Fields of TreeNode class

protected:
    line_number -> Line number of the program from which the AST node is generated

public:
    tree_node() -> generate a new node 
        set: line_number = yylineno;


    void dump(ostream &s, int n); 
        pretty printer for the node 
        n -> padding 

    gen_line_number();
        returns line number

    Symbol get_type();
        returns the type of the current node


    tree_node* set(tree_node *t);
        this->line_number = t->line_number;
        this->type = t->get_type(); 


*/
class tree_node
{
private:
    /* data */
    int line_number; // For generating Parse Errors
public:
    tree_node();
    // tree_node();

    // All above functions will be virtual functions
    virtual void dump(std::ostream &s, int nPad);

    virtual ~tree_node() {}

    // Copy function
    // Creates a deep copy of the tree_node
    // make copy function virtual so that the list_node can override it
    virtual tree_node *copy() = 0;

    int get_line_number();

    tree_node *set(tree_node *t);
};

/*
    Define the class list_node -> implements LIST of APS language

    // properties of list_node -> 
        // Inherits tree_node
        // Template 
        

    --Members of list_node class
    tree_node* copy();
    list_node<Elem> *copy_list();

    -- Both above functions can be used to copy list but 2nd should be used.
        -- 1st can create a deep copy of the APS tree
        -- 2nd can create a deep copy of a list<Elem> only


    Elem nth(int n); 
        -- get nth element of the list


    -- Implementing a simple iterator for list
    int first();
    int more(int i);
    int next(int i);

    -- Use of the iterator 
    for(int i = l->first(); l->more(i); i = l->next(i))
    {
        --perform operation on l->nth(i);
    }
    

    int len() 
        -- Get the length of the list


    ----- Create constructors for creating empty list, single element list and append two lists
    static list_node<Elem> *nil();
    static list_node<Elem> *single_list(Elem e);
    static list_node<Elem> *append_list(list_node<Elem>* l1, list_node<Elem> *l2);



*/
template <class Elem>
class list_node : public tree_node
{
public:
    // Make copy constructors
    // override only virtual functions
    tree_node *copy() override { return copy_list(); }

    // classes which will inherit list_node will be able to override copy_list() method
    virtual list_node<Elem> *copy_list();

    // Destructor
    virtual ~list_node() {}

    Elem nth(int n);

    // Iterator
    int first();
    int more(int i);
    int next(int i);

    virtual int len() = 0;

    virtual Elem nth_length(int n, int &len) = 0;

    // not related to instances or objects
    static list_node<Elem> *nil();
    static list_node<Elem> *single_list(Elem e);
    static list_node<Elem> *append_list(list_node<Elem> *l1, list_node<Elem> *l2);
};

// Read about virtual function
// Read about their use and make sense of this code to very ground

#endif