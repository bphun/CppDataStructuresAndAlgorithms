#ifndef QueueTestHarness_h
#define QueueTestHarness_h

#include "../Queue.h"

TEST(QueueTest, checkEmpty_EmptyQueue)
{
    Queue<int> queue;

    EXPECT_TRUE(queue.empty());
}

TEST(QueueTest, checkEmpty_NonEmptyQueue)
{
    Queue<int> queue;

    queue.push(1);

    EXPECT_FALSE(queue.empty());
}

TEST(QueueTest, checkSize)
{
    Queue<int> queue;

    queue.push(1);
    queue.push(2);

    EXPECT_EQ(queue.size(), 2);

    queue.pop();

    EXPECT_EQ(queue.size(), 1);
}

TEST(QueueTest, getFront)
{
    Queue<int> queue;

    queue.push(1);
    queue.push(2);

    EXPECT_EQ(queue.front(), 1);
}

TEST(QueueTest, getBack)
{
    Queue<int> queue;

    queue.push(1);
    queue.push(2);

    EXPECT_EQ(queue.back(), 2);
}

TEST(QueueTest, getBack_PopFirst)
{
    Queue<int> queue;

    queue.push(1);
    queue.push(2);

    queue.pop();

    EXPECT_EQ(queue.front(), 2);
    EXPECT_EQ(queue.back(), 2);
}

TEST(QueueTest, getBack_PopUntilEmpty)
{
    Queue<int> queue;

    queue.push(1);
    queue.push(2);

    queue.pop();

    EXPECT_EQ(queue.front(), 2);
    EXPECT_EQ(queue.back(), 2);
}

#endif