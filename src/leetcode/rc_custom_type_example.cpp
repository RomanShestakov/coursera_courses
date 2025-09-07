#include <gtest/gtest.h>
#include <rapidcheck.h>
#include <rapidcheck/gen/Arbitrary.h>
#include <rapidcheck/gtest.h>
#include <vector>

struct Person {
  std::string firstName;
  std::string lastName;
  int age;
};

namespace rc {

template <> struct Arbitrary<Person> {
  static Gen<Person> arbitrary() {
    return gen::build<Person>(gen::set(&Person::firstName),
                              gen::set(&Person::lastName),
                              gen::set(&Person::age, gen::inRange(0, 100)));
  }
};

} // namespace rc

template <typename T> struct MyType {
  size_t size_ = 0;
  std::vector<T> data_;
  // T val_;
  MyType() = default;
  // MyType(int val) : val_{val} {}
};

namespace rc {

// template <>
template <typename T> struct Arbitrary<MyType<T>> {
  static Gen<MyType<T>> arbitrary() {
    // FIXME - why the line below doesn't work?
    //  return *rc::gen::arbitrary<MyType<T>>();
    return gen::build<MyType<T>>(gen::set(&MyType<T>::size_));
  }
};
} // namespace rc

RC_GTEST_PROP(TestCase, custon_type, (const MyType<int> &t)) {
  RC_ASSERT(t.data_.size() == 0);
}

RC_GTEST_PROP(TestCase, custon_type_person, (const Person &p)) {
  RC_ASSERT(p.age < 200);
}
