#include "gtest/gtest.h"
#include "../../../../dataStructures/LinkedList/LinkedList.h"
#include "../ReverseLinkedListTraversal.h"

int maxVal = 50;

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

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