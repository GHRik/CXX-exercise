#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../headers/MyList_template.hpp"
#include <string>

TEST(myListTestSize,after_back_add)
{
    MyList<int> myList;
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(5));
    EXPECT_EQ(1,myList.getSize());
}

TEST(myListTestSize,after_front_add)
{
    MyList<int> myList;
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.front_push(5));
    EXPECT_EQ(1,myList.getSize());
}

TEST(myListTestSize,after_back_pop)
{
    MyList<int> myList;
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(5));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(6));
    EXPECT_EQ(2,myList.getSize());
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_pop());
    EXPECT_EQ(1,myList.getSize());
}

TEST(myListTestSize,after_front_pop)
{
    MyList<int> myList;
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(5));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(6));
    EXPECT_EQ(2,myList.getSize());
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.front_pop());
    EXPECT_EQ(1,myList.getSize());
}

TEST(myListTest, front_pop_empty_list)
{
    MyList<int> myList;
    EXPECT_EQ(0,myList.getSize());
    EXPECT_EQ(utils::OUT_OF_BOUND,myList.front_pop());
}

TEST(myListTest, back_pop_empty_list)
{
    MyList<int> myList;
    EXPECT_EQ(0,myList.getSize());
    EXPECT_EQ(utils::OUT_OF_BOUND,myList.back_pop());
}

TEST(myListTest, back_push_properly_pushing)
{
        MyList<int> myList;
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(1));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(2));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(3));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(4));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(5));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(6));
    EXPECT_EQ(6,myList.getSize());
    EXPECT_EQ(1,myList.getElement(0)->value);
    EXPECT_EQ(2,myList.getElement(1)->value);
    EXPECT_EQ(3,myList.getElement(2)->value);
    EXPECT_EQ(4,myList.getElement(3)->value);
    EXPECT_EQ(5,myList.getElement(4)->value);
    EXPECT_EQ(6,myList.getElement(5)->value);
}

TEST(myListTest, front_push_properly_pushing)
{
    MyList<int> myList;
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.front_push(1));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.front_push(2));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.front_push(3));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.front_push(4));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.front_push(5));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.front_push(6));
    EXPECT_EQ(6,myList.getSize());
    EXPECT_EQ(1,myList.getElement(5)->value);
    EXPECT_EQ(2,myList.getElement(4)->value);
    EXPECT_EQ(3,myList.getElement(3)->value);
    EXPECT_EQ(4,myList.getElement(2)->value);
    EXPECT_EQ(5,myList.getElement(1)->value);
    EXPECT_EQ(6,myList.getElement(0)->value);
}

TEST(myListTest, clearList)
{
    MyList<int> myList;
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(1));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(2));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(3));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(4));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(5));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(6));
    EXPECT_EQ(6,myList.getSize());
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.clear_list());
    EXPECT_EQ(0,myList.getSize());
}

TEST(myListTest, getElement_OutOfBound_empty_list)
{
    MyList<int> myList;
    EXPECT_TRUE(myList.isEmpty());
    EXPECT_THROW(myList.getElement(0),utils::RESULT_CODE);
    EXPECT_THROW(myList.getElement(-1),utils::RESULT_CODE);
    EXPECT_THROW(myList.getElement(1),utils::RESULT_CODE);
}

TEST(myListTest, getElement_OutOfBound)
{
    MyList<int> myList;
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(1));
    EXPECT_EQ(1,myList.getElement(0)->value);
    EXPECT_THROW(myList.getElement(-1),utils::RESULT_CODE);
    EXPECT_THROW(myList.getElement(1),utils::RESULT_CODE);
}

TEST(myListTest, insert_to_list)
{
    MyList<int> myList;
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(1));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(3));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(4));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.insert_to_list(1,2));
    EXPECT_EQ(2,myList.getElement(1)->value);
}

TEST(myListTest, insert_to_front)
{
    MyList<int> myList;
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(1));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(2));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(3));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.insert_to_list(0,0));
    EXPECT_EQ(0,myList.getElement(0)->value);
}

TEST(myListTest, insert_to_back)
{
    MyList<int> myList;
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(1));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(2));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(3));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.insert_to_list(3,4));
    EXPECT_EQ(4,myList.getElement(3)->value);
}

TEST(myListTest, insert_to_negative)
{
    MyList<int> myList;
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(1));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(2));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(3));
    EXPECT_THROW(myList.insert_to_list(-1,4),utils::RESULT_CODE);
}

TEST(myListTest, insert_too_far)
{
    MyList<int> myList;
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(1));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(2));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(3));
    EXPECT_THROW(myList.insert_to_list(5,4),utils::RESULT_CODE);
}

TEST(myListTest, stringList)
{
    MyList<std::string> myList;

    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push("1"));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push("2"));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push("3"));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.insert_to_list(3,"4"));
    EXPECT_EQ("4",myList.getElement(3)->value);

}

class MockClass
{
    public:
        MockClass( int value ): m_value(value){}
        MockClass(){}
        int m_value;

};

TEST(myListTest, withMyOwnObject)
{
    MockClass mock1(1);
    MockClass mock2(2);
    MockClass mock3(3);
    MockClass mock4(4);
    MyList<MockClass> myList;

    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(mock1));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(mock2));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.back_push(mock3));
    EXPECT_EQ(utils::RESULT_CODE::OK,myList.insert_to_list(3,mock4));
    EXPECT_EQ(4,myList.getElement(3)->value.m_value);

}
