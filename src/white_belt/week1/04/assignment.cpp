#include<iostream>


int main(int argc, char* argv[]) {
    int a, b, c;

    std::cin >> a >> b;

    if( b == 0 ) {
        std::cout << "impossible" << std::endl;
    }
    else {
        c = a / b ;
        std::cout << c << std::endl;
    }

    return 0;
}
