#ifndef DoublyLinkedListNode_h
#define DoublyLinkedListNode_h

template <typename T>
struct DoublyLinkedListNode {
    T data;

    DoublyLinkedListNode<T>* prev;
    DoublyLinkedListNode<T>* next;

    DoublyLinkedListNode(T value)
        : data(value)
        , prev(nullptr)
        , next(nullptr)
    {
    }
};

#endif