#include<iostream>
#include<string>
#include <type_traits>
#include<utility>

// https://www.youtube.com/watch?v=zGT2CAoW3YI&list=PL3BR09unfgciJ1_K_E914nohpiOiHnpsK&index=26
// 1:12

template<typename T>
auto length( T value ) {
    if constexpr( std::is_integral<T>::value) {
        return sizeof( T );
    } else {
        return value.length();
    }
}


int main() {
    int a{ 5 };
    std::string b { "foo" };

    std::cout << length( a ) << " " << length( b) << std::endl;
    return 0;
}
