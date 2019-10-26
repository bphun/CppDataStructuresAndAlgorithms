#ifndef HammingDistance_h
#define HammingDistance_h

#include <string>

using namespace std;

int hammingDistance(const string& strA, const string& strB)
{
    int distance = 0;

    if (strA.length() != strB.size())
        return -1;

    for (int i = 0; i < strA.length(); i++)
        if (strA[i] != strB[i])
            distance++;

    return distance;
}

#endif