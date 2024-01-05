#include <iostream>

// example how dangling reference could happen
//
// https://www.youtube.com/watch?v=TQ5VPnKWqoY
// 16:35

int main() {

    int *pa = new int[ 3 ];
    int &a = pa[ 2 ];

    for( int i = 0; i < 3; i++ ) {
        pa[ i ] = i;
    }

    std::cout << "before delete a:" << a << std::endl;

    delete[] pa;

    // at this point &a is dangling
    std::cout << "after delete a:" << a << std::endl;

    return 0;
}
