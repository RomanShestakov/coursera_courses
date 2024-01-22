#include<iostream>
#include<memory>

enum { SZ = 1000 };

struct CDetelerTy {
    void operator()( int *t ){ delete[] t; }
};


int main() {
    std::unique_ptr<int, CDetelerTy> Uic{ new int[ SZ ]};
    return 0;
}
