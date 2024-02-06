#include<deque>
#include<forward_list>
#include<iostream>
#include<iterator>
#include<list>
#include<vector>


std::ostream& operator<<(std::ostream& out, std::random_access_iterator_tag) {
    std::cout << "random access";
    return out;
}

std::ostream& operator<<(std::ostream& out, std::bidirectional_iterator_tag) {
    std::cout << "bidirectional";
    return out;
}

std::ostream& operator<<(std::ostream& out, std::forward_iterator_tag) {
    std::cout << "forward";
    return out;
}

std::ostream& operator<<(std::ostream& out, std::input_iterator_tag) {
    std::cout << "input";
    return out;
}

std::ostream& operator<<(std::ostream& out, std::output_iterator_tag) {
    std::cout << "output";
    return out;
}

template<typename Iter>
void print_iterator_type() {
    std::cout << typename std::iterator_traits<Iter>::iterator_category() << std::endl;
}

int main() {
    print_iterator_type<typename std::deque<int>::iterator>();
    print_iterator_type<typename std::forward_list<int>::iterator>();
    print_iterator_type<typename std::list<int>::iterator>();
    print_iterator_type<typename std::vector<int>::iterator>();
    print_iterator_type<std::istream_iterator<int>>();
    print_iterator_type<std::ostream_iterator<int>>();

    return 0;
}
