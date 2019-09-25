#ifndef HashTable_h
#define HashTable_h

#include "../LinkedList/LinkedList.h"
#include "../LinkedList/LinkedListNode.h"
#include "HashTableNode.h"

#include <tuple>
using namespace std;

#define TABLE_SIZE 32

template <typename KeyType, typename ValueType>
class HashTable
{
    LinkedList<tuple<KeyType, ValueType>> *table[TABLE_SIZE] = {nullptr};

    size_t numBuckets = 0;
    size_t numValues = 0;

    size_t generateHashForKey(const KeyType &) const;
    size_t getIndexForKey(const KeyType &) const;

public:
    ~HashTable();

    HashTable<KeyType, ValueType> &operator=(const HashTable<KeyType, ValueType> &);

    bool empty() const;
    size_t size() const;

    // ValueType &operator[](const KeyType &);
    // ValueType &at(const KeyType &);
    ValueType &get(const KeyType &);
    void put(const KeyType &, const ValueType &);

    size_t count(const KeyType &) const;

    void erase(const KeyType &);
    void clear();

    size_t bucketCount() const;
    size_t maxBucketCount() const;
    size_t bucketSize(const size_t &) const;
};

template <typename KeyType, typename ValueType>
HashTable<KeyType, ValueType>::~HashTable()
{
    this->clear();
}

template <typename KeyType, typename ValueType>
size_t HashTable<KeyType, ValueType>::generateHashForKey(const KeyType &key) const
{
    hash<KeyType> hashValue;

    return hashValue(key);
}

template <typename KeyType, typename ValueType>
size_t HashTable<KeyType, ValueType>::getIndexForKey(const KeyType &key) const
{
    return this->generateHashForKey(key) % TABLE_SIZE;
}

template <typename KeyType, typename ValueType>
HashTable<KeyType, ValueType> &HashTable<KeyType, ValueType>::operator=(const HashTable<KeyType, ValueType> &lhs)
{
    HashTable<KeyType, ValueType> newHashTable;

    newHashTable.table = lhs.table;
    newHashTable.numBuckets = lhs.numBuckets;
    newHashTable.numValues = lhs.numValues;

    return newHashTable;
}

template <typename KeyType, typename ValueType>
bool HashTable<KeyType, ValueType>::empty() const
{
    return numValues == 0;
}

template <typename KeyType, typename ValueType>
size_t HashTable<KeyType, ValueType>::size() const
{
    return numValues;
}

// template <typename KeyType, typename ValueType>
// ValueType &HashTable<KeyType, ValueType>::operator[](const KeyType &key)
// {
//     return this->get(key);
// }

// template <typename KeyType, typename ValueType>
// ValueType &HashTable<KeyType, ValueType>::at(const KeyType &key)
// {
//     return this->get(key);
// }

template <typename KeyType, typename ValueType>
ValueType &HashTable<KeyType, ValueType>::get(const KeyType &key)
{
    if (numBuckets == 0 || numValues == 0)
        throw std::out_of_range("No values in table to get");

    size_t index = this->getIndexForKey(key);
    LinkedListNode<tuple<KeyType, ValueType>> *currNode = table[index]->first();

    while (currNode != nullptr && std::get<0>(currNode->data) != key)
        currNode = currNode->next;

    return std::get<1>(currNode->data);
}

template <typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::put(const KeyType &key, const ValueType &value)
{
    size_t index = this->getIndexForKey(key);

    if (table[index] == nullptr)
    {
        table[index] = new LinkedList<tuple<KeyType, ValueType>>();
        table[index]->append(std::make_tuple(key, value));

        numBuckets++;
        numValues++;

        return;
    }

    LinkedListNode<tuple<KeyType, ValueType>> *currNode = table[index]->first();

    while (currNode != nullptr && std::get<0>(currNode->data) != key)
        currNode = currNode->next;

    if (currNode == nullptr)
    {
        auto keyValuePair = std::make_tuple(key, value);

        currNode = new LinkedListNode<tuple<KeyType, ValueType>>(keyValuePair);

        numValues++;
    }
    else
    {
        std::get<1>(currNode->data) = value;
    }
}

template <typename KeyType, typename ValueType>
size_t HashTable<KeyType, ValueType>::count(const KeyType &key) const
{
    if (numBuckets == 0 || numValues == 0)
        return 0;

    size_t count = 0;
    size_t index = this->getIndexForKey(key);

    LinkedListNode<tuple<KeyType, ValueType>> *currNode = table[index]->first();

    if (!currNode)
        return 0;

    while (currNode != nullptr)
    {
        if (std::get<0>(currNode->data) == key)
            count++;

        currNode = currNode->next;
    }

    return count;
}

template <typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::erase(const KeyType &key)
{
    if (numBuckets == 0 || numValues == 0)
        throw std::out_of_range("No values in table to remove");

    size_t index = this->getIndexForKey(key);

    LinkedListNode<tuple<KeyType, ValueType>> *currentNode = table[index]->first();

    while (currentNode != nullptr && std::get<0>(currentNode->data) != key)
        currentNode = currentNode->next;

    table[index]->deleteNode(currentNode);

    if (table[index]->count() == 0)
    {
        delete table[index];
        numBuckets--;
    }

    numValues--;
}

template <typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::clear()
{
    for (int i = 0; i < numBuckets; i++)
    {
        if (table[i] != nullptr)
        {
            table[i]->deleteAll();
            delete table[i];
            table[i] = nullptr;
        }
    }

    numBuckets = 0;
    numValues = 0;
}

template <typename KeyType, typename ValueType>
size_t HashTable<KeyType, ValueType>::bucketCount() const
{
    return numBuckets;
}

template <typename KeyType, typename ValueType>

size_t HashTable<KeyType, ValueType>::maxBucketCount() const
{
    return TABLE_SIZE;
}

template <typename KeyType, typename ValueType>
size_t HashTable<KeyType, ValueType>::bucketSize(const size_t &n) const
{
    if (table[n] == nullptr)
        return 0;

    return table[n]->count();
}

#endif