#include "../PowerSet.h"
#include "gtest/gtest.h"

#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(PowerSet, test)
{
    vector<int> set = { 1, 2, 3 };
    vector<vector<int>> result;
    vector<vector<int>> expectedResult = {
        {},
        { 1 },
        { 1, 2 },
        { 1, 3 },
        { 2 },
        { 2, 3 },
        { 3 },
        { 1, 2, 3 }
    };

    powerSet(set, result);

    for (int i = 0; i < expectedResult.size(); i++)
        EXPECT_TRUE(find(result.begin(), result.end(), expectedResult[i]) != result.end());
}