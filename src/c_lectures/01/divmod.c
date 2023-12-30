#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void read_input( int* a, int* b) {
    printf( "input a and b:");
    int nitems = scanf("%d%d", a, b);
    if( nitems != 2 || b == 0 ) {
        printf( "invalid input ");
        abort();
    }
}

int main() {
    int a, b, p, q;
    read_input( &a, &b );
    assert( b != 0 );
    p = a / b;
    q = a % b;
    printf( "p = %d, q = %d \n", p, q);
    return 0;
}
