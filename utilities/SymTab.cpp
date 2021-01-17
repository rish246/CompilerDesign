#include "../include/SymTab.hpp"
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

// Declare The StringTable here
StringTable stringTable;
IdTable idTable;
IntTable intTable;