#include <iostream>

// example shows to dangling pointer could happen

int foo() {
    int a = 3;
    int *pc;
    {
        int c = a + 3;
        pc = &c;
    } // c scope ends - *pc pointer is dangling

    return a + *pc;

}


int main() {

    std::cout << "foo:" << foo() << std::endl;

    return 0;
}
