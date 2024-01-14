#include<iostream>
#include<cassert>
// https://www.youtube.com/watch?v=_mLDaU4wSOo
// 31:00

int main() {

    int x = 4;
    int&& y = x + 1;

    std::cout << "y:" << y << " x:" << x << std::endl;
    std::cout << "&y:" << &y << " &x:" << &x << std::endl;

    int&& z = std::move( x );

    z = z + 1;

    //
    // https://www.youtube.com/watch?v=_mLDaU4wSOo
    // 59:21
    // nothing appens here - for int move is not defined
    int yy = std::move( x );

    assert( yy == x );

    std::cout << "yy:" << yy << " x:" << x << std::endl;

    std::cout << "z:" << y << " x:" << x << std::endl;
    std::cout << "&z:" << &z << " &x:" << &x << std::endl;



    // cross ref
    //int&& b = x; // fail
    // int &v = x + 1; // fail

    const int& d = x + 1; //OK - const ref prolongs the live of object

    //int &&e = y; // fail
    int& g = y;

    return 0;
}
