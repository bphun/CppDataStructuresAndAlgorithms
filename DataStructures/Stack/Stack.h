#ifndef Stack_h
#define Stack_h

#include "../LinkedList/LinkedList.h"

template <typename T>
class Stack
{

    LinkedList<T> linkedList;

public:
    T top();

    void push(const T &);
    void pop();

    size_t size() const;
    bool empty() const;
};

template <typename T>
T Stack<T>::top()
{
    return linkedList.first()->data;
}

template <typename T>
void Stack<T>::push(const T &value)
{
    linkedList.prepend(value);
}

template <typename T>
void Stack<T>::pop()
{
    linkedList.deleteHead();
}

template <typename T>
size_t Stack<T>::size() const
{
    return linkedList.count();
}

template <typename T>
bool Stack<T>::empty() const
{
    return size() == 0;
}

#endif