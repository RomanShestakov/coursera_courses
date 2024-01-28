#include<iostream>
#include <list>

// https://www.youtube.com/watch?v=d0iqsUx_Aow
// 33:44

void* operator new( std::size_t n ) {
    void *p = malloc( n );
    if( !p ) throw std::bad_alloc();
    printf( "Alloc: %p, size is %zu \n", p, n );
    return p;
}

void operator delete( void *mem ) noexcept {
    printf( "free: %p\n", mem );
    free( mem );
}


int main() {

    std::list< int > l;
    l.push_back( 42 );
    return 0;
}
