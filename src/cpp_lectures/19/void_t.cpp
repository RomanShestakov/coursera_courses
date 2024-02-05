#include <ios>
#include<iostream>
#include <type_traits>


// https://www.youtube.com/watch?v=JC8yVbvDxyg&list=PL3BR09unfgciJ1_K_E914nohpiOiHnpsK&index=19
// 40:43

template<typename, typename = void>
struct has_typedef_foobar : std::false_type {};

template<typename T>
struct has_typedef_foobar< T, std::void_t< typename T::foobar > > : std::true_type{};

struct Foo {
    typedef float foobar;
};

struct Bar {};

int main() {
    std::cout << std::boolalpha;
    std::cout << has_typedef_foobar<Foo>() << std::endl;
    std::cout << has_typedef_foobar<Bar>() << std::endl;
}
