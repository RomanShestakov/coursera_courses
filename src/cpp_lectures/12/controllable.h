#pragma once
#include<iostream>
#include <new>
#include<stdexcept>
#include<utility>

struct Controllable {
    static int control;
    int *resource_;
    Controllable() : resource_( new int(42)) {}

    Controllable( Controllable && rhs ) noexcept : resource_( rhs.resource_) {
        rhs.resource_ = nullptr;
    }

    Controllable &operator = ( Controllable && rhs) noexcept {
        std::swap(resource_, rhs.resource_);
        return *this;
    }

    Controllable( const Controllable &rhs ) : resource_(new int(*rhs.resource_)) {
        if(control == 0 ) {
            control = 5;
            std::cout << "control reached \n";
            throw std::bad_alloc{};
        }
        control -= 1;
    }

    Controllable &operator=(const Controllable &rhs) {
        Controllable tmp(rhs);
        std::swap( *this, tmp);
        return *this;
    }

    ~Controllable(){ delete resource_; }
};
