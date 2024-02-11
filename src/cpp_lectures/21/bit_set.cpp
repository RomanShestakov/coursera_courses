#include<iostream>
#include<bitset>
//https://www.youtube.com/watch?v=zEP7KRc2t3k
// 42:59

int main() {
    std::bitset<24> s1 = 0x7ff000;
    std::bitset<24> s2 = 0xff00;

    s1[ 0 ] = 1;

    auto s3 = s1 & s2;
    std::cout << "0b" << s3 << std::endl;
    std::cout << std::hex << "0x" << s3.to_ulong() << std::endl;
    return 0;
}
