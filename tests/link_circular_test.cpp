#include "qTest/qTest.hpp"
#include "DSA/link/circular_linked_list.hpp"
#include <unordered_map>



TEST(test_circular_linked_list, routine_operation)
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


TEST(test_circular_linked_list, limited_capacity)
{
    dsa::ds::CircledList<int> link_5(5);
    ASSERT_TRUE(link_5.empty());
    ASSERT_FALSE(link_5.isfull());
    link_5.push(3);
    ASSERT_FALSE(link_5.empty());
    ASSERT_FALSE(link_5.isfull());
    link_5.push(1);
    link_5.push(2);
    link_5.push(5);
    link_5.push(4);
    ASSERT_TRUE(link_5.isfull());
    ASSERT_TRUE(link_5.size() == 5);

}