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
    int val_ {}; // value init - sets val_ = 0
    int val2_; // not init -will have some garbage

    Node( int key ) : key_( key ) {}
    Node( int key, int val ) : Node{ key } {} // delegate init to another constructor


};

int main() {

    auto node = Node( 5,6);

    std::cout << "val_: " << node.val_ << " val2:" << node.val2_ << std::endl;

    return 0;
}
