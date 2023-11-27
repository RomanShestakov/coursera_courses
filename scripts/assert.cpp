#include<iostream>
#include<string>

int main(int argc, char* argv[]) {

    if( argc != 3 ) {
        std::cout << "Usage: assert < progname expectedResult>" << std::endl;
        exit( 1 );
    }

    std::string name = argv[ 1 ];
    std::string expected = argv[ 2 ];
    std::string result;

    std::getline(std::cin, result );

    if( result != expected ) {
        std::cout << name << " Found:" << result << " expected:" << expected << " FAIL" << std::endl;
        return 1;
    }
    else {
        std::cout << name << " Found:" << result << " expected:" << expected << " PASSED" << std::endl;
    }

    return 0;
}
