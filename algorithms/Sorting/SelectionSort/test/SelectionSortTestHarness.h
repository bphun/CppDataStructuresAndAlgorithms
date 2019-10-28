#ifndef SelectionSortTestHarness_h
#define SelectionSortTestHarness_h

#include "../../../util/SortingUtil.h"
#include "../SelectionSort.h"
#include "gtest/gtest.h"

#define ARRAY_SIZE 1000

TEST(SelectionSort, ArraySort)
{
    int arr[ARRAY_SIZE];
    size_t i = 0;

    while (i < ARRAY_SIZE) {
        int randNum = rand() % ARRAY_SIZE;

        while (valueIsInArray(arr, randNum, i))
            randNum = rand() % ARRAY_SIZE;

        arr[i++] = randNum;
    }

    selectionSort(arr, ARRAY_SIZE);

    EXPECT_TRUE(arrayIsSorted(arr, ARRAY_SIZE));
}

TEST(SelectionSort, PointerArraySort)
{
    int* arr[ARRAY_SIZE];
    size_t i = 0;

    while (i < ARRAY_SIZE) {
        int randNum = rand() % ARRAY_SIZE;

        while (valueIsInPointerArray(arr, randNum, i))
            randNum = rand() % ARRAY_SIZE;

        arr[i++] = new int(randNum);
    }

    selectionSort(arr, ARRAY_SIZE);

    EXPECT_TRUE(pointerArrayIsSorted(arr, ARRAY_SIZE));
}

TEST(SelectionSort, VectorSort)
{
    vector<int> arr(ARRAY_SIZE, 0);

    while (arr.size() < ARRAY_SIZE) {
        int randNum = rand() % ARRAY_SIZE;

        while (arr.size() != 0 && count(arr.begin(), arr.end(), randNum))
            randNum = rand() % ARRAY_SIZE;

        arr.push_back(randNum);
    }

    selectionSort(arr);

    EXPECT_TRUE(vectorIsSorted(arr));
}

#endif