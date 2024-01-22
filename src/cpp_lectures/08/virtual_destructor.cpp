#include<iostream>

// https://www.youtube.com/watch?v=Qr6UIGF0DKg
// 1:00

struct ISquare {
    virtual int square() const = 0;
    virtual ISquare* clone() const = 0;
    virtual ~ISquare() {}
};

// can not inherit from Triangle
struct Triangle final : public ISquare {
    int x_ {};
    int y_ {};
    Triangle() = default;
    Triangle( int x, int y ) : x_( x ), y_( y ) {}
    int square () const override { return x_; }
    Triangle* clone() const override {
        return new Triangle{ x_, y_ };
    }
};

int main() {

    ISquare* s = new Triangle();

    delete s;

    return 0;
}
