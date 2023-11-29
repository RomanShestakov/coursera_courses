#include<iostream>
#include <string>

bool isPolindrom( const std::string& str ) {
    int l = 0;
    int r = str.size() - 1;

    while( l <= r ) {
        if( str[ l++ ] != str[ r-- ] ) {
            return false;
        }
    }

    return true;
}


int main() {
    std::string str;

    std::cin >> str;

    std::cout << std::boolalpha << isPolindrom( str ) << std::endl;

    return 0;
}
