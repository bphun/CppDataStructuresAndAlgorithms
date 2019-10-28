#include "gtest/gtest.h"
#include "ShellSortTestHarness.h"

int main(int argc, char** argv)
{
    srand(time(nullptr));

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}