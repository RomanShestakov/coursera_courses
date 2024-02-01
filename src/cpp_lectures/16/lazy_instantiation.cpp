#include<iostream>

// https://www.youtube.com/watch?v=UrL5gdW2JOM&list=PL3BR09unfgciJ1_K_E914nohpiOiHnpsK&index=16
// 43:00

template <int N > struct S {
    typedef char block[ N ];
};

template <typename T, int N> struct D {
    void test_lazy() {
        S< N > no_boom_yet;
    }
};


// require full specialization
// template struct D<int, -2>;



template <typename T >
T max( T x, T y ){ return x > y ? x : y; }


extern template double max< double>( double x, double y);

int main() {
    D<int, -2> s;
    //s.test_lazy();

    return 0;
}
