#include "gtest/gtest.h"
#include "../LinkedList.h"
#include "../LinkedListNode.h"

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LinkedListTest, append)
{
    LinkedList<int> ll;

    ll.append(1);
    ll.append(2);
    ll.append(3);

    EXPECT_EQ(ll.first()->data, 1);
    EXPECT_EQ(ll.first()->next->data, 2);
    EXPECT_EQ(ll.last()->data, 3);
}

TEST(LinkedListTest, append_FollowingDeleteAll)
{
    LinkedList<int> ll;

    ll.append(1);
    ll.append(2);
    ll.append(3);

    ll.deleteAll();

    ll.append(3);
    ll.append(4);
    ll.append(5);

    EXPECT_EQ(ll.first()->data, 3);
    EXPECT_EQ(ll.first()->next->data, 4);
    EXPECT_EQ(ll.last()->data, 5);
}

TEST(LinkedListTest, append_FollowingDeleteHead)
{
    LinkedList<int> ll;

    ll.append(1);
    ll.append(2);
    ll.append(3);

    ll.deleteHead();

    ll.append(4);

    EXPECT_EQ(ll.first()->data, 2);
    EXPECT_EQ(ll.first()->next->data, 3);
    EXPECT_EQ(ll.last()->data, 4);
}

TEST(LinkedListTest, append_FollowingDeleteTail)
{
    LinkedList<int> ll;

    ll.append(1);
    ll.append(2);
    ll.append(3);

    ll.deleteTail();

    ll.append(4);

    EXPECT_EQ(ll.first()->data, 1);
    EXPECT_EQ(ll.first()->next->data, 2);
    EXPECT_EQ(ll.last()->data, 4);
}

TEST(LinkedListTest, prepend)
{
    LinkedList<int> ll;

    ll.prepend(1);
    ll.prepend(2);
    ll.prepend(3);

    EXPECT_EQ(ll.first()->data, 3);
    EXPECT_EQ(ll.first()->next->data, 2);
    EXPECT_EQ(ll.last()->data, 1);

    EXPECT_EQ(ll.count(), 3);
}

TEST(LinkedListTest, prepend_FollowingDeleteAll)
{
    LinkedList<int> ll;

    ll.prepend(1);
    ll.prepend(2);
    ll.prepend(3);

    EXPECT_EQ(ll.first()->data, 3);
    EXPECT_EQ(ll.first()->next->data, 2);
    EXPECT_EQ(ll.first()->next->next->data, 1);
    EXPECT_EQ(ll.last()->data, 1);

    EXPECT_EQ(ll.count(), 3);

    ll.deleteAll();

    ll.prepend(3);
    ll.prepend(4);
    ll.prepend(5);

    EXPECT_EQ(ll.first()->data, 5);
    EXPECT_EQ(ll.first()->next->data, 4);
    EXPECT_EQ(ll.first()->next->next->data, 3);
    EXPECT_EQ(ll.last()->data, 3);

    EXPECT_EQ(ll.count(), 3);
}

TEST(LinkedListTest, prepend_FollowingDeleteHead)
{
    LinkedList<int> ll;

    ll.prepend(1);
    ll.prepend(2);
    ll.prepend(3);

    EXPECT_EQ(ll.first()->data, 3);
    EXPECT_EQ(ll.first()->next->data, 2);
    EXPECT_EQ(ll.last()->data, 1);

EXPECT_EQ(ll.count(), 3);

    ll.deleteHead();

    ll.prepend(4);

    EXPECT_EQ(ll.first()->data, 4);
    EXPECT_EQ(ll.first()->next->data, 2);
    EXPECT_EQ(ll.last()->data, 1);

    EXPECT_EQ(ll.count(), 3);
}

TEST(LinkedListTest, addValueToSortedList)
{
    LinkedList<int> ll;

    ll.addValueToSortedList(20);
    ll.addValueToSortedList(1);
    ll.addValueToSortedList(5);

    Node<int> *currNode = ll.first();

    while (currNode->next != nullptr)
    {
        ASSERT_TRUE(currNode->data < currNode->next->data);

        currNode = currNode->next;
    }
}

