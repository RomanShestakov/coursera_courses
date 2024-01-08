#include<iostream>

// https://www.youtube.com/watch?v=duDyVgMFyug
// 1:15

struct MyString {
    char* buf_;
    size_t len_;

    // this is user defined type conversion
    // impliciti conversion from int -> Mystring
    MyString() = default;
    MyString( size_t len ) : buf_{ new char[ len ]{}}, len_{ len } {}
    //explicit MyString( size_t len ) : buf_{ new char[ len ]{}}, len_{ len } {}


    // operator to convert MyString into char*
    /* explicit */ operator char*(){ return buf_; }
};

void foo( MyString ){ return; };
void bar ( char* obj ) { return; }

int main() {

    foo( 42 );

    // how to use operator()
    MyString s;
    bar( s );
}
