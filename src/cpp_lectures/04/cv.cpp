#include<iostream>

// https://www.youtube.com/watch?v=duDyVgMFyug
// 1:11

// CV - const volatile classificator

struct S {
    int foo() const { return 42; }
    int bar() volatile { return 42; }
    int buz() const volatile { return 42; }

};

int main() {

    // cant be changed
    const int c = 10;

    // v can change on its own independent from your code
    // but you can still change it from insed the code
    volatile int v = 10;

    // volatile that you code can't chnage
    const volatile int m = 42;

}
