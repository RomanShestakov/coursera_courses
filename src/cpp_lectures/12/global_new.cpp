#include<iostream>
#include <new>
#include <type_traits>


// https://www.youtube.com/watch?v=d0iqsUx_Aow
// 31:44

int main() {

    // C
    void *p = malloc( 10 );
    free( p );

    // c++

    // allocate and initialize
    int *n = new int( 10 );
    delete( n );

    // only allocate
    n = (int *) ::operator new( sizeof( int ) );

    delete( n );

    return 0;
}
