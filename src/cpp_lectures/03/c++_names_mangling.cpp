#include<iostream>

// compile with : g++ -g0 -O1 -masm=intel -S c++_names_mangaling.cpp

struct S{
    int foo( int v ){ return v; }
};

int foo( S* p, int x ) { return p -> foo( x ); };

int foo( int x ) { return x; };


// extern C guarantees stable name without mangaling
extern "C" int bar( int x ) { return x; };
