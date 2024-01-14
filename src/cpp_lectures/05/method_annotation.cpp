#include<iostream>

// https://www.youtube.com/watch?v=_mLDaU4wSOo
// 39::00

struct S {
    int n = 10;
    int& foo() & { return n; };
    int& foo() && { return n; };
};

struct SS {
    int n = 10;
    int& foo() & { return n; };
};

int main() {

    extern S bar();
    S x {};

    //std::cout << "foo()&: " << x.foo() << " foo()&&: " << bar().foo() << std::endl;

    // https://www.youtube.com/watch?v=_mLDaU4wSOo
    // 41::00
    //auto d = SS{}.foo(); // compilation err as SS is rvalue and foo() can only be called for lvalue
    return 0;
}
