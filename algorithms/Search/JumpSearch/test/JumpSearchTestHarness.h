#ifndef JumpSearchTestHarness_h
#define JumpSearchTestHarness_h

#include "../JumpSearch.h"

#define ARRAY_SIZE 1000

TEST(JumpSearch, Array_SearchValIsMemberOfArray)
{
    int array[ARRAY_SIZE];
    int randIndex = rand() % ARRAY_SIZE;

    for (size_t i = 0; i < ARRAY_SIZE - 1; i++)
        array[i] = i;

    EXPECT_TRUE(jumpSearch(array, array[randIndex], ARRAY_SIZE));
}

TEST(JumpSearch, Array_SearchValIsNotMemberOfArray)
{
    int array[ARRAY_SIZE];
    int searchVal = ARRAY_SIZE + 1;

    for (size_t i = 0; i < ARRAY_SIZE; i++)
        array[i] = i;

    EXPECT_FALSE(jumpSearch(array, searchVal, ARRAY_SIZE));
}

TEST(JumpSearch, PointerArray_SearchValIsMemberOfArray)
{
    int* array[ARRAY_SIZE] = { nullptr };
    int randIndex = rand() % ARRAY_SIZE;

    for (size_t i = 0; i < ARRAY_SIZE - 1; i++)
        array[i] = new int(i);

    EXPECT_TRUE(jumpSearch(array, array[randIndex], ARRAY_SIZE));
}

TEST(JumpSearch, PointerArray_SearchValIsNotMemberOfArray)
{
    int* array[ARRAY_SIZE] = { nullptr };
    int searchVal = ARRAY_SIZE + 1;

    for (size_t i = 0; i < ARRAY_SIZE; i++)
        array[i] = new int(i);

    EXPECT_FALSE(jumpSearch(array, searchVal, ARRAY_SIZE));
}

TEST(JumpSearch, Vector_SearchValIsMemberOfArray)
{
    vector<int> array(ARRAY_SIZE);
    int randIndex = rand() % ARRAY_SIZE;

    for (size_t i = 0; i < ARRAY_SIZE - 1; i++)
        array[i] = i;

    EXPECT_TRUE(jumpSearch(array, array[randIndex]));
}

TEST(JumpSearch, Vector_SearchValIsNotMemberOfArray)
{
    vector<int> array(ARRAY_SIZE);
    int searchVal = ARRAY_SIZE + 1;

    for (size_t i = 0; i < ARRAY_SIZE; i++)
        array[i] = i;

    EXPECT_FALSE(jumpSearch(array, searchVal));
}

#endif