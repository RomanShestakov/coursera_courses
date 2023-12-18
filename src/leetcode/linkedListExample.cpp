#include<iostream>

struct LinkedNode {
    int val_;
    LinkedNode *next_;
    LinkedNode( int val ) : val_( val ) {}
};

int main() {

    auto a = new LinkedNode( 1 );
    auto b = new LinkedNode( 2 );
    auto c = new LinkedNode( 3 );
    auto head = a;

    a -> next_ = b;
    b -> next_ = c;
    c -> next_ = nullptr;

    while( head ) {
        std::cout << head -> val_ << " " << std::endl;
        head = head -> next_;
    }

    delete a;
    delete b;
    delete c;

    return 0;
}
