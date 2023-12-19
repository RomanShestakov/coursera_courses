#include<iostream>
#include<memory>

struct LinkedNode {
    bool verbose_ = false;
    int val_;
    LinkedNode *next_ = nullptr;
    LinkedNode *prev_ = nullptr;
    LinkedNode( int val ) : val_( val ) {}

    ~LinkedNode() {
        std::cout << "Removing:" << val_ << std::endl;
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
        return prev_;
    }

};

int main() {

    auto a = std::make_unique< LinkedNode >( 1 ) ;
    auto b = std::make_unique< LinkedNode >( 2 ) ;
    auto c = std::make_unique< LinkedNode >( 3 ) ;
    auto d = std::make_unique< LinkedNode >( 4 ) ;
    auto e = std::make_unique< LinkedNode >( 5 ) ;

    auto head = a.get();
    head -> addNode( b.get() ) -> addNode( c.get() ) -> addNode( d.get() ) -> addNode( e.get() );

    auto fast = head;
    auto slow = head;
    while( fast != nullptr && fast -> next_ != nullptr ) {
        std::cout << head -> val_ << " ";
        slow = slow -> next_;
        fast = fast -> next_ -> next_;
    }

    std::cout << "fast:" << fast -> val_ << " slow:" << slow -> val_ << std::endl;

    return 0;
}
