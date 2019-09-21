#include "gtest/gtest.h"
#include "../Stack.h"

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(StackTest, top)
{
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    EXPECT_EQ(stack.top(), 3);
    EXPECT_EQ(stack.size(), 3);

    stack.pop();
    EXPECT_EQ(stack.top(), 2);
    EXPECT_EQ(stack.size(), 2);

    stack.pop();
    EXPECT_EQ(stack.top(), 1);
    EXPECT_EQ(stack.size(), 1);
}

TEST(StackTest, size)
{
    Stack<int> stack;

    EXPECT_EQ(stack.size(), 0);

    stack.push(1);
    EXPECT_EQ(stack.size(), 1);

    stack.push(1);
    EXPECT_EQ(stack.size(), 2);
}

TEST(StackTest, empty)
{
    Stack<int> stack;

    EXPECT_TRUE(stack.empty());
}