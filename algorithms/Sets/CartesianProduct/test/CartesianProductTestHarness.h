#ifndef CartesianProductTestHarness_h
#define CartesianProductTestHarness_h

#include "../CartesianProduct.h"
 
#include <iostream>

using namespace std;

TEST(CartesianProduct, test)
{
    vector<int> arrA = { 1, 2, 3, 4, 5 };
    vector<int> arrB = { 5, 4, 3, 2, 1 };
    vector<vector<int>> result;

    cartesianProduct(arrA, arrB, result);

    int n = 0;
    for (int i = 0; i < arrA.size(); i++) {
        for (int j = 0; j < arrB.size(); j++) {
            EXPECT_EQ(result[n][0], arrA[i]);
            EXPECT_EQ(result[n][1], arrB[j]);
            n++;
        }
    }
}

#endif