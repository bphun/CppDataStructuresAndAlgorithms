#ifndef MergeSort_h
#define MergeSort_h

#include <vector>

using namespace std;

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void merge(T arr[], const int& startIndex, const int& midIndex, const int& endIndex)
{
    T tmp[endIndex - startIndex + 1];
    int i = startIndex;
    int j = midIndex + 1;
    int k = 0;

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

    for (int n = startIndex; n <= endIndex; n++) {
        arr[n] = tmp[n - startIndex];
    }
}

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void mergeSort(T arr[], const int& startIndex, const int& endIndex)
{
    if (startIndex < endIndex) {
        int midIndex = (startIndex + endIndex) / 2;

        mergeSort(arr, startIndex, midIndex);
        mergeSort(arr, midIndex + 1, endIndex);

        merge(arr, startIndex, midIndex, endIndex);
    }
}

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void merge(T* arr[], const int& startIndex, const int& midIndex, const int& endIndex)
{
    T* tmp[endIndex - startIndex + 1];
    int i = startIndex;
    int j = midIndex + 1;
    int k = 0;

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

    for (int n = startIndex; n <= endIndex; n++) {
        arr[n] = tmp[n - startIndex];
    }
}

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void mergeSort(T* arr[], const int& startIndex, const int& endIndex)
{
    if (startIndex < endIndex) {
        int midIndex = (startIndex + endIndex) / 2;

        mergeSort(arr, startIndex, midIndex);
        mergeSort(arr, midIndex + 1, endIndex);

        merge(arr, startIndex, midIndex, endIndex);
    }
}

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void merge(vector<T> arr, const int& startIndex, const int& midIndex, const int& endIndex)
{
    T tmp[endIndex - startIndex + 1];
    int i = startIndex;
    int j = midIndex + 1;
    int k = 0;

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

    for (int n = startIndex; n <= endIndex; n++) {
        arr[n] = tmp[n - startIndex];
    }
}

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void mergeSort(vector<T> arr, const int& startIndex, const int& endIndex)
{
    if (startIndex < endIndex) {
        int midIndex = (startIndex + endIndex) / 2;

        mergeSort(arr, startIndex, midIndex);
        mergeSort(arr, midIndex + 1, endIndex);

        merge(arr, startIndex, midIndex, endIndex);
    }
}

#endif