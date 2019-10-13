#ifndef CountingSort_h
#define CountingSort_h

#include <vector>
#include <map>

using namespace std;

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void countingSort(T arr[], const int& arrSize)
{
    map<T, int> counts;

    for (int i = 0; i < arrSize; i++)
        counts[arr[i]]++;

    int i = 0;
    for (auto it = counts.begin(); it != counts.end(); it++)
        arr[i++] = it->second;
}

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void countingSort(T* arr[], const int& arrSize)
{
    map<T, int> counts;

    for (int i = 0; i < arrSize; i++)
        counts[*arr[i]]++;

    int i = 0;
    for (auto it = counts.begin(); it != counts.end(); it++) {
        *arr[i++] = it->second;
    }
}

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
void countingSort(vector<T> arr)
{
    map<T, int> counts;

    for (int i = 0; i < arr.size(); i++) 
        counts[arr[i]]++;

    int i = 0;
    for (auto it = counts.begin(); it != counts.end(); it++)
        arr[i++] = it->second;
}

#endif