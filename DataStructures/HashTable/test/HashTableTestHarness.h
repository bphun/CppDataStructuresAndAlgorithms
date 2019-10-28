#ifndef HashTableTestHarness_h
#define HashTableTestHarness_h

#include "../HashTable.h"
#include "gtest/gtest.h"

#include <iostream>
#include <string>

using namespace std;

TEST(HashTableTest, init)
{
    HashTable<string, string> hashTable;

    EXPECT_TRUE(hashTable.empty());
    EXPECT_EQ(hashTable.size(), 0);
}

TEST(HashTableTest, put)
{
    HashTable<string, string> hashTable;

    hashTable.put("key1", "value1");

    EXPECT_FALSE(hashTable.empty());
    EXPECT_EQ(hashTable.size(), 1);
    EXPECT_EQ(hashTable.get("key1"), "value1");

    hashTable.put("key2", "value2");

    EXPECT_FALSE(hashTable.empty());
    EXPECT_EQ(hashTable.size(), 2);
    EXPECT_EQ(hashTable.get("key2"), "value2");

    hashTable.put("key3", "value3");

    EXPECT_FALSE(hashTable.empty());
    EXPECT_EQ(hashTable.size(), 3);
    EXPECT_EQ(hashTable.get("key3"), "value3");
}

TEST(HashTableTest, put_DuplicateKeys)
{
    HashTable<string, string> hashTable;

    hashTable.put("key1", "value1");

    EXPECT_FALSE(hashTable.empty());
    EXPECT_EQ(hashTable.size(), 1);
    EXPECT_EQ(hashTable.get("key1"), "value1");

    hashTable.put("key1", "value2");

    EXPECT_FALSE(hashTable.empty());
    EXPECT_EQ(hashTable.size(), 1);
    EXPECT_EQ(hashTable.get("key1"), "value2");

    hashTable.put("key1", "value3");

    EXPECT_FALSE(hashTable.empty());
    EXPECT_EQ(hashTable.size(), 1);
    EXPECT_EQ(hashTable.get("key1"), "value3");
}

TEST(HashTableTest, put_LargeList)
{
    HashTable<string, string> hashTable;

    const size_t maxElements = 900000;

    for (int i = 0; i < maxElements; i++) {
        hashTable.put("key", "value");

        EXPECT_EQ(hashTable.bucketCount(), 1);
        EXPECT_EQ(hashTable.size(), 1);
        EXPECT_EQ(hashTable.count("key"), 1);
    }
}

TEST(HashTableTest, get)
{
    HashTable<string, string> hashTable;

    hashTable.put("key", "value");

    EXPECT_EQ(hashTable.size(), 1);
    EXPECT_EQ(hashTable.bucketCount(), 1);
    EXPECT_EQ(hashTable.get("key"), "value");
}

TEST(HashTableTest, get_EmptyTable)
{
    HashTable<string, string> hashTable;

    EXPECT_EQ(hashTable.size(), 0);
    EXPECT_EQ(hashTable.bucketCount(), 0);
    EXPECT_THROW(hashTable.get("key"), std::out_of_range);
}

TEST(HashTableTest, count)
{
    HashTable<string, string> hashTable;

    hashTable.put("key", "value");

    EXPECT_EQ(hashTable.count("key"), 1);
}

TEST(HashTableTest, count_EmptyTable)
{
    HashTable<string, string> hashTable;

    EXPECT_EQ(hashTable.count("key"), 0);
}

TEST(HashTableTest, erase)
{
    HashTable<string, string> hashTable;

    hashTable.put("key", "value");

    EXPECT_FALSE(hashTable.empty());
    EXPECT_EQ(hashTable.size(), 1);
    EXPECT_EQ(hashTable.get("key"), "value");

    hashTable.erase("key");

    EXPECT_EQ(hashTable.size(), 0);
    EXPECT_EQ(hashTable.bucketCount(), 0);
    EXPECT_THROW(hashTable.get("key"), std::out_of_range);
}

TEST(HashTableTest, erase_EmptTable)
{
    HashTable<string, string> hashTable;

    EXPECT_TRUE(hashTable.empty());
    EXPECT_EQ(hashTable.size(), 0);
    EXPECT_THROW(hashTable.erase("key"), std::out_of_range);
}

TEST(HashTableTest, clear)
{
    HashTable<string, string> hashTable;

    hashTable.put("key1", "value1");

    EXPECT_FALSE(hashTable.empty());
    EXPECT_EQ(hashTable.size(), 1);
    EXPECT_EQ(hashTable.get("key1"), "value1");

    hashTable.put("key2", "value2");

    EXPECT_FALSE(hashTable.empty());
    EXPECT_EQ(hashTable.size(), 2);
    EXPECT_EQ(hashTable.get("key2"), "value2");

    hashTable.put("key3", "value3");

    EXPECT_FALSE(hashTable.empty());
    EXPECT_EQ(hashTable.size(), 3);
    EXPECT_EQ(hashTable.get("key3"), "value3");

    hashTable.clear();

    EXPECT_EQ(hashTable.bucketCount(), 0);
    EXPECT_EQ(hashTable.size(), 0);
}

#endif