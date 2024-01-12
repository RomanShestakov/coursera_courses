#pragma once

#include <string_view>
#include <vector>
#include <string>
#include <stack>

namespace red_belt {

    std::vector<std::string_view> split( std::string_view s );
    std::vector<std::string_view> split( std::string_view s, char delim );
}
