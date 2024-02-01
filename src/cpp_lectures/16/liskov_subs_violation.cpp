#include<iostream>

//https://www.youtube.com/watch?v=UrL5gdW2JOM&list=PL3BR09unfgciJ1_K_E914nohpiOiHnpsK&index=16
// 1:05

template <typename T> struct S {
    void foo(){ std::cout << "foo" << std::endl; };
};

template <> struct S<int> {
    void bar(){ std::cout << "bar" << std::endl; };
};


int main() {
    S<double> sd;
    sd.foo();

    S<int> si;
    si.bar();

    return 0;
}
