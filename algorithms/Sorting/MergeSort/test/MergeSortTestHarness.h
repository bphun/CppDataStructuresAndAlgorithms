#ifndef MergeSortTestHarness_h
#define MergeSortTestHarness_h

#include "../../../util/SortingUtil.h"
#include "../MergeSort.h"

#define ARRAY_SIZE 1000

TEST(MergeSort, ArraySort)
{
    int arr[ARRAY_SIZE];
    size_t i = 0;

    while (i < ARRAY_SIZE) {
        int randNum = rand() % ARRAY_SIZE;

        while (valueIsInArray(arr, randNum, i))
            randNum = rand() % ARRAY_SIZE;

        arr[i++] = randNum;
    }

    mergeSort(arr, 0, ARRAY_SIZE - 1);

    EXPECT_TRUE(arrayIsSorted(arr, ARRAY_SIZE));
}

TEST(MergeSort, PointerArraySort)
{
    int* arr[ARRAY_SIZE];
    size_t i = 0;

    while (i < ARRAY_SIZE) {
        int randNum = rand() % ARRAY_SIZE;

        while (valueIsInPointerArray(arr, randNum, i))
            randNum = rand() % ARRAY_SIZE;

        arr[i++] = new int(randNum);
    }

    mergeSort(arr, 0, ARRAY_SIZE - 1);

    EXPECT_TRUE(pointerArrayIsSorted(arr, ARRAY_SIZE));
}

TEST(MergeSort, VectorSort)
{
    vector<int> arr(ARRAY_SIZE, 0);

    while (arr.size() < ARRAY_SIZE) {
        int randNum = rand() % ARRAY_SIZE;

        while (arr.size() != 0 && count(arr.begin(), arr.end(), randNum))
            randNum = rand() % ARRAY_SIZE;

        arr.push_back(randNum);
    }

    mergeSort(arr, 0, arr.size() - 1);

    EXPECT_TRUE(vectorIsSorted(arr));
}

#endif