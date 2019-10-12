#ifndef SortingUtil_h
#define SortingUtil_h

#include <vector>

using namespace std;

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

#endif