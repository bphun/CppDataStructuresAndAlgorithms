#ifndef SortingUtil_h
#define SortingUtil_h

#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

template <typename T>
bool valueIsInArray(T arr[], const T& value, const size_t& arrSize)
{
    for (size_t i = 0; i < arrSize; i++) {
        if (arr[i] == value)
            return true;
    }

    return false;
}

template <typename T>
bool valueIsInPointerArray(T* arr[], const T& value, const size_t& arrSize)
{
    for (size_t i = 0; i < arrSize; i++) {
        if (*arr[i] == value)
            return true;
    }

    return false;
}

template <typename T>
bool arrayIsSorted(T arr[], const size_t& arrSize)
{
    T prev = arr[0];
    for (size_t i = 1; i < arrSize; i++) {
        if (arr[i] < prev)
            return false;
        prev = arr[i];
    }

    return true;
}

template <typename T>
bool pointerArrayIsSorted(T* arr[], const size_t& arrSize)
{
    T prev = *arr[0];
    for (size_t i = 1; i < arrSize; i++) {
        if (*arr[i] < prev)
            return false;
        prev = *arr[i];
    }

    return true;
}

template <typename T>
bool vectorIsSorted(const vector<T>& arr)
{
    T prev = arr[0];
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < prev)
            return false;
        prev = arr[i];
    }

    return true;
}

#endif