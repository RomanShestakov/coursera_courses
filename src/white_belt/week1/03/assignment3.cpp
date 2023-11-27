#include<iostream>
#include<cmath>
#include<utility>

using namespace std;

std::pair<double, double> solve_sqrt( double a, double b, double c) {
    auto d = b * b - 4 * a * c;

    if( d == 0 ){
        auto x = -b / ( 2 * a );
        return std::make_pair( x, x );
    }
    else if ( d > 0 ) {
        double x1 = ( -b + std::sqrt( d ) ) / ( 2 * a );
        double x2 = ( -b - std::sqrt( d ) ) / (2 * a );
        return( std::make_pair( x1, x2 ) );
    }

    return std::make_pair(std::nan(""), std::nan(""));
}


double solve_liner( double b, double c) {

    if( b != 0 ) {
        return -c / b;
    }
    else {
        return std::nan("");
    }
}


int main() {

    double a, b, c;
    double x1, x2;

    cin >> a >> b >> c;

    if( a != 0 ) {
        auto [x1, x2] = solve_sqrt( a, b, c );
        cout << "x1:"<< x1 << " x2:" << x2 << endl;
    }
    else {
        auto x = solve_liner(b, c);
        cout << "x:" << x << endl;
    }

    return 1;
}
