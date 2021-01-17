#ifndef SYMTAB_H
#define SYMTAB_H

#include <unordered_map>
#include <string.h>
// Define our Entry class
class Entry
{
protected:
    char *value;
    int length;
    int id;

public:
    Entry() {}

    Entry(char *v, int l, int _id);

    char *getValue();
};

// Define StringEntry
class StringEntry : public Entry
{
public:
    StringEntry(char *v, int l, int _id)
        : Entry(v, l, _id)
    {
    }
};
// Define IntEntry
class IntEntry : public Entry
{
public:
    IntEntry(char *v, int l, int _id)
        : Entry(v, l, _id)
    {
    }
};
// Define IdEntry
class IdEntry : public Entry
{
public:
    IdEntry(char *v, int l, int _id)
        : Entry(v, l, _id)
    {
    }
};

/*
    We have defined different types of Entries in a SymbolTable
    
    For Each type of Entry, we will make a separate symbol Table to store Each Entry separately


    // Make a general class -> SymbolTable (Template)
    // StringTable = SymbolTable<StringEntry>
    // IntTable = SymbolTable<IntEntry>
    // IdTable = SymbolTable<IdEntry>


*/

//////////////////////////////////////////////////////////////////////////////
//
//                  Class SymbolTable
//              1. Features:
//                      Table(Map), uniqueIndex
//              2. Methods
//                      addEntry(char *name) : Entry *
//                      lookup(char *name)  : Entry *
//
//////////////////////////////////////////////////////////////////////////////

template <class Elem>
class SymbolTable
{
    // Make the Table and Index protected
    // They will Be used by the IdTable, IntTable and StringTable
protected:
    // Table: Map from lexeme -> Entry
    std::unordered_map<char *, Elem *> table; // Ptr to Table is stored

    int uniqueId;

public:
    // Default constructor
    // Set uniqueId = 0 and Table is nullptr
    SymbolTable()
        : uniqueId(0)
    {
        printf("Default constructor is called\n");
    }

    Elem *addEntry(char *name);

    Elem *lookUp(char *name);
};

/*
        Add functionalities to the SymbolTable class
*/

template <class Elem>
Elem *SymbolTable<Elem>::addEntry(char *name)
{
    // Lookup Entry
    // If Entry Found, Return Entry
    // Else create a new
    Elem *existingEntry = lookUp(name);
    if (existingEntry != nullptr)
        return existingEntry;

    int lenEntry = strlen(name);
    // Create a new Entry
    Elem *newEntry = new Elem(name, lenEntry, uniqueId++);

    table[name] = newEntry;
    printf("New Entry Added In the Table\n");

    return newEntry;

    // return nullptr;
}

template <class Elem>
Elem *SymbolTable<Elem>::lookUp(char *name)
{
    // return table[name];
    return table[name];
}

class StringTable : public SymbolTable<StringEntry>
{
};

class IntTable : public SymbolTable<StringEntry>
{
};

class IdTable : public SymbolTable<StringEntry>
{
};

// Why am i not getting it here
// It means in some External file, i have declared stringTable(in SymTab.cpp)
// It uses same variable
extern StringTable stringTable;
extern IntTable intTable;
extern IdTable idTable;
#endif