#ifndef LongestIncreasingSubsequence_h
#define LongestIncreasingSubsequence_h

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
int longestIncreasingSubsequence(vector<T> arr)
{
    int longestIncSubseq = 1;
    int currLongestIncSubseq = 1;
    T prev = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > prev)
            currLongestIncSubseq++;
        else
            currLongestIncSubseq = 1;

        longestIncSubseq = max(currLongestIncSubseq, longestIncSubseq);
        prev = arr[i];
    }
    
    return longestIncSubseq;
}

#endif