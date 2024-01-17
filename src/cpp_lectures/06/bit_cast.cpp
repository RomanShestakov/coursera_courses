#include<iostream>
#include<bit>
#include <memory>

//https://www.youtube.com/watch?v=LDoCQzSd3xo
// 1:19

int main() {

    float p = 1.0;

    // this is UB - strict aliasing violation
    // [basic.lval/11]
    int n = *reinterpret_cast< int* >( &p );
    std::cout << "N:" << n << std::endl;

    // instead can do
    int m = std::bit_cast< int >( p );
    std::cout << "M:" << m << std::endl;

    return 0;
}
