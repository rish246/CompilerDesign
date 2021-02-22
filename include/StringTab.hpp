#ifndef STRING_TAB_H
#define STRING_TAB_H

<<<<<<< HEAD
#include <iostream>
#include <unordered_map>
#include <string>
=======
#include <unordered_map>
#include <string.h>
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
// Define our Entry class
class Entry
{
protected:
<<<<<<< HEAD
    std::string m_value;
    size_t m_length;
    int m_id;
=======
    char *value;
    int length;
    int id;
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a

public:
    Entry() {}

<<<<<<< HEAD
    Entry(const std::string &, size_t l, int _id);

    std::string getValue();
=======
    Entry(char *v, int l, int _id);

    char *getValue();
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
};

// Define StringEntry
class StringEntry : public Entry
{
public:
<<<<<<< HEAD
    StringEntry(const std::string &v, size_t l, int _id)
=======
    StringEntry(char *v, int l, int _id)
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
        : Entry(v, l, _id)
    {
    }
};
// Define IntEntry
class IntEntry : public Entry
{
public:
<<<<<<< HEAD
    IntEntry(const std::string &v, size_t l, int _id)
=======
    IntEntry(char *v, int l, int _id)
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
        : Entry(v, l, _id)
    {
    }
};
// Define IdEntry
class IdEntry : public Entry
{
public:
<<<<<<< HEAD
    IdEntry(const std::string &v, size_t l, int _id)
=======
    IdEntry(char *v, int l, int _id)
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
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
class Table
{
    // Make the Table and Index protected
    // They will Be used by the IdTable, IntTable and StringTable
<<<<<<< HEAD
public:
    // Table: Map from lexeme -> Entry
    std::unordered_map<std::string, Elem *> table; // Ptr to Table is stored
=======
protected:
    // Table: Map from lexeme -> Entry
    std::unordered_map<char *, Elem *> table; // Ptr to Table is stored
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a

    int uniqueId;

public:
    // Default constructor
    // Set uniqueId = 0 and Table is nullptr
    Table()
        : uniqueId(0)
    {
<<<<<<< HEAD
    }

    Elem *addEntry(const std::string &name);
=======
        printf("Default constructor is called\n");
    }

    Elem *addEntry(char *name);
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a

    // Add one more Feature... To Lookup by ID
    Elem *lookUpById(int id);

<<<<<<< HEAD
    Elem *lookUp(const std::string &name);
=======
    Elem *lookUp(char *name);
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
};

/*
        Add functionalities to the SymbolTable class
*/

template <class Elem>
<<<<<<< HEAD
Elem *Table<Elem>::addEntry(const std::string &name)
{

    Elem *existingEntry = lookUp(name);

    if (existingEntry != nullptr)
    {
        std::cout << "Entry " << name << " already Exists" << std::endl;
        return existingEntry;
    }

    size_t lenEntry = name.size();
=======
Elem *Table<Elem>::addEntry(char *name)
{
    // Lookup Entry
    // If Entry Found, Return Entry
    // Else create a new
    Elem *existingEntry = lookUp(name);
    if (existingEntry != nullptr)
        return existingEntry;

    int lenEntry = strlen(name);
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
    // Create a new Entry
    Elem *newEntry = new Elem(name, lenEntry, uniqueId++);

    table[name] = newEntry;
    printf("New Entry Added In the Table\n");

    return newEntry;

    // return nullptr;
}

template <class Elem>
<<<<<<< HEAD
Elem *Table<Elem>::lookUp(const std::string &name)
{
    // return table[name];
    if (table[name])
        std::cout << "Entry " << table[name] << " found in string table" << std::endl;
=======
Elem *Table<Elem>::lookUp(char *name)
{
    // return table[name];
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
    return table[name];
}

template <class Elem>
Elem *Table<Elem>::lookUpById(int id)
{
    for (auto entry : table)
    {
        Elem *valueElem = entry.second;
        if (valueElem->uniqueId == id)
            return valueElem;

        return nullptr;
    }
}

class StringTable : public Table<StringEntry>
{
};

<<<<<<< HEAD
class IntTable : public Table<IntEntry>
{
};

class IdTable : public Table<IdEntry>
=======
class IntTable : public Table<StringEntry>
{
};

class IdTable : public Table<StringEntry>
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
{
};

// Why am i not getting it here
// It means in some External file, i have declared stringTable(in SymTab.cpp)
// It uses same variable
extern StringTable stringTable;
extern IntTable intTable;
extern IdTable idTable;
#endif