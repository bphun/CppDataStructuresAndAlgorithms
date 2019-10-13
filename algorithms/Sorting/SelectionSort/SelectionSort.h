#ifndef SelectionSort_h
#define SelectionSort_h

#include <vector>

using namespace std;

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void selectionSort(T arr[], const int& arrSize)
{
    int minIndex;

    for (int i = 0; i < arrSize - 1; i++) {
        minIndex = i;

        for (int j = i + 1; j < arrSize; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;

        swap(arr[minIndex], arr[i]);
    }
}

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void selectionSort(T* arr[], const int& arrSize)
{
    int minIndex;

    for (int i = 0; i < arrSize - 1; i++) {
        minIndex = i;

        for (int j = i + 1; j < arrSize; j++)
            if (*arr[j] < *arr[minIndex])
                minIndex = j;

        swap(*arr[minIndex], *arr[i]);
    }
}

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void selectionSort(vector<T> arr)
{
    int arrSize = arr.size();
    int minIndex;

    for (int i = 0; i < arrSize - 1; i++) {
        minIndex = i;

        for (int j = i + 1; j < arrSize; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;

        swap(arr[minIndex], arr[i]);
    }
}

#endif