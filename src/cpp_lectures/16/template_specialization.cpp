#include<iostream>

//https://www.youtube.com/watch?v=UrL5gdW2JOM&list=PL3BR09unfgciJ1_K_E914nohpiOiHnpsK&index=16
// 4:05

template <typename T> struct S {
    void dump() { std::cout << "for all\n"; }
};

template <> struct S<int> {
    void dump() { std::cout << "for int\n"; }
};

int main() {
    S<int> s1;
    s1.dump();

    S<double> s2;
    s2.dump();

    return 0;
}
