#ifndef InterpolationSearchTestHarness_h
#define InterpolationSearchTestHarness_h

#include "../InterpolationSearch.h"

#define ARRAY_SIZE 1000

TEST(InterpolationSearch, Array_SearchValIsMemberOfArray)
{
    int array[ARRAY_SIZE];
    int randIndex = rand() % ARRAY_SIZE;

    for (size_t i = 0; i < ARRAY_SIZE; i++)
        array[i] = i;

    EXPECT_TRUE(interpolationSearch(array, array[randIndex], ARRAY_SIZE));
}

TEST(InterpolationSearch, Array_SearchValIsNotMemberOfArray)
{
    int array[ARRAY_SIZE];
    int searchVal = ARRAY_SIZE + 1;

    for (size_t i = 0; i < ARRAY_SIZE; i++)
        array[i] = i;

    EXPECT_FALSE(interpolationSearch(array, searchVal, ARRAY_SIZE));
}

TEST(InterpolationSearch, PointerArray_SearchValIsMemberOfArray)
{
    int* array[ARRAY_SIZE] = { nullptr };
    int randIndex = rand() % ARRAY_SIZE;

    for (size_t i = 0; i < ARRAY_SIZE; i++)
        array[i] = new int(i);

    EXPECT_TRUE(interpolationSearch(array, array[randIndex], ARRAY_SIZE));
}

TEST(InterpolationSearch, PointerArray_SearchValIsNotMemberOfArray)
{
    int* array[ARRAY_SIZE] = { nullptr };
    int searchVal = ARRAY_SIZE + 1;

    for (size_t i = 0; i < ARRAY_SIZE; i++)
        array[i] = new int(i);

    EXPECT_FALSE(interpolationSearch(array, searchVal, ARRAY_SIZE));
}

TEST(InterpolationSearch, Vector_SearchValIsMemberOfArray)
{
    vector<int> array(ARRAY_SIZE);
    int randIndex = rand() % ARRAY_SIZE;

    for (size_t i = 0; i < ARRAY_SIZE; i++)
        array[i] = i;

    EXPECT_TRUE(interpolationSearch(array, array[randIndex]));
}

TEST(InterpolationSearch, Vector_SearchValIsNotMemberOfArray)
{
    vector<int> array(ARRAY_SIZE);
    int searchVal = ARRAY_SIZE + 1;

    for (size_t i = 0; i < ARRAY_SIZE; i++)
        array[i] = i;

    EXPECT_FALSE(interpolationSearch(array, searchVal));
}

#endif