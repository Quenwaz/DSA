#include "qTest/qTest.hpp"
#include "DSA/link/single_linked_list.hpp"
#include <unordered_map>



TEST(test_single_linked_list, t1)
{
    dsa::ds::Link<int> link;
    link.insert(0,9);
    ASSERT_EQ(link.front(), 9);
    ASSERT_EQ(link.back(), 9);
    link.push_back(1);
    ASSERT_EQ(link.front(), 9);
    ASSERT_EQ(link.back(), 1);
    link.push_back(2);
    link.insert(3,11);
    ASSERT_EQ(link.back(), 11);
    link.push_back(3);
    link.push_back(4);
    link.push_back(5);
    ASSERT_TRUE(link.size() == 7);
    link.pop_back();
    ASSERT_TRUE(link.size() == 6);
    ASSERT_TRUE(link.back() == 4);
    link.reverse();
    ASSERT_TRUE(link.back() == 9);

    link.rearrangement();
}
