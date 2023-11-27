#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>

int main() {

    std::unordered_map<char, std::vector<int>> data;

    std::string str;
    char l;
    std::cin >> str >> l;

    for( int i = 0; i < str.size(); ++i ) {
        data[ str[ i ] ].push_back( i );
    }

    if( data[ l ].size() == 0 ) {
        std::cout << -2 << std::endl;
    }
    else if( data[ l ].size() == 1 ) {
        std::cout << -1 << std::endl;
    }
    else {
        std::cout << data[ l ].back() << std::endl;
    }
}
