#include<iostream>
#include<bit>

//https://www.youtube.com/watch?v=LDoCQzSd3xo
// 1:19

int main() {

    float p = 1.0;

    int m = std::bit_cast< int >( p );

    std::cout << "M:" << m << std::endl;

    return 0;
}
