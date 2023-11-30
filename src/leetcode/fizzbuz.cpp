#include<iostream>
#include <string>

// Fizz Buzz − it is a simple programming problem in which the programmer changes the occurrence o all multiples of 3 by ‘Fizz’ and all multiples of 5 by ‘Buzz’ in the numbers from 1 to 100.

// Let’s take an example to understand the problem

// 1, 2, 'Fizz', 4, 'Buzz', 'Fizz' , 7, 8, 'Fizz' , 'Buzz', 11, 'Fizz' , 13, 14, 'Fizz Buzz' , 16, 17, 'Fizz' , 19, 'Buzz',....

int main() {

    for(int i = 0; i < 100; ++i) {

        if( i % 3 && i % 5 ) {
            std::cout << "fizzbuz,";
        }
        else if( i % 3 ) {
            std::cout << "fizz,";
        }
        else if( i % 5 ) {
            std::cout << "buzz,";
        }
        else {
            std::cout << i << ",";
        }
    }

    return 0;
}
