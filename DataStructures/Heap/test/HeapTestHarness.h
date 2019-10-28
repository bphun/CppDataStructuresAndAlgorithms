#ifndef HeapTestHarness_h
#define HeapTestHarness_h

#include "../Heap.h"
#include "../MaxHeap.h"
#include "../MinHeap.h"
#include "gtest/gtest.h"

#include <iostream>
#include <string>

using namespace std;

TEST(MinHeapTest, init)
{
    MinHeap<int> heap;
}

TEST(MinHeapTest, add)
{
    MinHeap<int> heap;

    EXPECT_TRUE(heap.isEmpty());

    heap.add(1);

    EXPECT_EQ(heap.poll(), 1);

    heap.add(3);
    heap.add(1);
    heap.add(2);
    heap.add(10);

    EXPECT_EQ(heap.peek(), 1);

    EXPECT_TRUE(heap.hasParent(0));
    EXPECT_TRUE(heap.hasLeftChild(0));
    EXPECT_TRUE(heap.hasRightChild(0));

    EXPECT_EQ(heap.parent(heap.getLeftChildIndex(0)), 1);
    EXPECT_EQ(heap.parent(heap.getRightChildIndex(0)), 1);

    EXPECT_EQ(heap.leftChild(0), 3);
    EXPECT_EQ(heap.rightChild(0), 2);

    EXPECT_TRUE(heap.hasLeftChild(heap.getLeftChildIndex(0)));

    EXPECT_EQ(heap.leftChild(heap.getLeftChildIndex(0)), 10);
}

#endif