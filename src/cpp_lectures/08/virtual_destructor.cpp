#include<iostream>

// https://www.youtube.com/watch?v=Qr6UIGF0DKg
// 1:00

struct ISquare {
    virtual int square() const = 0;
    virtual ~ISquare() {}
};

struct Triangle : public ISquare {
    int x_ {};
    int y_ {};
    int square () const override { return x_; }
};

int main() {

    ISquare* s = new Triangle();

    delete s;

    return 0;
}
