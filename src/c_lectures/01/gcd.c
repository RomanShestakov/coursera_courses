#include<stdio.h>

int gcd( int a, int b) {

    printf( "a=%d b=%d\n", a, b);
    if( a == 1 || b == 1 ) return 1;
    else if( a == 0 ) return b;
    else if( b == 0 ) return a;
    else {
        if ( a > b ) {
            return gcd( a % b, b );
        }
        else {
            return gcd( a, b % a );
        }
    }
}

/* int main() { */

/*     int a, b; */
/*     printf( "Input a and b\n"); */
/*     scanf("%d%d", &a, &b ); */
/*     printf( "gcd = %d\n", gcd( a, b ) ); */

/* } */
