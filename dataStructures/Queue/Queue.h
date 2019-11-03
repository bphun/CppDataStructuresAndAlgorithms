#ifndef Queue_h
#define Queue_h

#include "../LinkedList/LinkedList.h"

template <typename T>
class Queue {

    LinkedList<T> linkedList;

public:
    T& first() const;
    T& last() const;

    void push(const T&);
    void pop();

    bool empty() const;
    size_t size() const;
};

template <typename T>
bool Queue<T>::empty() const
{
    return !linkedList.first();
}

template <typename T>
size_t Queue<T>::size() const
{
    return linkedList.count();
}

template <typename T>
T& Queue<T>::first() const
{
    return linkedList.first()->data;
}

template <typename T>
T& Queue<T>::last() const
{
    return linkedList.last()->data;
}

template <typename T>
void Queue<T>::pop()
{
    linkedList.deleteHead();
}

template <typename T>
void Queue<T>::push(const T& value)
{
    linkedList.append(value);
}

#endif