#pragma once
#include<iostream>
#include<memory>
#include<unordered_set>


    // 707 dsign linked list
    //     Design your implementation of the linked list. You can choose to use a singly or doubly linked list
    // A node in a singly linked list should have two attributes: val and next. val is the value of the curren    // t node, and next is a pointer/reference to the next node.
    // If you want to use the doubly linked list, you will need one more attribute prev to indicate the previo    // us node in the linked list. Assume all nodes in the linked list are 0-indexed.

    // Implement the MyLinkedList class:

    // MyLinkedList() Initializes the MyLinkedList object.
    // int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, retur    //n -1.
    // void addAtHead(int val) Add a node of value val before the first element of the linked list. After the     //insertion, the new node will be the first node of the linked list.
    // void addAtTail(int val) Append a node of value val as the last element of the linked list.
    // void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list.    // If index equals the length of the linked list, the node will be appended to the end of the linked list.    // If index is greater than the length, the node will not be inserted.
    // void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.

    // Example 1:

    // Input
    // ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
    // [[], [1], [3], [1, 2], [1], [1], [1]]
    // Output
    // [null, null, null, null, 2, null, 3]

    // Explanation
    // MyLinkedList myLinkedList = new MyLinkedList();
    // myLinkedList.addAtHead(1);
    // myLinkedList.addAtTail(3);
    // myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
    // myLinkedList.get(1);              // return 2
    // myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
    // myLinkedList.get(1);              // return 3



    template< typename T>
    struct NodeTmpl {
        NodeTmpl( T val ) : val_( val ) {}
        NodeTmpl* prev_ = nullptr;
        NodeTmpl* next_ = nullptr;
        T val_;
    };

    template< typename T>
    class MyLinkedListTmpl {
        using Node = NodeTmpl< T >;
        std::unordered_set< std::unique_ptr< Node > > s_;
        Node* head_ = nullptr;
        Node* tail_ = nullptr;
        size_t length_ = 0;

    public:
        MyLinkedListTmpl() {}

        friend std::ostream& operator<<( std::ostream& os, const MyLinkedListTmpl<T>& obj ) {
            os << '[';
            auto h = obj.head_;
            while( h ) {
                os << h -> val_ << " ";
                h = h -> next_;
            }
            os << ']';
            return os;
        }

        T get(int index) {
            if( !head_ ) return -1;

            auto h = head_;
            while( index-- ) {
                if( !h -> next_ ) return -1;
                h = h -> next_;
            }
            return h -> val_;
        }

        void addAtHead(T val) {
            auto [ it, res ] = s_.emplace( std::make_unique< Node >( Node( val ) ) );
            it -> get() -> next_ = head_;
            head_ = it -> get();
            if( !tail_ ) tail_ = head_;
            length_++;
        }

        void addAtTail(T val) {
            auto [ it, res ] = s_.emplace( std::make_unique< Node >( Node( val ) ) );
            if( tail_ ) tail_ -> next_ = it -> get();
            tail_ = it -> get();
            length_++;
        }

        void addAtIndex(int index, int val) {
            if( index > length_ ) return;
            if( index == length_ ) return addAtTail( val );

            auto h = head_;
            while( --index ) {
                if( !h -> next_ ) return;
                h = h -> next_;
            }
            auto [ it, res ] = s_.emplace( std::make_unique< Node >( Node( val ) ) );
            it -> get() -> next_ = h -> next_;
            h -> next_ = it -> get();
        }

        void deleteAtIndex(int index) {
            if( index > length_ ) return;
            auto h = head_;
            while( --index ) {
                if( !h -> next_ ) return;
                h = h -> next_;
            }

            auto n = h -> next_;
            h -> next_ = h -> next_ -> next_;
            //s_.erase( n );

        }
    };

    using MyLinkedList = MyLinkedListTmpl<int>;

    /**
     * Your MyLinkedList object will be instantiated and called as such:
     * MyLinkedList* obj = new MyLinkedList();
     * int param_1 = obj->get(index);
     * obj->addAtHead(val);
     * obj->addAtTail(val);
     * obj->addAtIndex(index,val);
     * obj->deleteAtIndex(index);
     */
