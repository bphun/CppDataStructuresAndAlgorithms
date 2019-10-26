#include "../HammingDistance.h"
#include "gtest/gtest.h"

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(HammingDistance, SameStrings)
{
    string strA = "abcd";

    EXPECT_EQ(hammingDistance(strA, strA), 0);
}

TEST(HammingDistance, DifferentLengthStrings)
{
    string strA = "page";
    string strB = "pages";

    EXPECT_EQ(hammingDistance(strA, strB), -1);
}

TEST(HammingDistance, DifferentStrings)
{
    string strA = "karolin";
    string strB = "kathrin";

    EXPECT_EQ(hammingDistance(strA, strB), 3);
}