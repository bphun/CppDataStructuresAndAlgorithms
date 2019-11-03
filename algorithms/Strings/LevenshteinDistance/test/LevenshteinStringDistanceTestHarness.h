#ifndef LevenshteinStringDistanceTestHarness_h¸
#define LevenshteinStringDistanceTestHarness_h¸

#include "../LevenshteinStringDistance.h"
#include "gtest/gtest.h"

#include <iostream>
#include <string>

using namespace std;

TEST(LevenshteinStringDistance, test)
{
    EXPECT_EQ(levenshteinStringDistance("", ""), 0);
    EXPECT_EQ(levenshteinStringDistance("a", ""), 1);
    EXPECT_EQ(levenshteinStringDistance("", "a"), 1);
    EXPECT_EQ(levenshteinStringDistance("abc", ""), 3);
    EXPECT_EQ(levenshteinStringDistance("", "abc"), 3);
    EXPECT_EQ(levenshteinStringDistance("islander", "slander"), 1);
    EXPECT_EQ(levenshteinStringDistance("mart", "karma"), 3);
    EXPECT_EQ(levenshteinStringDistance("kitten", "sitting"), 3);
    EXPECT_EQ(levenshteinStringDistance("ball", "football"), 4);
    EXPECT_EQ(levenshteinStringDistance("football", "foot"), 4);
    EXPECT_EQ(levenshteinStringDistance("intention", "execution"), 5);
}

#endif