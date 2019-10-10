#ifndef MinHeap_H
#define MinHeap_H

#include "Heap.h"

template <typename T>
class MinHeap : public Heap<T>
{

public:
    bool pairIsInCorrectOrder(const T &, const T &);
};

template <typename T>
bool MinHeap<T>::pairIsInCorrectOrder(const T &valueOne, const T &valueTwo)
{
    return valueOne <= valueTwo;
}

#endif