#ifndef STRING_TAB_H
#define STRING_TAB_H

#include <iostream>
#include <unordered_map>
#include <string>
// Define our Entry class
class Entry
{
protected:
    std::string m_value;
    size_t m_length;
    int m_id;

public:
    Entry() {}

    Entry(const std::string &, size_t l, int _id);

    std::string getValue();
};

// Define StringEntry
class StringEntry : public Entry
{
public:
    StringEntry(const std::string &v, size_t l, int _id)
        : Entry(v, l, _id)
    {
    }
};
// Define IntEntry
class IntEntry : public Entry
{
public:
    IntEntry(const std::string &v, size_t l, int _id)
        : Entry(v, l, _id)
    {
    }
};
// Define IdEntry
class IdEntry : public Entry
{
public:
    IdEntry(const std::string &v, size_t l, int _id)
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
public:
    // Table: Map from lexeme -> Entry
    std::unordered_map<std::string, Elem *> table; // Ptr to Table is stored

    int uniqueId;

public:
    // Default constructor
    // Set uniqueId = 0 and Table is nullptr
    Table()
        : uniqueId(0)
    {
    }

    Elem *addEntry(const std::string &name);

    // Add one more Feature... To Lookup by ID
    Elem *lookUpById(int id);

    Elem *lookUp(const std::string &name);
};

/*
        Add functionalities to the SymbolTable class
*/

template <class Elem>
Elem *Table<Elem>::addEntry(const std::string &name)
{

    Elem *existingEntry = lookUp(name);

    if (existingEntry != nullptr)
    {
        std::cout << "Entry " << name << " already Exists" << std::endl;
        return existingEntry;
    }

    size_t lenEntry = name.size();
    // Create a new Entry
    Elem *newEntry = new Elem(name, lenEntry, uniqueId++);

    table[name] = newEntry;
    printf("New Entry Added In the Table\n");

    return newEntry;

    // return nullptr;
}

template <class Elem>
Elem *Table<Elem>::lookUp(const std::string &name)
{
    // return table[name];
    if (table[name])
        std::cout << "Entry " << table[name] << " found in string table" << std::endl;
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

class IntTable : public Table<IntEntry>
{
};

class IdTable : public Table<IdEntry>
{
};

// Why am i not getting it here
// It means in some External file, i have declared stringTable(in SymTab.cpp)
// It uses same variable
extern StringTable stringTable;
extern IntTable intTable;
extern IdTable idTable;
#endif