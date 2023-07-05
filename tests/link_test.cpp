#include "qTest/qTest.hpp"
#include "DSA/link/link.hpp"
#include <unordered_map>



TEST(test_link, t1)
{
    dsa::ds::Link<int> link;
    link.push_back(1);
    link.push_back(2);
    link.push_back(3);
    link.push_back(4);
    link.push_back(5);
    ASSERT_TRUE(link.size() == 5);
    link.pop_back();
    ASSERT_TRUE(link.size() == 4);
    ASSERT_TRUE(link.back() == 4);
    link.reverse();
    ASSERT_TRUE(link.back() == 1);

    link.rearrangement();
}
