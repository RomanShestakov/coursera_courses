#include<iostream>


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

    return 0;
}
