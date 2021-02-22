#include "../../include/StringTab.hpp"
#include <string.h>

// Create a copy constructor for Entry class
Entry::Entry(const std::string &name, size_t l, int i)
    : m_value(name), m_length(l), m_id(i)
{
    std::cout << "Created new Entry : " << m_value << std::endl;
}

std::string Entry::getValue()
{
    return m_value;
}

// Three Tables for This thing

// Declare The StringTable here
// StringTables are used to capture the values of the strings in a program.. Just efficient storage
// My implementation is right... We just have to change the name of the Class
// Everything else is just the same
StringTable stringTable;
IdTable idTable;
IntTable intTable;