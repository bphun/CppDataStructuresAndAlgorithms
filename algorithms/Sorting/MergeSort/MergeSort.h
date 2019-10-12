#ifndef MergeSort_h
#define MergeSort_h

#include <vector>

using namespace std;

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void merge(T arr[], const size_t& startIndex, const size_t& midIndex, const size_t& endIndex)
{
    T tmp[endIndex - startIndex + 1];
    size_t i = startIndex;
    size_t j = midIndex + 1;
    size_t k = 0;

    while (i <= midIndex && j <= endIndex) {
        if (arr[i] <= arr[j]) {
            tmp[k] = arr[i];
            i++;
        } else {
            tmp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= midIndex) {
        tmp[k] = arr[i];
        k++;
        i++;
    }

    while (j <= endIndex) {
        tmp[k] = arr[j];
        k++;
        j++;
    }

    for (size_t n = startIndex; n <= endIndex; n++) {
        arr[n] = tmp[n - startIndex];
    }
}

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void mergeSort(T arr[], const size_t& startIndex, const size_t& endIndex)
{
    if (startIndex < endIndex) {
        size_t midIndex = (startIndex + endIndex) / 2;

        mergeSort(arr, startIndex, midIndex);
        mergeSort(arr, midIndex + 1, endIndex);

        merge(arr, startIndex, midIndex, endIndex);
    }
}

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void merge(T* arr[], const size_t& startIndex, const size_t& midIndex, const size_t& endIndex)
{
    T* tmp[endIndex - startIndex + 1];
    size_t i = startIndex;
    size_t j = midIndex + 1;
    size_t k = 0;

    while (i <= midIndex && j <= endIndex) {
        if (*arr[i] <= *arr[j]) {
            tmp[k] = arr[i];
            i++;
        } else {
            tmp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= midIndex) {
        tmp[k] = arr[i];
        k++;
        i++;
    }

    while (j <= endIndex) {
        tmp[k] = arr[j];
        k++;
        j++;
    }

    for (size_t n = startIndex; n <= endIndex; n++) {
        arr[n] = tmp[n - startIndex];
    }
}

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void mergeSort(T* arr[], const size_t& startIndex, const size_t& endIndex)
{
    if (startIndex < endIndex) {
        size_t midIndex = (startIndex + endIndex) / 2;

        mergeSort(arr, startIndex, midIndex);
        mergeSort(arr, midIndex + 1, endIndex);

        merge(arr, startIndex, midIndex, endIndex);
    }
}

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void merge(vector<T> arr, const size_t& startIndex, const size_t& midIndex, const size_t& endIndex)
{
    T tmp[endIndex - startIndex + 1];
    size_t i = startIndex;
    size_t j = midIndex + 1;
    size_t k = 0;

    while (i <= midIndex && j <= endIndex) {
        if (arr[i] <= arr[j]) {
            tmp[k] = arr[i];
            i++;
        } else {
            tmp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= midIndex) {
        tmp[k] = arr[i];
        k++;
        i++;
    }

    while (j <= endIndex) {
        tmp[k] = arr[j];
        k++;
        j++;
    }

    for (size_t n = startIndex; n <= endIndex; n++) {
        arr[n] = tmp[n - startIndex];
    }
}

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void mergeSort(vector<T> arr, const size_t& startIndex, const size_t& endIndex)
{
    if (startIndex < endIndex) {
        size_t midIndex = (startIndex + endIndex) / 2;

        mergeSort(arr, startIndex, midIndex);
        mergeSort(arr, midIndex + 1, endIndex);

        merge(arr, startIndex, midIndex, endIndex);
    }
}

#endif