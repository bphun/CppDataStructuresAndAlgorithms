#ifndef PowerSet_h
#define PowerSet_h

#include <math.h>
#include <vector>

using namespace std;

template <typename T>
void powerSet(const vector<T>& arr, vector<vector<T>>& result)
{
    int powersetSize = pow(2, arr.size());
    for (int i = 0; i < powersetSize; i++) {
        vector<T> set;
        for (int j = 0; j < arr.size(); j++) {
            if (i & (1 << j))
                set.push_back(arr[j]);
        }
        result.push_back(set);
    }
}

#endif