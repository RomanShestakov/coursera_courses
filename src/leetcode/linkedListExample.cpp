#include<iostream>
#include<memory>

struct LinkedNode {
    bool verbose_ = false;
    int val_;
    LinkedNode *next_ = nullptr;
    LinkedNode *prev_ = nullptr;
    LinkedNode( int val ) : val_( val ) {}

    ~LinkedNode() {
        if( verbose_ ) {
            std::cout << "Removing:" << val_;
        }
    }

    LinkedNode* addNode( LinkedNode* node ) {
        node -> next_ = next_;
        next_ = node;
        node -> prev_ = this;
        return node;
    }

    LinkedNode* deleteNode() {

        if( prev_ ) prev_ -> next_ = next_;
        if( next_ ) next_ -> prev_ = prev_;
//        delete this;
        return prev_;
    }

};

int main() {

    auto a = new LinkedNode( 1 );
    auto b = new LinkedNode( 2 );
    auto c = new LinkedNode( 3 );
    auto d = new LinkedNode( 4 );
    auto e = new LinkedNode( 5 );

    auto head = a;
    head -> addNode( b ) -> addNode( c ) -> addNode( d ) -> addNode( e );

    auto fast = head;
    auto slow = head;
    while( fast != nullptr && fast -> next_ != nullptr ) {
        std::cout << head -> val_ << " ";
        slow = slow -> next_;
        fast = fast -> next_ -> next_;
    }

    std::cout << "fast:" << fast -> val_ << " slow:" << slow -> val_ << std::endl;


    delete a;
    delete b;
    delete c;
    delete d;
    delete e;

    return 0;
}
