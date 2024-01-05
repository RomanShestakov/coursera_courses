#include <iostream>

int foo() {
    int a = 3;
    return a;
}

#if 0
int& foo2() {
    int a = 3;
    // returns dangling ref
    return a;
}
#endif

int main() {

    // const ref prolongs life of temp object
    const int& lr = 0;
    std::cout << "lr:" << lr << std::endl;

    const int& lr2 = 42 + foo();
    std::cout << "lr2:" << lr2 << std::endl;

#if 0
    // this is UB as foo returns dangling ref
    const int& lr3 = 42 + foo();
    std::cout << "lr3:" << lr3 << std::endl;
#endif

    //****************
    // life of temp objects
    struct S{
        int x;
        const int& y;
    };

    // this is ok as x if an object
    S x{ 1, 2 };

    // dangling ref to S.y as S
    S *p = new S{ 1 ,2 };

    delete p;



    // https://www.youtube.com/watch?v=TQ5VPnKWqoY
    // 27:02
    // decaying
    int arr[ 5 ] = {1,2,3,4,5};
    int *t = arr + 3;
    std::cout << "t" << *t << std::endl;

    return 0;
}
