#include<stdio.h>
#include<stdlib.h>

int main() {

    // not cleaned mem
    int* ptr = malloc( 10 * sizeof( int ) );

    // initialized mem
    int* ptrc = calloc( 10, sizeof( int ) );

    free( ptr );
    free( ptrc );

    return 0;
}
