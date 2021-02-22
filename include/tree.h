#ifndef TREE_H
#define TREE_H

#include <iostream>

using namespace std;
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
protected:
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
    int first() { return 0; }
    int more(int i) { return (i < len()); }
    int next(int i) { return (i + 1); }

    virtual int len() = 0;

    virtual Elem nth_length(int n, int &len) = 0;

    // not related to instances or objects
    static list_node<Elem> *nil();
    static list_node<Elem> *single(Elem e);
    static list_node<Elem> *append(list_node<Elem> *l1, list_node<Elem> *l2);
};

char *pad(int n);

extern int info_size;

template <class Elem>
class nil_node : public list_node<Elem>
{
public:
    list_node<Elem> *copy_list() override;
    int len() override;
    Elem nth_length(int n, int &len) override;
    void dump(ostream &stream, int n) override;
};

template <class Elem>
class single_list_node : public list_node<Elem>
{
    Elem elem;

public:
    single_list_node(Elem t)
    {
        elem = t;
    }
    list_node<Elem> *copy_list() override;
    int len() override;
    Elem nth_length(int n, int &len) override;
    void dump(ostream &stream, int n) override;
};

/*
    This is a cheeky class

    // We just assign two lists and combine them in the form of a class to make them appear concatenated
    

    // When we call
    list_node<Elem> *list_node<Elem>::append_node(l1, l2)
    {
        form A class Object of type append_node
        // Put l1 in some
        // Put l2 in some
        // Return ptr to the object
    }
*/

template <class Elem>
class append_node : public list_node<Elem>
{
private:
    list_node<Elem> *some, *rest;

public:
    append_node(list_node<Elem> *l1, list_node<Elem> *l2)
    {
        some = l1;
        rest = l2;
    }
    list_node<Elem> *copy_list() override;
    int len() override;
    Elem nth(int n);
    Elem nth_length(int n, int &len) override;
    void dump(ostream &stream, int n) override;
};

// Return a singl_list_node<Elem> ptr
template <class Elem>
single_list_node<Elem> *list(Elem x);
// Called using single_list_node<Class_> = list(newElementOfTypeClass)

// append Elem x to the beginning of the list
template <class Elem>
append_node<Elem> *cons(Elem x, list_node<Elem> *l);

// Append Elem x to the end of the list
template <class Elem>
append_node<Elem> *xcons(list_node<Elem> *l, Elem x);

// Create an empty list of type elem
// Benefits of creating Empty lists
// Type declaration --> better while Debugging
template <class Elem>
list_node<Elem> *list_node<Elem>::nil() { return new nil_node<Elem>(); }
template <class Elem>
list_node<Elem> *list_node<Elem>::single(Elem e) { return new single_list_node<Elem>(e); }
template <class Elem>
list_node<Elem> *list_node<Elem>::append(list_node<Elem> *l1, list_node<Elem> *l2)
{
    return new append_node<Elem>(l1, l2);
}

///////////////////////////////////////////////////////////////////////////
//
// list_node::nth
//
// function to find the nth element of the list
//
///////////////////////////////////////////////////////////////////////////

template <class Elem>
Elem list_node<Elem>::nth(int n)
{
    int len;
    Elem tmp = nth_length(n, len);

    if (tmp)
        return tmp;
    else
    {
        cerr << "error: outside the range of the list\n";
        exit(1);
    }
}

// added 10/30/06 cgs
template <class Elem>
Elem append_node<Elem>::nth(int n)
{
    int len;
    Elem tmp = nth_length(n, len);

    if (tmp)
        return tmp;
    else
    {
        cerr << "error: outside the range of the list\n";
        exit(1);
    }
}

///////////////////////////////////////////////////////////////////////////
//
// nil_node::copy_list
//
// return the deep copy of the nil_node
//
///////////////////////////////////////////////////////////////////////////
template <class Elem>
list_node<Elem> *nil_node<Elem>::copy_list()
{
    return new nil_node<Elem>(); // Return a new Null Tree
}

///////////////////////////////////////////////////////////////////////////
//
// nil_node::len
//
// return the length of the nil_node
//
///////////////////////////////////////////////////////////////////////////
template <class Elem>
int nil_node<Elem>::len()
{
    return 0;
}

///////////////////////////////////////////////////////////////////////////
//
// nil_node::nth_length
//
// return the nth element on the list
//
///////////////////////////////////////////////////////////////////////////
template <class Elem>
Elem nil_node<Elem>::nth_length(int, int &len)
{
    len = 0;
    return NULL;
}

