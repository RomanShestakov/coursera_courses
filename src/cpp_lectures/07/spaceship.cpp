#include <compare>
#include <ios>
#include<iostream>

//https://youtu.be/lHxf3_uHbKg?si=xyC_s7yRRdJPHaD_
// 1:02

struct MyInt {
    int x_;
    MyInt( int x ) : x_{ x } {}

    auto operator<=>( const MyInt& rhs ) const = default;

    // // this will auto-generate all comparison operations
    // std::strong_ordering operator<=>( const MyInt& rhs ) const {
    //     return x_ <=> rhs.x_;
    // }

};

int main() {

    int a = 4, b = 4, c = 5;

    auto ac = a <=> c;
    std::cout << std::boolalpha << std::endl;
    std::cout << ( ac < 0 ) << std::endl;
    std::cout << ( ( a <=> b ) == 0 ) << std::endl;
    std::cout << ( ( a <=> c ) > 0 ) << std::endl;


    //
    MyInt x{ 5 };
    MyInt y{ 6 };

    std::cout << ( x < y ) << std::endl;
    std::cout << ( x >= y ) << std::endl;

    return 0;
}
