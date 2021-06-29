#include "qTest/qTest.hpp"
#include "DSA/binarysearch/binarysearch.hpp"

TEST(test_binary_search, t1)
{
    int test[5] = {1, 2, 3, 4, 5};
    ASSERT_TRUE(dsa::alg::search::binary_search(test, 5, 2) == 1);
    ASSERT_TRUE(dsa::alg::search::binary_search(test, 5, 8) == -1);
}
