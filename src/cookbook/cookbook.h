#pragma once

#include<iostream>

namespace cookbook {

    // how to use decltype( auto ) to deduce int& from get()
    struct foo {
        int x_;
        foo( const int x = 0 ) : x_{ x } {};
        int& get() { return x_; }
    };

    // this needs to return auto&
    decltype( auto ) proxy_get( foo& f ) { return f.get(); }

}
