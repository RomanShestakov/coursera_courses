#include <initializer_list>
#include<iostream>
#include <vector>

//https://www.youtube.com/watch?v=KZ24E8pWNwg&list=PL3BR09unfgciJ1_K_E914nohpiOiHnpsK&index=18
// 39:24

struct S {
    S( int n ) {};
    S( std::initializer_list<int> il) {}
};


int main() {
    S s1(1);
    S s2{ 1 };


    // 3 elements, each == 14
    // [ 14, 14, 14 ]
    std::vector v( 1, 14);

    // [ 1, 14 ]
    std::vector v2{ 1, 14};

    return 0;
}
