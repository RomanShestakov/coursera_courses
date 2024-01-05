#include <iostream>
#include <ostream>

// https://www.youtube.com/watch?v=TQ5VPnKWqoY
// 33:54
int main() {
    int ai[ 20 ] = { 0 };
    int *api[ 20 ] = {nullptr};
    int (*pai)[ 20 ] = &ai;
    int (&rai)[20] = ai;

    std::cout << ai << "+1=" << api + 1 << std::endl;
    std::cout << pai << "+1=" << pai + 1 << std::endl;

    rai[ 2 ] = 40;
    (*pai)[ 2 ] +=2;
    std::cout << ai[ 2 ] << std::endl;

    return 0;
}
