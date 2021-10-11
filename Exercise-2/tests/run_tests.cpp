#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;

int main()
{
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}
