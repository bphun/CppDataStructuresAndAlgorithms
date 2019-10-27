#ifndef KnuthMorrisPrattAlgorithm_h
#define KnuthMorrisPrattAlgorithm_h

#include <string>

using namespace std;

void generatePatternTable(const string& str, int patternTable[])
{
    int prefixIndex = 0;
    int suffixIndex = 1;

    while (suffixIndex < str.size()) {
        if (str[prefixIndex] == str[suffixIndex]) {
            patternTable[suffixIndex] = prefixIndex + 1;

            prefixIndex++;
            suffixIndex++;
        } else if (prefixIndex == 0) {
            patternTable[suffixIndex] = 0;

            suffixIndex++;
        } else {
            prefixIndex = patternTable[prefixIndex - 1];
        }
    }
}

int knuthMorrisPratt(const string& str, const string& patternString)
{
    if (str.size() == 0)
        return 0;

    int strIndex = 0;
    int patternStringIndex = 0;
    int patternTable[str.size() - 1];

    generatePatternTable(str, patternTable);

    while (strIndex < str.size()) {
        if (str[strIndex] == patternString[patternStringIndex]) {
            if (patternStringIndex == patternString.size() - 1)
                return (strIndex - patternString.size()) + 1;

            strIndex++;
            patternStringIndex++;
        } else if (patternStringIndex > 0) {
            patternStringIndex = patternTable[patternStringIndex - 1];
        } else {
            strIndex++;
            patternStringIndex = 0;
        }
    }

    return -1;
}

#endif