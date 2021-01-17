symtest:	SymTab.o SymTableTest.o
	g++ SymTab.o SymTableTest.o -o symtest 

SymTab.o:	SymTab.cpp
	g++ -c SymTab.cpp 

SymTableTest.o:	SymTableTest.cpp
	g++ -c SymTableTest.cpp 

clear:
	rm *.o symtest