#include "qTest/qTest.hpp"
#include "DSA/vector/vector.hpp"

TEST(test_vector, t1)
{
    dsa::ds::Vector<int> test1(5,3);

    ASSERT_TRUE(test1.size() == 5);
    ASSERT_TRUE(test1[4] == 3);
    test1.push_back(7);
    ASSERT_TRUE(7 == test1[5]);
}