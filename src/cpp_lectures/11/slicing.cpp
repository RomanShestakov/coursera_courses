#include<iostream>

// https://www.youtube.com/watch?v=P1LcWg6K3WE
// 43:54

struct Base {
    virtual ~Base() { std::cout << "~Base" << std::endl; }
};


struct Derived : public Base {
    ~Derived() { std::cout << "~Derived" << std::endl; }
};

int main() {
    try {
        // Derived() is LVALUE!!!
        // special case for exceptions
        throw Derived();
    }
    //#if defined(CORR) {
    // catch(Base &b ) {
    // }
    //#else
    catch( Base b ){
    }
}
//    #endif
