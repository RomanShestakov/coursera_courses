#include <ios>
#include<iostream>
#include<utility>
#include <type_traits>


// https://www.youtube.com/watch?v=avnte_HqBKQ&list=PL3BR09unfgciJ1_K_E914nohpiOiHnpsK&index=20
// 3:33

struct fib {};


struct fibit {
    int curr = 1;
    int prev = 0;

    fibit& operator++() {
        prev = std::exchange(curr, curr + prev);
        return *this;
    }

    int operator*() { return curr; }
    auto operator <=>(const fibit&) const  = default;
};

fibit begin( fib ) { return fibit() ; }
fibit end( fib ){ return fibit(89, 55 ); }

int main() {

    for( auto f : fib() ) {
        std::cout << f << " ";
    }

    std::cout << std::endl;
}
