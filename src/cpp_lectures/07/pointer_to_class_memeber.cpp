#include<iostream>

// https://youtu.be/lHxf3_uHbKg?si=75byTA0Yn9_RYerX
// 1:14

// operator ->*

struct MyClass {
    int doIt( double a, int b ) const { std::cout << a << " " << b << std::endl; return a; }
};

int main() {

    using const_ptr = int( MyClass::* )( double, int ) const;

    // one way to call
    const_ptr ptr = &MyClass::doIt;
    MyClass c;

    // .* - it is a call to class memebe or class function
    ( c.*ptr )( 1, 3 );

    // second syntax
    MyClass *p = &c;
    (p ->*ptr)( 1,2 );

}
