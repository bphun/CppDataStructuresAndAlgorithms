#ifndef InterpolationSearch_h

#include <vector>

using namespace std;

template <typename T>
bool interpolationSearch(T arr[], const T &searchVal, const size_t &arrSize)
{
    if (arrSize == 0)
        return false;

    size_t start = 0;
    size_t end = arrSize - 1;

    while (start <= end && searchVal >= arr[start] && searchVal <= arr[end])
    {
        if (start == end)
        {
            if (arr[start] == searchVal)
                return true;

            return false;
        }

        int index = start + (((double)(end - start) / (arr[end] - arr[start])) * (searchVal - arr[start]));

        if (arr[index] == searchVal)
            return true;

        if (arr[index] < searchVal)
            start = index + 1;
        else
            end = index - 1;
    }

    return false;
}

template <typename T>
bool interpolationSearch(T **arr, const T &searchVal, const size_t &arrSize)
{
    if (arrSize == 0)
        return false;

    size_t start = 0;
    size_t end = arrSize - 1;

    while (start <= end && searchVal >= *arr[start] && searchVal <= *arr[end])
    {
        if (start == end)
        {
            if (*arr[start] == searchVal)
                return true;

            return false;
        }

        int index = start + (((double)(end - start) / (*arr[end] - *arr[start])) * (searchVal - *arr[start]));

        if (*arr[index] == searchVal)
            return true;

        if (*arr[index] < searchVal)
            start = index + 1;
        else
            end = index - 1;
    }

    return false;
}

template <typename T>
bool interpolationSearch(vector<T> arr, T searchVal)
{
    if (arr.size() == 0)
        return false;

    size_t start = 0;
    size_t end = arr.size() - 1;

    while (start <= end && searchVal >= arr[start] && searchVal <= arr[end])
    {
        if (start == end)
        {
            if (arr[start] == searchVal)
                return true;

            return false;
        }

        int index = start + (((double)(end - start) / (arr[end] - arr[start])) * (searchVal - arr[start]));

        if (arr[index] == searchVal)
            return true;

        if (arr[index] < searchVal)
            start = index + 1;
        else
            end = index - 1;
    }

    return false;
}

#endif