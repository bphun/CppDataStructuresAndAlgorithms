#include "gtest/gtest.h"
#include "../Heap.h"
#include "../MinHeap.h"
#include "../MaxHeap.h"

#include <string>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

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