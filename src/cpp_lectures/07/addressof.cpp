#include<iostream>
#include <memory>

//https://youtu.be/lHxf3_uHbKg?si=KGazuHyaqIjWnKiO
// 1:11

struct MyInt {
    int x_;
    MyInt( int x ) : x_{ x } {}
    auto operator<=>( const MyInt& rhs ) const = default;

    // take address is overloaded
    int operator&() { return 42; }

};

int main() {

    auto s = new MyInt( 5 );

    // allows to take address if perator & is overloaded
    std::cout << std::addressof( s );

    delete s;
}
