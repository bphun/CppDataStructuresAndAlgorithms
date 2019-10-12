#include "../BinarySearch.h"
#include "gtest/gtest.h"

#define ARRAY_SIZE 1000

int main(int argc, char** argv)
{
    srand(time(nullptr));
    cout << "sup" << endl
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(BinarySearch, Array_SearchValIsMemberOfArray)
{
    int array[ARRAY_SIZE];
    int randIndex = rand() % ARRAY_SIZE;

    for (size_t i = 0; i < ARRAY_SIZE - 1; i++)
        array[i] = i;

    EXPECT_TRUE(binarySearch(array, array[randIndex], ARRAY_SIZE));
}

TEST(BinarySearch, Array_SearchValIsNotMemberOfArray)
{
    int array[ARRAY_SIZE];
    int searchVal = ARRAY_SIZE + 1;

    for (size_t i = 0; i < ARRAY_SIZE; i++)
        array[i] = i;

    EXPECT_FALSE(binarySearch(array, searchVal, ARRAY_SIZE));
}

TEST(BinarySearch, PointerArray_SearchValIsMemberOfArray)
{
    int* array[ARRAY_SIZE] = { nullptr };
    int randIndex = rand() % ARRAY_SIZE;

    for (size_t i = 0; i < ARRAY_SIZE - 1; i++)
        array[i] = new int(i);

    EXPECT_TRUE(binarySearch(array, array[randIndex], ARRAY_SIZE));
}

TEST(BinarySearch, PointerArray_SearchValIsNotMemberOfArray)
{
    int* array[ARRAY_SIZE] = { nullptr };
    int searchVal = ARRAY_SIZE + 1;

    for (size_t i = 0; i < ARRAY_SIZE; i++)
        array[i] = new int(i);

    EXPECT_FALSE(binarySearch(array, searchVal, ARRAY_SIZE));
}

TEST(BinarySearch, Vector_SearchValIsMemberOfArray)
{
    vector<int> array(ARRAY_SIZE);
    int randIndex = rand() % ARRAY_SIZE;

    for (size_t i = 0; i < ARRAY_SIZE - 1; i++)
        array[i] = i;

    EXPECT_TRUE(binarySearch(array, array[randIndex]));
}

TEST(BinarySearch, Vector_SearchValIsNotMemberOfArray)
{
    vector<int> array(ARRAY_SIZE);
    int searchVal = ARRAY_SIZE + 1;

    for (size_t i = 0; i < ARRAY_SIZE; i++)
        array[i] = i;

    EXPECT_FALSE(binarySearch(array, searchVal));
}