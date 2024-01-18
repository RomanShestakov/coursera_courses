#include<iostream>


//https://www.youtube.com/watch?v=LDoCQzSd3xo
// 1:10

template<typename T>
struct Quat {
    T x, y, z, w;

    //template<typename T >
    friend std::ostream& operator<<( std::ostream&os, Quat& v ) {
        return os << '{' << v.x << ',' << v.y << ',' << v.z << ',' << v.w << '}';
    }

    // in class overload
    Quat operator-() {
        return Quat<T>{ -x, -y, -z, -w };
    }

};


// out class overload - this one wins!!!!
template<typename T> Quat< T > operator-( Quat< T > arg ) {
    return Quat<T>{ -arg.x, -arg.y, -arg.z, -arg.w };
}

int main() {

    Quat<int> q { 1,2,3,4 };

    std::cout << q << std::endl;

    Quat p = -q;

    std::cout << p << std::endl;

    return 0;
}
