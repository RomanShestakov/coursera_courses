#include<iostream>


//https://www.youtube.com/watch?v=LDoCQzSd3xo
// 1:10

template<typename T>
struct Quat {
    T x, y, z, w;

    friend std::ostream& operator<<( std::ostream&os, Quat& v ) {
        return os << '{' << v.x << ',' << v.y << ',' << v.z << ',' << v.w << '}';
    }

    // in class overload
    // this one wins in overload set
    Quat operator-() {
        std::cout << "in class" << std::endl;
        return Quat<T>{ -x, -y, -z, -w };
    }

    // cant overload using return param

    // pre-increment
    Quat& operator++() {
        x++; y++; z++; w++;
        return *this;
    }

    // post increment
    Quat operator++( int ) {
        auto q = Quat<T>{ x, y, z, w };
        x++; y++; z++; w++;
        return q;
    }


};

template<typename T> Quat< T > operator-( Quat< T > arg ) {
    std::cout << "out class" << std::endl;
    return Quat<T>{ -arg.x, -arg.y, -arg.z, -arg.w };
}

int main() {

    Quat<int> q { 1,2,3,4 };
    std::cout << q << std::endl;

    Quat p = -q;
    std::cout << p << std::endl;

    // can call operators directly
    q.operator-();
    operator-( q);


    // pre-increment
    std::cout << "pre-increment:" << ++q << std::endl;

    auto qq = q++;
    std::cout << "post_increment:" << qq << " q" << q << std::endl;
    return 0;
}
