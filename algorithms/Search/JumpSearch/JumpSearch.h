#ifndef JumpSearch_h
#define JumpSearch_h

#include <math.h>
#include <vector>

using namespace std;

template <typename T>
bool jumpSearch(T arr[], const T& searchVal, const size_t& arrSize)
{
    if (arrSize == 0)
        return false;

    size_t stepSize = sqrt(arrSize);
    size_t prev = 0;

    while (arr[min(stepSize, arrSize) - 1] < searchVal) {
        prev = stepSize;
        stepSize += sqrt(arrSize);

        if (prev >= arrSize)
            return false;
    }

    while (arr[prev] < searchVal) {
        prev++;

        if (prev == min(stepSize, arrSize))
            return false;
    }

    if (arr[prev] == searchVal)
        return true;

    return false;
}

template <typename T>
bool jumpSearch(T** arr, const T& searchVal, const size_t& arrSize)
{
    if (arrSize == 0)
        return false;

    size_t stepSize = sqrt(arrSize);
    int prev = 0;

    while (*arr[min(stepSize, arrSize) - 1] < searchVal) {
        prev = stepSize;
        stepSize += sqrt(arrSize);

        if (prev >= arrSize)
            return false;
    }

    while (*arr[prev] < searchVal) {
        prev++;

        if (prev == min(stepSize, arrSize))
            return false;
    }

    if (*arr[prev] == searchVal)
        return true;

    return false;
}

template <typename T>
bool jumpSearch(vector<T> arr, T searchVal)
{
    if (arr.size() == 0)
        return false;

    size_t arrSize = arr.size();
    size_t stepSize = sqrt(arrSize);
    int prev = 0;

    while (arr[min(stepSize, arrSize) - 1] < searchVal) {
        prev = stepSize;
        stepSize += sqrt(arrSize);

        if (prev >= arrSize)
            return false;
    }

    while (arr[prev] < searchVal) {
        prev++;

        if (prev == min(stepSize, arrSize))
            return false;
    }

    if (arr[prev] == searchVal)
        return true;

    return false;
}

#endif