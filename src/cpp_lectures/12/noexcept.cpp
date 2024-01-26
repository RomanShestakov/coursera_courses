#include<iostream>
#include <type_traits>

//https://www.youtube.com/watch?v=d0iqsUx_Aow
// 10:15
template<typename T>
T copy(T const& orig ) noexcept(std::is_fundamental<T>::value) {
    return orig;
}

template<typename T>
T copy2(T const& orig ) noexcept(noexcept(T(orig))) {
    return orig;
}


int main() {

    return 0;
}
