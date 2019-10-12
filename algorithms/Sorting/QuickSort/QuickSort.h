#ifndef QuickSort_h
#define QuickSort_h

#include <vector>
#include <iostream>
using namespace std;

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
size_t partition(T arr[], const int& startIndex, const int& endIndex)
{
    T pivot = arr[endIndex];
    int partitionIndex = startIndex;

    for (int i = startIndex; i < endIndex; i++) {
        if (arr[i] <= pivot) {
            swap(arr[partitionIndex], arr[i]);
            partitionIndex++;
        }
    }

    swap(arr[partitionIndex], arr[endIndex]);

    return partitionIndex;
}

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void quickSort(T arr[], const int& startIndex, const int& endIndex)
{
    if (startIndex < endIndex) {
        int partitionIndex = partition(arr, startIndex, endIndex);

        quickSort(arr, startIndex, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, endIndex);
    }
}

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
int partition(T* arr[], const int& startIndex, const int& endIndex)
{
    T pivot = *arr[endIndex];
    int i = startIndex - 1;

    for (int j = startIndex; j < endIndex; j++) {
        if (*arr[j] < pivot) {
            i++;
            swap(*arr[i], *arr[j]);
        }
    }

    swap(*arr[i + 1], *arr[endIndex]);

    return i + 1;
}

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void quickSort(T* arr[], const int& startIndex, const int& endIndex)
{
    if (startIndex < endIndex) {
        int partitionIndex = partition(arr, startIndex, endIndex);

        quickSort(arr, startIndex, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, endIndex);
    }
}

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
int partition(vector<T> arr, const int& startIndex, const int& endIndex)
{
    T pivot = arr[endIndex];
    int i = startIndex - 1;

    for (int j = startIndex; j < endIndex; j++) {
        if (arr[j] < pivot) {
            i++;
            // T tmp = arr[i];
            // arr[i] = arr[j];
            // arr[j] = tmp;
            swap(arr[i], arr[j]);
        }
    }

    // T tmp = arr[i + 1];
    // arr[i + 1] = arr[endIndex];
    // arr[endIndex] = tmp;
    swap(arr[i + 1], arr[endIndex]);

    return i + 1;
}

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void quickSort(vector<T> arr, const int& startIndex, const int& endIndex)
{
    if (startIndex < endIndex) {
        int partitionIndex = partition(arr, startIndex, endIndex);

        quickSort(arr, startIndex, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, endIndex);
    }
}

#endif