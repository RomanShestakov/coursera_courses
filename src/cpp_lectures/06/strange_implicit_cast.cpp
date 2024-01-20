#include<iostream>
#include<string>
#include<cassert>

struct S {
    S( std::string s ) {}
    S( std::wstring s ) {}
};

bool operator==( S s, S w ) { return true; }

int main() {

    std::string s { "foo" };
    std::wstring w { L"bar" };

    if( s == w ) {
        std::cout << "WHAT!" << std::endl;
    }

    return 0;

}
