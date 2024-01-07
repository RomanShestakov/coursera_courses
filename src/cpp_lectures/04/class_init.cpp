#include<iostream>

// https://www.youtube.com/watch?v=duDyVgMFyug
// 26:20

struct S {
    int k_ = 0;
    S() { std::cout << "Default" << std::endl; }
    S( int k ) { std::cout << "Direct" << std::endl; }
};

struct Node {
    S key_;
    int val_ = 0;

    // // S constructor is called twice - one default . then direct
    // Node( int key, int val ) {
    //     key_ = key;
    //     val_ = val;
    // }

    // s constructor is called once
    Node( int key, int val ) : key_( key ), val_( val ) {}


};

int main() {

    auto node = Node( 5,6);

    return 0;
}
