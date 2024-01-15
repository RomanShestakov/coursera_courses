#include<iostream>

// https://www.youtube.com/watch?v=LDoCQzSd3xo
// 6:00

class S {
    int m_ = 10;
public:
    int get() { return m_; };
    static int get_s( const S* s) { return s -> m_; }
    friend int get_f( const S* s);
};

int get_f( const S* s ) { return s -> m_; };

int main() {

    S s;

    std::cout << s.get() << " " << S::get_s( &s ) << " " << get_f( &s ) << std::endl;

    return 0;
}
