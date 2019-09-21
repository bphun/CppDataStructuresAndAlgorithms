// Programmer: Brandon Phan
// Programmer's ID: 1731593

#ifndef LinkedListNode_h
#define LinkedListNode_h

#include <sstream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T> *next;

    Node(T);
    Node(const Node<T> &);

    Node<T> &operator=(const Node<T> &);

    string toString();
};

template <typename T>
Node<T>::Node(T value) : data(value), next(nullptr)
{
}

template <typename T>
Node<T>::Node(const Node<T> &newNode)
{
    this->data = newNode.data;
    this->next = newNode.next;
}

template <typename T>
Node<T> &Node<T>::operator=(const Node<T> &toCopy)
{
    this->data = toCopy.data;
    this->next = toCopy.next;

    return *this;
}

template <typename T>
string Node<T>::toString()
{
    stringstream ss;

    ss << data;

    return ss.str();
}

#endif /* Node_h */