#ifndef QuickSortTestHarness_h
#define QuickSortTestHarness_h

#include "../../../util/SortingUtil.h"
#include "../QuickSort.h" 

#define ARRAY_SIZE 1000

TEST(QuickSort, ArraySort)
{
    int arr[ARRAY_SIZE];
    size_t i = 0;

    while (i < ARRAY_SIZE) {
        int randNum = rand() % ARRAY_SIZE;

        while (valueIsInArray(arr, randNum, i))
            randNum = rand() % ARRAY_SIZE;

        arr[i++] = randNum;
    }

    quickSort(arr, 0, ARRAY_SIZE - 1);

    EXPECT_TRUE(arrayIsSorted(arr, ARRAY_SIZE));
}

TEST(QuickSort, PointerArraySort)
{
    int* arr[ARRAY_SIZE];
    size_t i = 0;

    while (i < ARRAY_SIZE) {
        int randNum = rand() % ARRAY_SIZE;

        while (valueIsInPointerArray(arr, randNum, i))
            randNum = rand() % ARRAY_SIZE;

        arr[i++] = new int(randNum);
    }

    quickSort(arr, 0, ARRAY_SIZE - 1);

    EXPECT_TRUE(pointerArrayIsSorted(arr, ARRAY_SIZE));

    for (int i = 0; i < ARRAY_SIZE; i++)
        delete arr[i];
}

TEST(QuickSort, VectorSort)
{
    vector<int> arr(ARRAY_SIZE, 0);

    while (arr.size() < ARRAY_SIZE) {
        int randNum = rand() % ARRAY_SIZE;

        while (arr.size() != 0 && count(arr.begin(), arr.end(), randNum))
            randNum = rand() % ARRAY_SIZE;

        arr.push_back(randNum);
    }

    quickSort(arr, 0, ARRAY_SIZE - 1);

    EXPECT_TRUE(vectorIsSorted(arr));
}

#endif