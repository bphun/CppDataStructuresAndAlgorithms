#ifndef ForwardLinkedListTraversalTestHarness_h
#define ForwardLinkedListTraversalTestHarness_h

#include "../../../../dataStructures/LinkedList/LinkedList.h"
#include "../ForwardLinkedListTraversal.h"
#include "gtest/gtest.h"

int counter = 1;

void forwardTraversalTestCallback(int inputVal)
{
    EXPECT_EQ(inputVal, ++counter);
}

TEST(ForwardLinkedListTraversal, traversal)
{
    LinkedList<int> ll;

    for (int i = 1; i < 50; i++)
        ll.append(i);

    forwardTraversal(ll, forwardTraversalTestCallback);
}

#endif