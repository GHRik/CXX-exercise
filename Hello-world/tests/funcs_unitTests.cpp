#include "../headers/funcs.hpp"
#include <gtest/gtest.h>



namespace {

    TEST(AddTest, Positive) {

        EXPECT_EQ("Hello world", hello());
    }

}
