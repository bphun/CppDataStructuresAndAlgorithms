#include "../MergeSort.h"
#include "gtest/gtest.h"

#define ARRAY_SIZE 1000

int main(int argc, char** argv)
{
    srand(time(nullptr));

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

bool valueIsInArray(int arr[], const int& value, const size_t& arrSize)
{
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == value)
            return true;
    }

    return false;
}

bool valueIsInPointerArray(int* arr[], const int& value, const size_t& arrSize)
{
    for (int i = 0; i < arrSize; i++) {
        if (*arr[i] == value)
            return true;
    }

    return false;
}

bool arrayIsSorted(int arr[], const size_t& arrSize)
{
    int prev = arr[0];
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] < prev)
            return false;
        prev = arr[i];
    }

    return true;
}

bool pointerArrayIsSorted(int* arr[], const size_t& arrSize)
{
    int prev = *arr[0];
    for (int i = 1; i < arrSize; i++) {
        if (*arr[i] < prev)
            return false;
        prev = *arr[i];
    }

    return true;
}

bool vectorIsSorted(vector<int> arr)
{
    int prev = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < prev)
            return false;
        prev = arr[i];
    }

    return true;
}

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