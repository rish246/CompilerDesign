#include "../../include/StringTab.hpp"
#include <string.h>

Entry::Entry(char *v, int l, int i)
    : length(l), id(i)
{
    printf("New Entry Created\n");
    // Create a new Char array
    value = new char[length + 1];

    // Copy v to value
    // strncpy -> copy first (length) characters from v to value
    // Strncpy(dest, src, len)
    strncpy(value, v, length);
}

char *Entry::getValue()
{
    return value;
}

// Three Tables for This thing

// Declare The StringTable here
// StringTables are used to capture the values of the strings in a program.. Just efficient storage
// My implementation is right... We just have to change the name of the Class
// Everything else is just the same
StringTable stringTable;
IdTable idTable;
IntTable intTable;