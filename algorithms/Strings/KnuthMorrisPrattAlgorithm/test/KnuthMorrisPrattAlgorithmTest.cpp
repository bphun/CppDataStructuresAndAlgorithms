#include "../KnuthMorrisPrattAlgorithm.h"
#include "gtest/gtest.h"

#include <string>

using namespace std;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(KnuthMorrisPratt, test) {
    string str = "abcdefg";
    string pattern = "abc";

    EXPECT_EQ(knuthMorrisPratt(str, pattern), 0);

    str = "computer";
    pattern = "omp";

    EXPECT_EQ(knuthMorrisPratt(str, pattern), 1);

    str = "abcxabcdabxabcdabcdabcy";
    pattern = "abcdabcacc";

    EXPECT_EQ(knuthMorrisPratt(str, pattern), -1);
}