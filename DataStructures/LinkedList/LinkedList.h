#ifndef LinkedList_h
#define LinkedList_h

#include "LinkedListNode.h"

template <typename T>
class LinkedList
{

    LinkedListNode<T> *head = nullptr;
    LinkedListNode<T> *tail = nullptr;
    size_t size = 0;

    static constexpr bool typeIsArithmetic = is_arithmetic<T>::value;

public:
    void append(const T &);
    void prepend(const T &);
    void addValueToSortedList(const T &);

    void deleteNodeWithValue(const T &);
    void deleteNode(LinkedListNode<T> *);
    void deleteHead();
    void deleteTail();
    void deleteAll();

    void sort();

    LinkedListNode<T> *first() const;
    LinkedListNode<T> *last() const;
    size_t count() const;

    void print();
};

template <typename T>
void LinkedList<T>::append(const T &value)
{
    LinkedListNode<T> *newNode = new LinkedListNode<T>(value);

    size++;

    //  The linked list is empty so make the new node the head of the linked list and return
    if (head == nullptr)
    {
        head = newNode;
        tail = head;
        return;
    }

    //  Linked list is not empty so add the new node to the end of the list
    tail->next = newNode;
    tail = newNode;
}

template <typename T>
void LinkedList<T>::prepend(const T &value)
{
    LinkedListNode<T> *newNode = new LinkedListNode<T>(value);

    size++;

    if (head == nullptr)
    {
        head = newNode;
        tail = head;
        return;
    }

    newNode->next = head;
    head = newNode;
}

template <typename T>
void LinkedList<T>::addValueToSortedList(const T &value)
{
    static_assert(typeIsArithmetic, "T must be an arithmetic datatype in order to be sorted");

    LinkedListNode<T> *newNode = new LinkedListNode<T>(value);

    size++;

    if (head == nullptr)
    {
        //  List is empty so make the new node the head of the linked list
        head = newNode;
        tail = head;
    }
    else if (newNode->data < head->data)
    {
        /*
        * The new node's value is less than head's value so insert
        * it into the linked list before head and make the new node the head
        */

        newNode->next = head;
        head = newNode;
    }
    else
    {
        /*
        * The new node's value is greater than head so find an appropriate
        * spot to insert the new node
        */

        LinkedListNode<T> *currentNode = head;

        while (currentNode->next != nullptr && currentNode->next->data < newNode->data)
            currentNode = currentNode->next;

        if (currentNode->next == nullptr)
        {
            currentNode->next = newNode;
        }
        else
        {
            newNode->next = currentNode->next;
            currentNode->next = newNode;
        }
    }
}
#include <iostream>
using namespace std;
template <typename T>
void LinkedList<T>::deleteNodeWithValue(const T &value)
{
    if (head == nullptr)
        return;

    LinkedListNode<T> *currentNode = head;
    LinkedListNode<T> *previousNode = nullptr;

    //  Search for the node with the same data as value
    while (currentNode != nullptr && currentNode->data != value)
    {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    if (previousNode != nullptr)
    {
        //  Remove node that is neither head or tail
        // *(previousNode->next) = *(currentNode->next);
        previousNode->next = currentNode->next;
        
        if (currentNode == tail)
            tail = previousNode;
    }
    else if (currentNode->next != nullptr && previousNode == nullptr)
    {
        //  Removing first node of list
        head = currentNode->next;
    }
    else
    {
        //  List only had one element so set head and tail to nullptr
        head = nullptr;
        tail = nullptr;
    }

    delete currentNode;

    size--;
}

template <typename T>
void LinkedList<T>::deleteNode(LinkedListNode<T> *node)
{
    this->deleteNodeWithValue(node->data);
}

template <typename T>
void LinkedList<T>::deleteHead()
{
    if (head == nullptr)
        return;

    LinkedListNode<T> *newHead = head->next;

    delete head;

    head = newHead;

    size--;
}

template <typename T>
void LinkedList<T>::deleteTail()
{
    if (head == nullptr)
        return;

    LinkedListNode<T> *currNode = head;

    while (currNode->next != tail)
        currNode = currNode->next;

    delete tail;

    tail = currNode;
    currNode->next = tail;

    size--;
}

template <typename T>
void LinkedList<T>::deleteAll()
{
    LinkedListNode<T> *currentNode = head;
    LinkedListNode<T> *next = nullptr;

    //  Iterate through the linked list and remove each node
    while (currentNode != nullptr)
    {
        next = currentNode->next;
        delete currentNode;
        currentNode = next;
    }

    head = nullptr;
    tail = nullptr;

    size = 0;
}

template <typename T>
void LinkedList<T>::sort()
{
    if (head == nullptr)
        return;

    static_assert(typeIsArithmetic, "T must be an arithmetic datatype in order to be sorted");

    LinkedListNode<T> *currentNode = head;
    LinkedListNode<T> *nextNode = nullptr;
    LinkedListNode<T> *pivotNode = nullptr;

    while (currentNode->next != nullptr)
    {

        nextNode = currentNode->next;
        pivotNode = currentNode;

        /*
        * Iterate through every node after currentNode and find a node 
        * that contains a value that is smaller than the pivot's value
        */
        while (nextNode != nullptr)
        {
            if (pivotNode->data > nextNode->data)
                pivotNode = nextNode;

            nextNode = nextNode->next;
        }

        //  Swap values of the pivot node and current node
        T tmpVal = currentNode->data;
        currentNode->data = pivotNode->data;
        pivotNode->data = tmpVal;

        currentNode = currentNode->next;
    }
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::first() const
{
    return head;
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::last() const
{
    return tail;
}

template <typename T>
size_t LinkedList<T>::count() const
{
    return size;
}

template <typename T>
void LinkedList<T>::print()
{
    LinkedListNode<T> *currentNode = head;

    while (currentNode != nullptr)
    {
        printf("%s -> ", currentNode->toString().c_str());
        currentNode = currentNode->next;
    }

    printf("@\n");
}

#endif /* LinkedList_h */
