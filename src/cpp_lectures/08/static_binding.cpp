#include<iostream>

struct A {
    virtual int foo( int a = 10 ) { return a; }
};


struct B : public A {
    int foo( int a = 20 ) override { return a; }
};

int main() {

    A* a = new B();

    std::cout << "A:" << a -> foo() << std::endl;

    delete a;
}
