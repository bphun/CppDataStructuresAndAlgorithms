#include "gtest/gtest.h"
#include "../LinearSearch.h"

#define ARRAY_SIZE 1000

int main(int argc, char **argv)
{
    srand(time(nullptr));

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(LinearSearch, Array_SearchValIsMemberOfArray)
{
    int array[ARRAY_SIZE];
    int randIndex = rand() % ARRAY_SIZE;
    int searchVal = rand() % (2 * ARRAY_SIZE);

    for (size_t i = 0; i < ARRAY_SIZE - 1; i++)
    {
        if (i == randIndex)
            array[i] = searchVal;
        else
            array[i] = i;
    }

    EXPECT_TRUE(linearSearch(array, searchVal, ARRAY_SIZE));
}

TEST(LinearSearch, Array_SearchValIsNotMemberOfArray)
{
    int array[ARRAY_SIZE];
    int searchVal = ARRAY_SIZE + 1;

    for (size_t i = 0; i < ARRAY_SIZE; i++)
        array[i] = i;

    EXPECT_FALSE(linearSearch(array, searchVal, ARRAY_SIZE));
}

TEST(LinearSearch, PointerArray_SearchValIsMemberOfArray)
{
    int *array[ARRAY_SIZE] = {nullptr};
    int randIndex = rand() % ARRAY_SIZE;
    int searchVal = rand() % (2 * ARRAY_SIZE);

    for (size_t i = 0; i < ARRAY_SIZE - 1; i++)
    {
        if (i == randIndex)
            array[i] = new int(searchVal);
        else
            array[i] = new int(i);
    }

    EXPECT_TRUE(linearSearch(array, searchVal, ARRAY_SIZE));
}

TEST(LinearSearch, PointerArray_SearchValIsNotMemberOfArray)
{
    int *array[ARRAY_SIZE] = {nullptr};
    int searchVal = ARRAY_SIZE + 1;

    for (size_t i = 0; i < ARRAY_SIZE; i++)
        array[i] = new int(i);

    EXPECT_FALSE(linearSearch(array, searchVal, ARRAY_SIZE));
}

TEST(LinearSearch, Vector_SearchValIsMemberOfArray)
{
    vector<int> array(ARRAY_SIZE);
    int randIndex = rand() % ARRAY_SIZE;
    int searchVal = rand() % (2 * ARRAY_SIZE);

    for (size_t i = 0; i < ARRAY_SIZE - 1; i++)
    {
        if (i == randIndex)
            array[i] = searchVal;
        else
            array[i] = i;
    }

    EXPECT_TRUE(linearSearch(array, searchVal));
}

TEST(LinearSearch, Vector_SearchValIsNotMemberOfArray)
{
    vector<int> array(ARRAY_SIZE);
    int searchVal = ARRAY_SIZE + 1;

    for (size_t i = 0; i < ARRAY_SIZE; i++)
        array[i] = i;

    EXPECT_FALSE(linearSearch(array, searchVal));
}