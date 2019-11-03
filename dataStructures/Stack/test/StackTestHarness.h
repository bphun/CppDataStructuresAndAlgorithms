#ifndef StackTestHarness_h
#define StackTestHarness_h

#include "../Stack.h"

TEST(StackTest, first)
{
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    EXPECT_EQ(stack.first(), 3);
    EXPECT_EQ(stack.size(), 3);

    stack.pop();
    EXPECT_EQ(stack.first(), 2);
    EXPECT_EQ(stack.size(), 2);

    stack.pop();
    EXPECT_EQ(stack.first(), 1);
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

#endif