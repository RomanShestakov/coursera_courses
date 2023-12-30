#include<stdio.h>
#include<assert.h>

int gcd( int x, int y ) {
    int q;
    assert( y != 0 );
    q = x % y;
    printf( "x=%d y=%d q=%d\n", x, y, q);
    if( q == 0 ) {
        return y;
    }
    return gcd( y, q );
}

/* int main() { */

/*     int a, b; */
/*     printf( "Input a and b\n"); */
/*     scanf("%d%d", &a, &b ); */
/*     printf( "gcd = %d\n", gcd( a, b ) ); */

/* } */
