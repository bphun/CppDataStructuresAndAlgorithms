#include "gtest/gtest.h"
#include "../DoublyLinkedList.h"

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(DoublyLinkedListTest, prepend)
{
    DoublyLinkedList<int> dll;

    dll.prepend(1);
    dll.prepend(2);
    dll.prepend(3);

    EXPECT_EQ(dll.first()->data, 3);
    EXPECT_EQ(dll.first()->next->data, 2);
    EXPECT_EQ(dll.first()->next->next->data, 1);

    EXPECT_EQ(dll.last()->data, 1);
    EXPECT_EQ(dll.last()->prev->data, 2);
    EXPECT_EQ(dll.last()->prev->prev->data, 3);

    EXPECT_EQ(dll.count(), 3);
}


TEST(DoublyLinkedListTest, append)
{
    DoublyLinkedList<int> dll;

    dll.append(1);
    dll.append(2);
    dll.append(3);

    EXPECT_EQ(dll.first()->data, 1);
    EXPECT_EQ(dll.first()->next->data, 2);
    EXPECT_EQ(dll.first()->next->next->data, 3);

    EXPECT_EQ(dll.last()->data, 3);
    EXPECT_EQ(dll.last()->prev->data, 2);
    EXPECT_EQ(dll.last()->prev->prev->data, 1);

    EXPECT_EQ(dll.count(), 3);
}

TEST(DoublyLinkedListTest, removeNodeWithValue_RemoveHead)
{
    DoublyLinkedList<int> dll;

    dll.append(1);
    dll.append(2);
    dll.append(3);

    dll.removeNodeWithValue(1);

    EXPECT_EQ(dll.first()->data, 2);
    EXPECT_EQ(dll.first()->next->data, 3);

    EXPECT_EQ(dll.last()->data, 3);
    EXPECT_EQ(dll.last()->prev->data, 2);
    
    EXPECT_EQ(dll.count(), 2);
}

TEST(DoublyLinkedListTest, removeNodeWithValue_RemoveFromMiddleOfList)
{
    DoublyLinkedList<int> dll;

    dll.append(1);
    dll.append(2);
    dll.append(3);

    dll.removeNodeWithValue(2);

    EXPECT_EQ(dll.first()->data, 1);
    EXPECT_EQ(dll.first()->next->data, 3);

    EXPECT_EQ(dll.last()->data, 3);
    EXPECT_EQ(dll.last()->prev->data, 1);

    EXPECT_EQ(dll.count(), 2);
}

TEST(DoublyLinkedListTest, removeNodeWithValue_RemoveTail)
{
    DoublyLinkedList<int> dll;

    dll.append(1);
    dll.append(2);
    dll.append(3);

    dll.removeNodeWithValue(3);

    EXPECT_EQ(dll.first()->data, 1);
    EXPECT_EQ(dll.first()->next->data, 2);

    EXPECT_EQ(dll.last()->data, 2);
    EXPECT_EQ(dll.last()->prev->data, 1);

    EXPECT_EQ(dll.count(), 2);
}

TEST(DoublyLinkedListTest, removeNodeWithValue_SingleNodeList)
{
    DoublyLinkedList<int> dll;

    dll.append(1);

    dll.removeNodeWithValue(1);

    EXPECT_EQ(dll.first(), nullptr);
    EXPECT_EQ(dll.last(), nullptr);
}

TEST(DoublyLinkedListTest, removeHead)
{
    DoublyLinkedList<int> dll;

    dll.append(1);
    dll.append(2);
    dll.append(3);

    dll.removeHead();

    EXPECT_EQ(dll.first()->data, 2);
    EXPECT_EQ(dll.first()->next->data, 3);

    EXPECT_EQ(dll.first()->prev, nullptr);

    EXPECT_EQ(dll.count(), 2);
}

TEST(DoublyLinkedListTest, removeHead_EmptyList)
{
    DoublyLinkedList<int> dll;

    dll.removeHead();

    EXPECT_EQ(dll.first(), nullptr);
    EXPECT_EQ(dll.last(), nullptr);
    EXPECT_EQ(dll.count(), 0);
}

TEST(DoublyLinkedListTest, removeTail)
{
    DoublyLinkedList<int> dll;

    dll.append(1);
    dll.append(2);
    dll.append(3);

    dll.removeTail();

    EXPECT_EQ(dll.first()->data, 1);
    EXPECT_EQ(dll.first()->next->data, 2);

    EXPECT_EQ(dll.last()->data, 2);
    EXPECT_EQ(dll.last()->prev->data, 1);
    
    EXPECT_EQ(dll.count(), 2);
}

TEST(DoublyLinkedListTest, removeTail_EmptyList)
{
    DoublyLinkedList<int> dll;

    dll.removeTail();

    EXPECT_EQ(dll.first(), nullptr);
    EXPECT_EQ(dll.last(), nullptr);
    EXPECT_EQ(dll.count(), 0);
}