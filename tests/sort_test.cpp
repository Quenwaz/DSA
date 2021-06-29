#include "qTest/qTest.hpp"
#include "DSA/sort/sort.hpp"

TEST(test_sort, t1)
{
#define TEST_SORT(sort_name)                                                         \
    {                                                                                \                                            
        std::vector<int> vecTest = {9, 0, 5, 1, 2, 3, 8, 41, 32, 113, 4, 8};         \
        std::vector<int> vecTest1 = {5, 4, 3, 2, 1};                                 \
        dsa::alg::sort::sort_name(vecTest.begin(), vecTest.end());                             \
        dsa::alg::sort::sort_name(vecTest1.begin(), vecTest1.end());                           \
        ASSERT_TRUE(vecTest == std::vector<int>({0, 1, 2, 3, 4, 5, 8, 8, 9, 32, 41, 113})); \
        ASSERT_TRUE(vecTest != std::vector<int>({1, 1, 2, 3, 4, 5, 8, 8, 9, 32, 41, 113})); \
        ASSERT_TRUE(vecTest1 == std::vector<int>({1, 2, 3, 4, 5}));                         \
    }

    TEST_SORT(insert_sort);
    TEST_SORT(bubble_sort);
    TEST_SORT(quick_sort);

#undef TEST_SORT
}
