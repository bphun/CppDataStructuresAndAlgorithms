#ifndef LinkedList_h
#define LinkedList_h

#include "LinkedListNode.h"

template <typename T>
class LinkedList
{

    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
    size_t size = 0;

    static constexpr bool typeIsArithmetic = is_arithmetic<T>::value;

public:
    void append(const T &);
    void prepend(const T &);
    void addValueToSortedList(const T &);

    void deleteNodeWithValue(const T &);
    void deleteHead();
    void deleteTail();
    void deleteAll();

    void sort();

    Node<T> *first() const;
    Node<T> *last() const;
    size_t count() const;

    void print();
};

template <typename T>
void LinkedList<T>::append(const T &value)
{
    Node<T> *newNode = new Node<T>(value);

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
    Node<T> *newNode = new Node<T>(value);

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

    Node<T> *newNode = new Node<T>(value);

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

        Node<T> *currentNode = head;

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

template <typename T>
void LinkedList<T>::deleteNodeWithValue(const T &value)
{
    if (head == nullptr)
        return;

    Node<T> *currentNode = head;
    Node<T> *previousNode = nullptr;

    //  Search for the node with the same data as value
    while (currentNode != nullptr && currentNode->data != value)
    {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    if (previousNode != nullptr)
    {
        //  Remove node that is neither head or tail
        previousNode->next = currentNode->next;
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
void LinkedList<T>::deleteHead()
{
    if (head == nullptr)
        return;

    Node<T> *newHead = head->next;

    delete head;

    head = newHead;

    size--;
}

template <typename T>
void LinkedList<T>::deleteTail()
{
    if (head == nullptr)
        return;

    Node<T> *currNode = head;

    while (currNode->next != tail)
    {
        currNode = currNode->next;
    }

    delete tail;

    tail = currNode;
    currNode->next = tail;

    size--;
}

template <typename T>
void LinkedList<T>::deleteAll()
{
    Node<T> *currentNode = head;
    Node<T> *next = nullptr;

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

    Node<T> *currentNode = head;
    Node<T> *nextNode = nullptr;
    Node<T> *pivotNode = nullptr;

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
Node<T> *LinkedList<T>::first() const
{
    return head;
}

template <typename T>
Node<T> *LinkedList<T>::last() const
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
    Node<T> *currentNode = head;

    while (currentNode != nullptr)
    {
        printf("%s -> ", currentNode->toString().c_str());
        currentNode = currentNode->next;
    }

    printf("@\n");
}

#endif /* LinkedList_h */
