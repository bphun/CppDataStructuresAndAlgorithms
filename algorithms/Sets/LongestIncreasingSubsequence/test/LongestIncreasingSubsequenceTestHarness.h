#ifndef LongestIncreasingSubsequenceTestHarness_h
#define LongestIncreasingSubsequenceTestHarness_h

#include "../LongestIncreasingSubsequence.h"
#include "gtest/gtest.h"

#include <vector>

using namespace std;

TEST(LongestIncreasingSubsequence, test)
{
    vector<int> arr = { 1, 2, 3 };

    EXPECT_EQ(longestIncreasingSubsequence(arr), 3);

    vector<int> arr1 = { 1, 2, 3, 0, 4, 5, 6, 7, 8, 9 };
    EXPECT_EQ(longestIncreasingSubsequence(arr1), 7);

    vector<int> arr2 = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    EXPECT_EQ(longestIncreasingSubsequence(arr2), 1);

    vector<int> arr3 = { 3, 4, -1, 0, 6, 2, 3 };
    EXPECT_EQ(longestIncreasingSubsequence(arr3), 3);
}

#endif