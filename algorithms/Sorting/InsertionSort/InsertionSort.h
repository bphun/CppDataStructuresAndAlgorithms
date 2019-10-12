#ifndef InsertionSort_h
#define InsertionSort_h

#include <vector>

using namespace std;

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void insertionSort(T arr[], const int& arrSize)
{
    T key;
    int j;

    for (int i = 1; i < arrSize; i++) {
        key = arr[i];
        j = i;

        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void insertionSort(T* arr[], const int& arrSize)
{
    T key;
    int j;

    for (int i = 1; i < arrSize; i++) {
        key = *arr[i];
        j = i;

        while (j > 0 && *arr[j - 1] > key) {
            *arr[j] = *arr[j - 1];
            j--;
        }
        *arr[j] = key;
    }
}

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void insertionSort(vector<T> arr)
{
    T key;
    int j;

    for (int i = 1; i < arr.size(); i++) {
        key = arr[i];
        j = i;

        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

#endif