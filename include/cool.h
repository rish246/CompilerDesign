#ifndef COOL_H_
#define COOL_H_

#include <iostream>
/* a type renaming */
typedef int Boolean;
class Entry;
typedef Entry *Symbol;

Boolean copy_Boolean(Boolean);
void assert_Boolean(Boolean);
void dump_Boolean(std::ostream &, int, Boolean);

Symbol copy_Symbol(Symbol);
void assert_Symbol(Symbol);
void dump_Symbol(std::ostream &, int, Symbol);

#endif
