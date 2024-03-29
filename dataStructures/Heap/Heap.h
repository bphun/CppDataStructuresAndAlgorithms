#ifndef Heap_H
#define Heap_H

#include <math.h>
#include <vector>

using namespace std;

#define EMPTY_HEAP_EXCEPTION_MESSAGE "No elements in heap to pop"

template <typename T>
class Heap {

private:
    vector<T> heap;

protected:
    virtual bool pairIsInCorrectOrder(const T&, const T&) = 0;

public:
    size_t getLeftChildIndex(const size_t&) const;
    size_t getRightChildIndex(const size_t&) const;
    size_t getParentIndex(const size_t&) const;

    bool hasParent(const size_t&) const;
    bool hasLeftChild(const size_t&) const;
    bool hasRightChild(const size_t&) const;

    T leftChild(const size_t&) const;
    T rightChild(const size_t&) const;
    T parent(const size_t&) const;

    void swapValues(const size_t&, const size_t&);

    T peek();
    T poll();

    vector<int> find(const T&);

    void add(const T&);
    void remove(const T&);

    bool isEmpty();

    void heapifyUp(const int& startIndex = -1);
    void heapifyDown(const size_t& startIndex = 0);
};

template <typename T>
size_t Heap<T>::getLeftChildIndex(const size_t& parentIndex) const
{
    if (heap.size() == 0)
        throw std::out_of_range(EMPTY_HEAP_EXCEPTION_MESSAGE);

    return (2 * parentIndex) + 1;
}

template <typename T>
size_t Heap<T>::getRightChildIndex(const size_t& parentIndex) const
{
    if (heap.size() == 0)
        throw std::out_of_range(EMPTY_HEAP_EXCEPTION_MESSAGE);

    return (2 * parentIndex) + 2;
}

template <typename T>
size_t Heap<T>::getParentIndex(const size_t& childIndex) const
{
    if (heap.size() == 0)
        throw std::out_of_range(EMPTY_HEAP_EXCEPTION_MESSAGE);

    return floor(childIndex - 1) / 2;
}

template <typename T>
bool Heap<T>::hasParent(const size_t& childIndex) const
{
    return this->getParentIndex(childIndex) >= 0;
}

template <typename T>
bool Heap<T>::hasLeftChild(const size_t& parentIndex) const
{
    return this->getLeftChildIndex(parentIndex) < this->heap.size();
}

template <typename T>
bool Heap<T>::hasRightChild(const size_t& parentIndex) const
{
    return this->getRightChildIndex(parentIndex) < this->heap.size();
}

template <typename T>
T Heap<T>::leftChild(const size_t& parentIndex) const
{
    return this->heap[this->getLeftChildIndex(parentIndex)];
}

template <typename T>
T Heap<T>::rightChild(const size_t& parentIndex) const
{
    return this->heap[this->getRightChildIndex(parentIndex)];
}

template <typename T>
T Heap<T>::parent(const size_t& childIndex) const
{
    return this->heap[this->getParentIndex(childIndex)];
}

template <typename T>
void Heap<T>::swapValues(const size_t& indexA, const size_t& indexB)
{
    swap(heap[indexA], heap[indexB]);
}

template <typename T>
T Heap<T>::peek()
{
    if (heap.size() == 0)
        throw std::out_of_range(EMPTY_HEAP_EXCEPTION_MESSAGE);

    return this->heap[0];
}

template <typename T>
T Heap<T>::poll()
{
    if (heap.size() == 0)
        throw std::out_of_range(EMPTY_HEAP_EXCEPTION_MESSAGE);

    T value = heap.back();

    if (heap.size() == 1) {
        heap.pop_back();
        return value;
    }

    value = heap[0];

    heap[0] = heap.back();
    heap.pop_back();

    this->heapifyDown();

    return value;
}

template <typename T>
vector<int> Heap<T>::find(const T& value)
{
    vector<int> foundIndices;

    for (size_t i = 0; i < heap.size(); i++) {
        if (heap[i] == value)
            foundIndices.push_back(i);
    }
    return foundIndices;
}

template <typename T>
void Heap<T>::add(const T& value)
{
    this->heap.push_back(value);
    this->heapifyUp();
}

template <typename T>
void Heap<T>::remove(const T& value)
{
    vector<int> indicesToRemove = find(value);

    for (auto indexToRemove : indicesToRemove) {
        if (indexToRemove == heap.size() - 1) {
            heap.pop_back();
        } else {
            heap[indexToRemove] = heap.back();
            heap.pop_back();

            T parentItem = this->parent(indexToRemove);

            if (hasLeftChild(indexToRemove) && (hasParent(indexToRemove) || pairIsInCorrectOrder(parentItem, heap[indexToRemove]))) {
                heapifyDown(indexToRemove);
            } else {
                heapifyUp(indexToRemove);
            }
        }
    }
}

template <typename T>
bool Heap<T>::isEmpty()
{
    return this->heap.size() == 0;
}

template <typename T>
void Heap<T>::heapifyUp(const int& startIndex)
{
    int currIndex = startIndex < 0 ? this->heap.size() - 1 : startIndex;

    while (this->hasParent(currIndex) && !this->pairIsInCorrectOrder(this->parent(currIndex), heap[currIndex])) {
        this->swapValues(currIndex, this->getParentIndex(currIndex));

        currIndex = this->getParentIndex(currIndex);
    }
}

template <typename T>
void Heap<T>::heapifyDown(const size_t& startIndex)
{
    size_t currIndex = startIndex;
    size_t nextIndex = -1;

    while (this->hasLeftChild(currIndex)) {
        if (this->hasRightChild(currIndex) && this->pairIsInCorrectOrder(this->rightChild(currIndex), this->leftChild(currIndex)))
            nextIndex = this->getRightChildIndex(currIndex);
        else
            nextIndex = this->getLeftChildIndex(currIndex);

        if (this->pairIsInCorrectOrder(this->heap[currIndex], this->heap[nextIndex]))
            break;

        this->swapValues(currIndex, nextIndex);
        currIndex = nextIndex;
    }
}

#endif