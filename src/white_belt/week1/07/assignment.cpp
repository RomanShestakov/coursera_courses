#include<iostream>
#include<vector>

int main() {

    int a;
    std::vector<int> bits;

    std::cin >> a;

    while( a > 0 ) {
        bits.push_back( a % 2);
        a = a / 2;
    }

    for(int i = bits.size() - 1; i >= 0; --i ){
        std::cout << bits[ i ];
    }

    std::cout << std::endl;

    return 0;
}
