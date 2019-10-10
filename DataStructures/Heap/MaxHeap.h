#ifndef MaxHeap_H
#define MaxHeap_H

#include "Heap.h"

template <typename T>
class MaxHeap : public Heap<T>
{

public:
    bool pairIsInCorrectOrder(const T &, const T &);
};

template <typename T>
bool MaxHeap<T>::pairIsInCorrectOrder(const T &valueOne, const T &valueTwo)
{
    return valueOne >= valueTwo;
}

#endif