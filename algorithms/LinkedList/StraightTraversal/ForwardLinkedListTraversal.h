#ifndef ForwardLinkedListTraversal_h

#include "../../../dataStructures/LinkedList/LinkedList.h"
#include "../../../dataStructures/LinkedList/LinkedListNode.h"

#ifdef TEST
#include <iostream>
#endif

template <typename T>
void forwardTraversal(const LinkedList<T>& ll, void (* callback)(int)) {
    LinkedListNode<T>* currNode = ll.first();

    while (currNode != nullptr)
    {
        currNode = currNode->next;
        
        #ifdef TEST
        if (currNode)
            callback(currNode->data);
        #endif
    }
}

#endif