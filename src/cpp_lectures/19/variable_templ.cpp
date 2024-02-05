#include<iostream>

template<typename ... Args>
void foo( Args ... args ) {
    std::cout << "Size Args:" << sizeof ... ( Args ) << std::endl;
    std::cout << "Size args:" << sizeof ... ( args ) << std::endl;
    // for( auto el : args ) {
    // }
}

// void foo( Args ... args ) {
// }

int main() {
    foo( 1, 2 );
    foo();
}
