#include "qTest/qTest.hpp"
#include "DSA/link/circular_linked_list.hpp"
#include <unordered_map>



TEST(test_circular_linked_list, push_back)
{
    dsa::ds::CircledList<int> link;
    link.push(1);
    link.push(2);
    ASSERT_EQ(link.top()->data, 1);
    link.push(3);
    ASSERT_EQ(link.top()->data, 1);
    ASSERT_TRUE(link.size() == 3);
    link.pop();
    ASSERT_EQ(link.top()->data, 2);
    ASSERT_TRUE(link.size() == 2);
    link.pop();
    ASSERT_EQ(link.top()->data, 3);
    ASSERT_TRUE(link.size() == 1);
    link.pop();
    ASSERT_TRUE(link.size() == 0);
    ASSERT_EQ(link.top(), nullptr);
}