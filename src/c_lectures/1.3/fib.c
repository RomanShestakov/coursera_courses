#include<stdio.h>

unsigned long long fib( unsigned n ) {
    unsigned long long first = 0ull;
    unsigned long long second = 1ull;
    int idx = 0;

    if( n == 0 ) return first;
    for( idx = 2; idx <= n; ++idx ) {
        unsigned long long tmp = second;
        second = second + first;
        first = tmp;
    }
    return second;
}



int main() {
    unsigned n;
    int res;
    unsigned long long t;

    printf( "enter N:" );
    res = scanf( "%u", &n );

    if( res != 1 ) {
        printf( "not correct imput" );
        abort();
    }

    t = fib( n );
    printf( "result %ull", t );

    return 0;

}
