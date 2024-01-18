#include<iostream>
#include<bit>
#include <memory>

// https://www.youtube.com/watch?v=LDoCQzSd3xo
// 1:05
struct Foo {
    operator long() { return 42; }
};

void foo( int x ) { std::cout << "foo(int x)" << std::endl; };
void foo( Foo x ) { std::cout << "foo(Foo x)" << std::endl; };

int main() {

    Foo f;

    foo( f ); // call foo( Foo x )
    foo(+f ); // call foo( int x )

    return 0;
}
