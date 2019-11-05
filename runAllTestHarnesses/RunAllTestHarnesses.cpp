#include "gtest/gtest.h"

#include "../algorithms/LinkedList/ReverseTraversal/test/ReverseTraversalTestHarness.h"
#include "../algorithms/LinkedList/StraightTraversal/test/ForwardLinkedListTraversalTestHarness.h"

#include "../algorithms/Search/BinarySearch/test/BinarySearchTestHarness.h"
#include "../algorithms/Search/InterpolationSearch/test/InterpolationSearchTestHarness.h"
#include "../algorithms/Search/JumpSearch/test/JumpSearchTestHarness.h"
#include "../algorithms/Search/LinearSearch/test/LinearSearchTestHarness.h"

#include "../algorithms/Sets/CartesianProduct/test/CartesianProductTestHarness.h"
#include "../algorithms/Sets/LongestIncreasingSubsequence/test/LongestIncreasingSubsequenceTestHarness.h"
#include "../algorithms/Sets/PowerSet/test/PowerSetTestHarness.h"

#include "../algorithms/Sorting/BubbleSort/test/BubbleSortTestHarness.h"
#include "../algorithms/Sorting/CountingSort/test/CountingSortTestHarness.h"
#include "../algorithms/Sorting/InsertionSort/test/InsertionSortTestHarness.h"
#include "../algorithms/Sorting/MergeSort/test/MergeSortTestHarness.h"
#include "../algorithms/Sorting/QuickSort/test/QuickSortTestHarness.h"
#include "../algorithms/Sorting/SelectionSort/test/SelectionSortTestHarness.h"
#include "../algorithms/Sorting/ShellSort/test/ShellSortTestHarness.h"

#include "../algorithms/Strings/HammingDistance/test/HammingDistanceTestHarness.h"
#include "../algorithms/Strings/KnuthMorrisPrattAlgorithm/test/KnuthMorrisPrattAlgorithmTestHarness.h"
#include "../algorithms/Strings/LevenshteinDistance/test/LevenshteinStringDistanceTestHarness.h"

#include "../dataStructures/DoublyLinkedList/test/DoublyLinkedListTestHarness.h"
#include "../dataStructures/HashTable/test/HashTableTestHarness.h"
#include "../dataStructures/Heap/test/HeapTestHarness.h"
#include "../dataStructures/LinkedList/test/LinkedListTestHarness.h"
#include "../dataStructures/Queue/test/QueueTestHarness.h"
#include "../dataStructures/Stack/test/StackTestHarness.h"

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}