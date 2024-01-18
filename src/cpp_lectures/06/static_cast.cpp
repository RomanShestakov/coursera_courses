#include<iostream>
#include<bit>
#include <memory>

// https://www.youtube.com/watch?v=LDoCQzSd3xo
// 49:00

struct T {};
struct S { explicit S( T& t  ){}; };

void foo( S s ){ };

int main() {

    T t;
    // foo( t ); error - can do implicit conversion from S -> T

    // explici cast
    foo( static_cast< S >( t ) );

    // copy init
    S ss = static_cast< S > ( t );

    return 0;
}
