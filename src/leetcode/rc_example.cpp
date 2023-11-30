#include <rapidcheck.h>
#include <gtest/gtest.h>
#include <rapidcheck/gtest.h>

int add(int x, int y) {
    return x + y;
}

RC_GTEST_PROP(TestCase, inRange, (int first, int second)) {
    int x = *rc::gen::inRange(first, second);
    RC_ASSERT(x >= first);
    RC_ASSERT(x < second);
}

RC_GTEST_PROP(AdditionTest, IsCommutative, (int x, int y)) {
    int res1 = add(x, y);
    int res2 = add(y, x);
    RC_ASSERT(res1 == res2);
}

RC_GTEST_PROP(AdditionTest, IsAssociative, (int x, int y, int z)) {
    int res1 = add(add(x, y), z);
    int res2 = add(z, add(y, x));
    RC_ASSERT(res1 == res2);
}

RC_GTEST_PROP(AdditionTest, AddingZeroDoesntChangeTheValue, (int x)) {
    int res1 = add(x, 0);
    RC_ASSERT(x == res1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
