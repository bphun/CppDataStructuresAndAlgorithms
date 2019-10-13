#ifndef BubbleSort_h
#define BubbleSort_h

#include <vector>

using namespace std;

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void bubbleSort(T arr[], const int& arrSize)
{
    bool swapped = true;

    do {
        swapped = false;
        for (int i = 0; i < arrSize - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void bubbleSort(T* arr[], const int& arrSize)
{
    bool swapped = true;

    do {
        swapped = false;
        for (int i = 0; i < arrSize - 1; i++) {
            if (*arr[i] > *arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void bubbleSort(vector<T> arr)
{
    bool swapped = true;

    do {
        swapped = false;
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

#endif