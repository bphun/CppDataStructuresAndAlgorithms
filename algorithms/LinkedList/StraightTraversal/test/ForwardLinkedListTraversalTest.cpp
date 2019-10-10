#include "gtest/gtest.h"
#include "../../../../dataStructures/LinkedList/LinkedList.h"
#include "../ForwardLinkedListTraversal.h"

int counter = 1;

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

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