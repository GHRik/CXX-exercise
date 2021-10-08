#include "../headers/Interfaces/Animal.hpp"
#include "../headers/Cat.hpp"
#include "../headers/Dog.hpp"
#include "../headers/Monkey.hpp"
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
TEST( CatTest, CrashTest ) {
    Cat cat;
    EXPECT_THROW(cat.crash(), int);
}

TEST( DogTest, CrashTest ) {
    Dog dog;
    EXPECT_THROW(dog.crash(), int);
}

TEST( MonkeyTest, CrashTest ) {
    Monkey monkey;
    EXPECT_THROW(monkey.crash(), int);
}


