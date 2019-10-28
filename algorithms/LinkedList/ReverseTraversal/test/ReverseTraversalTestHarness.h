#ifndef ReverseTraversalTestHarness_h
#define ReverseTraversalTestHarness_h

#include "../../../../dataStructures/LinkedList/LinkedList.h"
#include "../ReverseLinkedListTraversal.h"

int maxVal = 50;

void reverseTraversalTestCallback(int inputVal)
{
    EXPECT_EQ(inputVal, maxVal--);
}

TEST(ReverseLinkedListTraversal, traversal)
{
    LinkedList<int> ll;

    for (int i = 1; i <= maxVal; i++)
        ll.append(i);

    reverseTraversal(ll, reverseTraversalTestCallback);
}

#endif