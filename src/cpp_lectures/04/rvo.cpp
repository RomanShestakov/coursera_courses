#include<iostream>

//https://www.youtube.com/watch?v=duDyVgMFyug
// 1:06

// return valur optimisation

struct foo {
    int i = 0;
    foo() { std::cout << "foo:foo()" << std::endl; }
    //foo( const foo& ) = delete;
    foo( const foo& ) { std::cout << "foo:foo( const foo& )" << std::endl; }
    ~foo() { std::cout << " foo::~foo()" << std::endl; }
};

foo bar() { foo local_foo; return local_foo; }
void use( foo& ) { return; }

int main() {
    foo f = bar();
    use( f );
    return 0;
}
