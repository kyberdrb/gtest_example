#include <Example.h>
#include "gtest/gtest.h"

class ExampleTestSuite : public ::testing::Test {};

TEST_F(ExampleTestSuite, test_foo_returns_bar) {
    EXPECT_EQ("bar", Example().foo());
}
