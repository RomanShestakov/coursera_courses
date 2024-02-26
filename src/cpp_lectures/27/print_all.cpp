#include<iostream>


template <typename H, typename... T>
void print_all(H head, T... tail) {
    std::cout << head;
    if constexpr( sizeof...(tail) > 0 ) {
        std::cout << ",";
        print_all( tail...);
    }
}


int main() {
    print_all(1,2,3,4,5);
    std::cout << std::endl;
}
