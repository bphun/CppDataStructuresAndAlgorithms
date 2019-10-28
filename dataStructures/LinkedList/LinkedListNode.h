// Programmer: Brandon Phan
// Programmer's ID: 1731593

#ifndef LinkedListNode_h
#define LinkedListNode_h

#include <sstream>
using namespace std;

template <typename T>
struct LinkedListNode {
    T data;
    LinkedListNode<T>* next;

    LinkedListNode(T);
    LinkedListNode(const LinkedListNode<T>&);

    LinkedListNode<T>& operator=(const LinkedListNode<T>&);

    string toString();
};

template <typename T>
LinkedListNode<T>::LinkedListNode(T value)
    : data(value)
    , next(nullptr)
{
}

template <typename T>
LinkedListNode<T>::LinkedListNode(const LinkedListNode<T>& newNode)
{
    this->data = newNode.data;
    this->next = newNode.next;
}

template <typename T>
LinkedListNode<T>& LinkedListNode<T>::operator=(const LinkedListNode<T>& toCopy)
{
    this->data = toCopy.data;
    this->next = toCopy.next;

    return *this;
}

template <typename T>
string LinkedListNode<T>::toString()
{
    stringstream ss;

    ss << data;

    return ss.str();
}

#endif /* Node_h */