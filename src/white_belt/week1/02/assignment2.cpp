#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int main(int argc, char* argv[]) {

    std:vector< std::string > v;
    std::string str;

    while( std::getline( std::cin, str, ' ' ) ) {
        v.push_back( str );
    }

    auto it = std::min_element( v.begin(), v.end() );

    std::cout << *it << std::endl;

}
