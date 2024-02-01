#include<iostream>

//https://www.youtube.com/watch?v=UrL5gdW2JOM&list=PL3BR09unfgciJ1_K_E914nohpiOiHnpsK&index=16
// 1:18

struct S {
    struct subtype {};
};

template <typename T> int foo (const T& x ) {
    //disabuation
    typename T::subtype *y;
    return 42;
};



template< typename T > struct B {
    template< typename U> void foo(){}
};

template<typename T> void bar() {
    B<T> b;

    // need to use template becuae foo is template function
    b.template foo<T>();
}

int main() {
    foo( S{} );
    return 0;
}
