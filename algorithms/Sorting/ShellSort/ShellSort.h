#ifndef ShellSort_h
#define ShellSort_h

#include <vector>

using namespace std;

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void shellSort(T arr[], const int& arrSize)
{
    int interval = 0;

    while (interval < arrSize / 3)
        interval = interval * 3 + 1;

    while (interval > 0) {
        for (int outer = interval; outer < arrSize; outer++) {
            T val = arr[outer];
            int inner = outer;

            while (inner > interval - 1 && arr[inner - interval] >= val) {
                arr[inner] = arr[inner - interval];
                inner -= interval;
            }

            arr[inner] = val;
        }

        interval = (interval - 1) / 3;
    }
}

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void shellSort(T* arr[], const int& arrSize)
{
    int interval = 0;

    while (interval < arrSize / 3)
        interval = interval * 3 + 1;

    while (interval > 0) {
        for (int outer = interval; outer < arrSize; outer++) {
            T val = *arr[outer];
            int inner = outer;

            while (inner > interval - 1 && *arr[inner - interval] >= val) {
                *arr[inner] = *arr[inner - interval];
                inner -= interval;
            }

            *arr[inner] = val;
        }

        interval = (interval - 1) / 3;
    }
}

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void shellSort(vector<T> arr)
{
    int interval = 0;

    while (interval < arr.size() / 3)
        interval = interval * 3 + 1;

    while (interval > 0) {
        for (int outer = interval; outer < arr.size(); outer++) {
            T val = arr[outer];
            int inner = outer;

            while (inner > interval - 1 && arr[inner - interval] >= val) {
                arr[inner] = arr[inner - interval];
                inner -= interval;
            }

            arr[inner] = val;
        }

        interval = (interval - 1) / 3;
    }
}

#endif