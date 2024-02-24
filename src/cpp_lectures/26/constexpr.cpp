#include<iostream>
#include<climits>

//https://www.youtube.com/watch?v=zGT2CAoW3YI&list=PL3BR09unfgciJ1_K_E914nohpiOiHnpsK&index=26
//57:00

template<typename T>
struct my_numeric_limits;

template<>
struct my_numeric_limits<char> {
    static constexpr size_t max() { return CHAR_MAX; }
};



int main() {
    constexpr size_t arrsz = my_numeric_limits<char>::max();
    int arr[ arrsz ];
    return 0;
}
