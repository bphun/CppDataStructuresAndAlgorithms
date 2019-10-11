#ifndef BinarySearch_h

#include <vector>

using namespace std;

template <typename T>
bool binarySearch(T arr[], const T &searchVal, const size_t &arrSize)
{
    if (arrSize == 0) { return false; }

    size_t first = 0;
    size_t last = arrSize - 1;
    size_t mid;

    while (first <= last)
    {
        mid = (first + last) / 2;

        if (arr[mid] == searchVal)
            return true;
        else if (arr[mid] > searchVal)
            last = mid - 1;
        else
            first = mid + 1;
    }

    return false;
}

template <typename T>
bool binarySearch(T *arr[], const T &searchVal, const size_t &arrSize)
{
    if (arrSize == 0) { return false; }

    size_t first = 0;
    size_t last = arrSize - 1;
    size_t mid;

    while (first <= last)
    {
        mid = (first + last) / 2;

        if (*arr[mid] == searchVal)
            return true;
        else if (*arr[mid] > searchVal)
            last = mid - 1;
        else
            first = mid + 1;
    }

    return false;
}

template <typename T>
bool binarySearch(vector<T> vec, const T &searchVal)
{
    if (vec.size() == 0) { return false; }

    size_t first = 0;
    size_t last = vec.size() - 1;
    size_t mid;

    while (first <= last)
    {
        mid = (first + last) / 2;

        if (vec[mid] == searchVal)
            return true;
        else if (vec[mid] > searchVal)
            last = mid - 1;
        else
            first = mid + 1;
    }

    return false;
}

#endif