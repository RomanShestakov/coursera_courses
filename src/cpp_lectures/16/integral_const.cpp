#include <algorithm>
#include <initializer_list>
#include <ios>
#include<iostream>
#include <random>
#include <type_traits>
#include <vector>

const int TMAX = 9;

// https://www.youtube.com/watch?v=KZ24E8pWNwg&list=PL3BR09unfgciJ1_K_E914nohpiOiHnpsK&index=18
// 56:00

template<typename T, T v>
struct integral_constant {
    static const T value = v;
    typedef T value_type;
    typedef integral_constant type;
    operator value_type() const { return value; }
};


// https://www.youtube.com/watch?v=KZ24E8pWNwg&list=PL3BR09unfgciJ1_K_E914nohpiOiHnpsK&index=18
// 1:02

template<typename T, typename U>
struct is_same : std::false_type{};

template<typename T >
struct is_same<T,T> : std::true_type{};

template< typename T, typename U>
using is_same_t = typename is_same< T,U>::type;


int main() {
    using ic6 = integral_constant<int, 6 >;
    auto n = 7 * ic6{};


    std::cout << std::boolalpha;
    std::cout << is_same_t<int, int>() << std::endl;
    std::cout << is_same_t<int, char>() << std::endl;



    // how to fill with random numbers
    std::random_device rd;
    std::default_random_engine reng(rd());

    std::uniform_int_distribution<int> dist( 0, TMAX );

    std::vector<int> v;
    std::generate( v.begin(), v.end(), [&dist, &reng]{ return dist(reng) ;} );

    return 0;

}
