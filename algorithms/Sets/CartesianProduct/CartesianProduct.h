#ifndef CartesianProduct_h
#define CartesianProduct_h

#include <vector>
#include <iostream>
using namespace std;

template <typename T>
void cartesianProduct(const vector<T>& arrA, const vector<T>& arrB, vector<vector<T>>& result)
{

    for (int i = 0; i < arrA.size(); i++) {
        vector<T> cartesianPair(2);
        for (int j = 0; j < arrB.size(); j++) {
            cartesianPair = { arrA[i], arrB[j] };
            result.push_back(cartesianPair);
        }
    }
}

#endif