TEST(LinkedListTest, deleteNodewithValue)
{
    LinkedList<int> ll;

    ll.append(1);
    ll.append(2);
    ll.append(3);

    ll.deleteNodeWithValue(2);

    EXPECT_EQ(ll.first()->data, 1);
    EXPECT_EQ(ll.first()->next->data, 3);
    EXPECT_EQ(ll.last()->data, 3);
}

TEST(LinkedListTest, deleteNodewithValue_EmptyList)
{
    LinkedList<int> ll;

    ll.deleteNodeWithValue(2);

    EXPECT_EQ(ll.first(), nullptr);
    EXPECT_EQ(ll.last(), nullptr);
}

TEST(LinkedListTest, deleteHead)
{
    LinkedList<int> ll;

    ll.append(1);
    ll.append(2);
    ll.append(3);
    ll.append(4);

    ll.deleteHead();

    EXPECT_EQ(ll.first()->data, 2);
    EXPECT_EQ(ll.first()->next->data, 3);
    EXPECT_EQ(ll.last()->data, 4);
}

TEST(LinkedListTest, deleteHead_EmptyList)
{
    LinkedList<int> ll;

    ll.deleteHead();

    EXPECT_EQ(ll.first(), nullptr);
    EXPECT_EQ(ll.last(), nullptr);
}

TEST(LinkedListTest, deleteTail)
{
    LinkedList<int> ll;

    ll.append(1);
    ll.append(2);
    ll.append(3);

    ll.deleteTail();

    EXPECT_EQ(ll.first()->data, 1);
    EXPECT_EQ(ll.first()->next->data, 2);
    EXPECT_FALSE(ll.first()->next->next->data == 3);
    EXPECT_EQ(ll.last()->data, 2);
}

TEST(LinkedListTest, deleteTail_EmptyList)
{
    LinkedList<int> ll;

    ll.deleteTail();

    EXPECT_EQ(ll.first(), nullptr);
    EXPECT_EQ(ll.last(), nullptr);
}

TEST(LinkedListTest, deleteAll)
{
    LinkedList<int> ll;

    ll.append(1);
    ll.append(2);
    ll.append(3);

    ll.deleteAll();

    EXPECT_EQ(ll.first(), nullptr);
    EXPECT_EQ(ll.last(), nullptr);
}

TEST(LinkedListTest, deleteAll_EmptyList)
{
    LinkedList<int> ll;

    ll.deleteAll();

    EXPECT_EQ(ll.first(), nullptr);
    EXPECT_EQ(ll.last(), nullptr);
}

TEST(LinkedListTest, sort)
{
    LinkedList<int> ll;

    ll.append(10);
    ll.append(1);
    ll.append(20);
    ll.append(12);

    ll.sort();

    Node<int> *currNode = ll.first();

    while (currNode->next != nullptr)
    {
        ASSERT_TRUE(currNode->data < currNode->next->data);

        currNode = currNode->next;
    }
}

TEST(LinkedListTest, sort_EmptyList)
{
    LinkedList<int> ll;

    ll.sort();

    EXPECT_EQ(ll.first(), nullptr);
    EXPECT_EQ(ll.last(), nullptr);
}

TEST(LinkedListTest, getFirstElement)
{
    LinkedList<int> ll;

    ll.append(1);
    ll.append(2);
    ll.append(3);

    EXPECT_EQ(ll.first()->data, 1);
    EXPECT_EQ(ll.first()->next->data, 2);
    EXPECT_EQ(ll.last()->data, 3);
}

TEST(LinkedListTest, getSize)
{
    LinkedList<int> ll;

    ll.append(1);
    ll.append(2);
    ll.append(3);

    EXPECT_EQ(ll.count(), 3);

    ll.deleteNodeWithValue(2);

    EXPECT_EQ(ll.count(), 2);
}