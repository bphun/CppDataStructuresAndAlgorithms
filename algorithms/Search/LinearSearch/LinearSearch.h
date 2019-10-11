#ifndef LinearSearch_h

#include <vector>

using namespace std;

template <typename T>
bool linearSearch(T arr[], const T &searchVal, const size_t &arrSize)
{
    if (arrSize == 0)
        return false;

    for (size_t i = 0; i < arrSize; i++)
        if (arr[i] == searchVal)
            return true;

    return false;
}

template <typename T>
bool linearSearch(T **arr, const T &searchVal, const size_t &arrSize)
{
    if (arrSize == 0)
        return false;

    for (size_t i = 0; i < arrSize; i++)
        if (*arr[i] == searchVal)
            return true;

    return false;
}

template <typename T>
bool linearSearch(vector<T> arr, T searchVal)
{
    if (arr.size() == 0)
        return false;

    for (size_t i = 0; i < arr.size(); i++)
        if (arr[i] == searchVal)
            return true;

    return false;
}

#endif