#include<iostream>

// https://www.youtube.com/watch?v=_mLDaU4wSOo
// 1:02

// rule of five
// copy ctr
// move ctr
// copy operator
// move operator
// destructor
template<typename T>
struct SillyPointer {
    T* ptr_;

    SillyPointer( T* ptr = nullptr ) : ptr_{ ptr } {}
    ~SillyPointer() { delete ptr_; }
};

template<typename T>
void swap( T& lhs, T& rhs) {
    T tmp = std::move( lhs );
    lhs = std::move( rhs );
    rhs = std::move( tmp );
}


int main() {

    int* ptr1 = new int;
    int* ptr2 = new int;

    auto S1 = new SillyPointer< int >( ptr1 );
    auto S2 = new SillyPointer< int >( ptr2 );

    // this is segfault
    swap( S1, S2);

    delete ptr1;
    delete ptr2;
    delete S1;
    delete S2;

    return 0;
}
