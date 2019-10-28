#ifndef HammingDistanceTestHarness_h
#define HammingDistanceTestHarness_h

#include "../HammingDistance.h" 

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

#endif