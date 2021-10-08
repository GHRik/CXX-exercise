#include "../headers/Interfaces/Animal.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>


namespace{

class MockCat : public Animal{
public:
    MOCK_METHOD0(sleeping,std::string());
};



TEST(MockCatTest,SleepingFunction) {
  MockCat mock_cat;
  EXPECT_CALL(mock_cat, sleeping());
  mock_cat.sleeping();

}


}
