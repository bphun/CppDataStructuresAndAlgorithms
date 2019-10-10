#ifndef ForwardLinkedListTraversal_h

#include "../../../dataStructures/LinkedList/LinkedList.h"
#include "../../../dataStructures/LinkedList/LinkedListNode.h"

template <typename T>
void forwardTraversal(const LinkedList<T>& ll, void (* callback)(int) = nullptr) {
    LinkedListNode<T>* currNode = ll.first();

    while (currNode != nullptr)
    {
        currNode = currNode->next;
        
        #ifdef TEST
        if (currNode && callback)
            callback(currNode->data);
        #endif
    }
}

#endif