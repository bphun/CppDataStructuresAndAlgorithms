#ifndef KnuthMorrisPrattAlgorithmTestRunner_h
#define KnuthMorrisPrattAlgorithmTestRunner_h

#include "../KnuthMorrisPrattAlgorithm.h" 

#include <string>

using namespace std;

TEST(KnuthMorrisPratt, test)
{
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

#endif