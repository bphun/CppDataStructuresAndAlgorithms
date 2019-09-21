#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include "DoublyLinkedListNode.h"

using namespace std;

template <typename T>
class DoublyLinkedList
{

    DoublyLinkedListNode<T> *head = nullptr;
    DoublyLinkedListNode<T> *tail = nullptr;
    size_t size = 0;

public:
    void prepend(T);
    void append(const T &);

    void removeNodeWithValue(const T &);
    void removeHead();
    void removeTail();
    void removeAll();

    DoublyLinkedListNode<T> *first() const;
    DoublyLinkedListNode<T> *last() const;
    size_t count() const;

    void print();
};

template <typename T>
void DoublyLinkedList<T>::prepend(T value)
{
    DoublyLinkedListNode<T> *newNode = new DoublyLinkedListNode<T>(value);

    size++;

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    head->prev = newNode;
    newNode->next = head;

    head = newNode;
}

template <typename T>
void DoublyLinkedList<T>::append(const T &value)
{
    DoublyLinkedListNode<T> *newNode = new DoublyLinkedListNode<T>(value);

    size++;

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

template <typename T>
void DoublyLinkedList<T>::removeNodeWithValue(const T &value)
{
    if (head == nullptr)
        return;

    DoublyLinkedListNode<T> *currNode = head;

    while (currNode != nullptr && currNode->data != value)
        currNode = currNode->next;

    if (head == currNode)
        head = currNode->next;

    if (currNode->next != nullptr)
        currNode->next->prev = currNode->prev;

    if (currNode->prev != nullptr)
        currNode->prev->next = currNode->next;

    if (tail == currNode)
        tail = currNode->prev;
        
    delete currNode;

    size--;
}

template <typename T>
void DoublyLinkedList<T>::removeHead()
{
    if (head == nullptr)
        return;

    DoublyLinkedListNode<T> *newHead = head->next;
    newHead->prev = nullptr;

    delete head;
    head = newHead;

    size--;
}

template <typename T>
void DoublyLinkedList<T>::removeTail()
{
    if (tail == nullptr)
        return;

    DoublyLinkedListNode<T> *newTail = tail->prev;

    delete tail;

    tail = newTail;
    newTail->next = tail;

    size--;
}

template <typename T>
void DoublyLinkedList<T>::removeAll()
{
    if (head == nullptr)
        return;

    DoublyLinkedListNode<T> *currNode = head;
    DoublyLinkedListNode<T> *nextNode = nullptr;

    while (currNode->data != nullptr)
    {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }

    delete head;
    delete tail;

    head = nullptr;
    tail = nullptr;

    size = 0;
}

template <typename T>
DoublyLinkedListNode<T> *DoublyLinkedList<T>::first() const
{
    return head;
}

template <typename T>
DoublyLinkedListNode<T> *DoublyLinkedList<T>::last() const
{
    return tail;
}

template <typename T>
size_t DoublyLinkedList<T>::count() const
{
    return size;
}

template <typename T>
void DoublyLinkedList<T>::print()
{
    DoublyLinkedListNode<T> *currentNode = head;

    while (currentNode != nullptr)
    {
        printf("%d <-> ", currentNode->data);
        currentNode = currentNode->next;
    }

    printf("@\n");
}

#endif