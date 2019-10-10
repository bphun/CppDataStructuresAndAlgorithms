#ifndef ReverseLinkedListTraversal_h

#include "../../../dataStructures/LinkedList/LinkedList.h"
#include "../../../dataStructures/LinkedList/LinkedListNode.h"

template <typename T>
void reverseTraversal(const LinkedList<T>& ll, void (* callback)(int) = nullptr) {
    reverseTraversalHelper(ll.first(), callback);
}

template <typename T>
void reverseTraversalHelper(const LinkedListNode<T>* node, void (* callback)(int) = nullptr) {
    if (node) {
        reverseTraversalHelper(node->next, callback);
        callback(node->data);
    }
}

#endif