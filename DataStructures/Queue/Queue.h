#ifndef Queue_h
#define Queue_h

#include "../LinkedList/LinkedList.h"

template <typename T>
class Queue
{

    LinkedList<T> linkedList;

public:

    bool empty() const;

    size_t size() const;

    T& front() const;
    T& back() const;
    void pop();

    void push(const T &);
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
T& Queue<T>::front() const
{
    return linkedList.first()->data;
}

template <typename T>
T& Queue<T>::back() const
{
    return linkedList.last()->data;
}

template <typename T>
void Queue<T>::pop()
{
    linkedList.deleteHead();
}

template <typename T>
void Queue<T>::push(const T &value)
{
    linkedList.append(value);
}

#endif