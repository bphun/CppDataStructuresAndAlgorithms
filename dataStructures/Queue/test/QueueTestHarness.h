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

TEST(QueueTest, getFirst)
{
    Queue<int> queue;

    queue.push(1);
    queue.push(2);

    EXPECT_EQ(queue.first(), 1);
}

TEST(QueueTest, getLast)
{
    Queue<int> queue;

    queue.push(1);
    queue.push(2);

    EXPECT_EQ(queue.last(), 2);
}

TEST(QueueTest, getLast_PopFirst)
{
    Queue<int> queue;

    queue.push(1);
    queue.push(2);

    queue.pop();

    EXPECT_EQ(queue.first(), 2);
    EXPECT_EQ(queue.last(), 2);
}

TEST(QueueTest, getLast_PopUntilEmpty)
{
    Queue<int> queue;

    queue.push(1);
    queue.push(2);

    queue.pop();

    EXPECT_EQ(queue.first(), 2);
    EXPECT_EQ(queue.last(), 2);
}

#endif