///////////////////////////////////////////////////////////////////////////
//
// nil_node::dump
//
// dump for list node
//
///////////////////////////////////////////////////////////////////////////
template <class Elem>
void nil_node<Elem>::dump(ostream &stream, int n)
{
    stream << pad(n) << "(nil)\n";
}

///////////////////////////////////////////////////////////////////////////
//
// single_list_node::copy_list
//
// return the deep copy of the single_list_node
//
///////////////////////////////////////////////////////////////////////////
template <class Elem>
list_node<Elem> *single_list_node<Elem>::copy_list()
{
    return new single_list_node<Elem>((Elem)elem->copy());
}

///////////////////////////////////////////////////////////////////////////
//
// single_list_node::len
//
// return the length of the single_list_node
//
///////////////////////////////////////////////////////////////////////////
template <class Elem>
int single_list_node<Elem>::len()
{
    return 1;
}

///////////////////////////////////////////////////////////////////////////
//
// single_list_node::nth_length
//
// return the nth element on the list
//
///////////////////////////////////////////////////////////////////////////
template <class Elem>
Elem single_list_node<Elem>::nth_length(int n, int &len)
{
    len = 1;
    if (n)
        return NULL;
    else
        return elem;
}

///////////////////////////////////////////////////////////////////////////
//
// single_list_node::dump
//
// dump for list node
//
///////////////////////////////////////////////////////////////////////////
template <class Elem>
void single_list_node<Elem>::dump(ostream &stream, int n)
{
    elem->dump(stream, n);
}

///////////////////////////////////////////////////////////////////////////
//
// append_node::copy_list
//
// return the deep copy of the append_node
//
///////////////////////////////////////////////////////////////////////////
template <class Elem>
list_node<Elem> *append_node<Elem>::copy_list()
{
    return new append_node<Elem>(some->copy_list(), rest->copy_list());
}

///////////////////////////////////////////////////////////////////////////
//
// append_node::len
//
// return the length of the append_node
//
///////////////////////////////////////////////////////////////////////////
template <class Elem>
int append_node<Elem>::len()
{
    return some->len() + rest->len();
}

///////////////////////////////////////////////////////////////////////////
//
// append_node::nth_length
//
// return the nth element on the list
//
///////////////////////////////////////////////////////////////////////////
template <class Elem>
Elem append_node<Elem>::nth_length(int n, int &len)
{
    int rlen;
    Elem tmp = some->nth_length(n, len);

    if (!tmp)
    {
        tmp = rest->nth_length(n - len, rlen);
        len += rlen;
    }
    return tmp;
}

///////////////////////////////////////////////////////////////////////////
//
// append_node::dump
//
// dump for list node
//
///////////////////////////////////////////////////////////////////////////
template <class Elem>
void append_node<Elem>::dump(ostream &stream, int n)
{
    int i, size;

    size = len();
    stream << pad(n) << "list\n";
    for (i = 0; i < size; i++)
        nth(i)->dump(stream, n + 2);
    stream << pad(n) << "(end_of_list)\n";
}

///////////////////////////////////////////////////////////////////////////
//
// list
//
///////////////////////////////////////////////////////////////////////////
template <class Elem>
single_list_node<Elem> *list(Elem x)
{
    return new single_list_node<Elem>(x);
}

///////////////////////////////////////////////////////////////////////////
//
// cons
//
///////////////////////////////////////////////////////////////////////////
template <class Elem>
append_node<Elem> *cons(Elem x, list_node<Elem> *l)
{
    return new append_node<Elem>(list(x), l);
}

///////////////////////////////////////////////////////////////////////////
//
// xcons
//
///////////////////////////////////////////////////////////////////////////
template <class Elem>
append_node<Elem> *xcons(list_node<Elem> *l, Elem x)
{
    return new append_node<Elem>(l, list(x));
}

template <class Elem>
list_node<Elem> *list_node<Elem>::copy_list()
{
    // Create a deep copy of the list
    int listLen = len();

    list_node<Elem> *resultingList = list_node<Elem>::nil();

    for (int i = 0; i < listLen; i++)
    {
        list_node<Elem> *newElem = list_node<Elem>::single(this->nth(i));

        resultingList = list_node<Elem>::append(resultingList, newElem);
    }

    return resultingList;
    // Iterate through list
    // For each element--> create a single_list
    // resulting_list --> nil_list()
    // resulting_list = append_list(resulting_list, newElement);
    // return resulting_list
}

#endif /* TREE_H */
///////////////////////////////////////////////////////////////////////////
