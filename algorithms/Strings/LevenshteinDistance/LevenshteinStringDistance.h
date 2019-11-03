#ifndef LevenshteinStringDistance_h
#define LevenshteinStringDistance_h

#include <iostream>
#include <string>
using namespace std;

int levenshteinStringDistance(const string& strA, const string& strB)
{
    int strALength = strA.length();
    int strBLength = strB.length();

    int** differenceMatrix = new int*[strBLength + 1];
    
    for (int i = 0; i <= strBLength; i++) 
        differenceMatrix[i] = new int[strALength + 1];

    for (int i = 0; i <= strALength; i++)
        differenceMatrix[0][i] = i;

    for (int j = 0; j <= strBLength; j++)
        differenceMatrix[j][0] = j;

    for (int j = 1; j <= strBLength; j++) {
        for (int i = 1; i <= strALength; i++) {
            int value = strA[i - 1] == strB[j - 1] ? 0 : 1;
            differenceMatrix[j][i] = min(
                min(
                    differenceMatrix[j][i - 1] + 1,
                    differenceMatrix[j - 1][i] + 1),
                differenceMatrix[j - 1][i - 1] + value);
        }
    }

    return differenceMatrix[strBLength][strALength];
}

#endif