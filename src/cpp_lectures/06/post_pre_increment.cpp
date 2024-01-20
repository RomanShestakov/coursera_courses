#include<iostream>
#include<vector>

//    https://www.youtube.com/watch?v=lHxf3_uHbKg
// 26:15

int main() {

    int x = 42, y, z;
    y = ++x;
    // y = 43, x == 43
    std::cout << "y:" << y << "  x:" << x << std::endl;

    z = y++;

    // z = 43, y == 44
    std::cout << "z:" << z << "  y:" << y << std::endl;


    //efficient loop
    //    https://www.youtube.com/watch?v=lHxf3_uHbKg
    // 29:48

    std::vector< int > v(100, 1);
    using it_t = typename std::vector< int >::iterator;

    // not efficient
    for( it_t it = v.begin(); it < v.end(); it++ ) {
    }

    // more efficient
    // no need to recalc v.end() and use pre-condition
    // this is boost coding style
    for( it_t it = v.begin(), ite = v.end(); it != ite; ++it ) {
    }


    return 0;
}
