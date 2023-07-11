#include "qTest/qTest.hpp"
#include "DSA/link/single_linked_list.hpp"
#include <unordered_map>



TEST(test_single_linked_list, push_back)
{
    dsa::ds::Link<int> link;
    link.insert(0,9);
    ASSERT_TRUE(link[0]->data == 9);
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
    ASSERT_TRUE(link[5]->data == 4);
    ASSERT_TRUE(link.size() == 7);
}


TEST(test_single_linked_list, pop_back)
{
    dsa::ds::Link<int> link;
    ASSERT_TRUE(link.size() == 0);
    ASSERT_TRUE(link.empty());
    link.push_back(2);
    ASSERT_TRUE(link.size() == 1);
    ASSERT_TRUE(link.back() == 2);
    link.push_back(6);
    ASSERT_TRUE(link.back() == 6);
    link.push_back(1);
    ASSERT_TRUE(link.back() == 1);
    ASSERT_TRUE(link.size() == 3);
}


TEST(test_single_linked_list, insert)
{
    dsa::ds::Link<int> link;
    ASSERT_TRUE(link.empty());
    link.insert(0, 8);
    ASSERT_EQ(link.back(), 8);
    ASSERT_EQ(link.front(), 8);
    link.insert(1, 9);
    ASSERT_EQ(link.front(), 8);
    ASSERT_EQ(link.back(), 9);
    link.insert(0, 0);
    ASSERT_EQ(link.front(), 0);
    link.insert(3, -1);
    ASSERT_EQ(link.back(), -1);
    ASSERT_EQ(link.size(), 4);
}


TEST(test_single_linked_list, remove)
{
    dsa::ds::Link<int> link;
    auto node_0 = link[0];
    ASSERT_EQ(node_0, nullptr);
    link.push_back(1);
    node_0 = link[0];
    ASSERT_EQ(node_0->data, 1);
    link.remove(node_0);
    ASSERT_EQ(link.size(), 0);
    link.push_back(9);
}


TEST(test_single_linked_list, reverse)
{
    dsa::ds::Link<int> link;
    for(size_t i  = 0; i < 10; ++i)
        link.push_back(i + 1);

    link.reverse();
    for(size_t i  = 0; i < 10; ++i){
        ASSERT_TRUE(link.back()==(i+1));
        link.pop_back();
    }
}

TEST(test_single_linked_list, rearrangement)
{
    dsa::ds::Link<int> link;
    for(size_t i  = 0; i < 10; ++i)
        link.push_back(i + 1);

    link.rearrangement();
    
    ASSERT_EQ(link[0]->data, 1);
    ASSERT_EQ(link[1]->data, 3);
    ASSERT_EQ(link[2]->data, 5);
    ASSERT_EQ(link[3]->data, 7);
    ASSERT_EQ(link[4]->data, 9);
    ASSERT_EQ(link[5]->data, 2);
    ASSERT_EQ(link[6]->data, 4);
    ASSERT_EQ(link[7]->data, 6);
    ASSERT_EQ(link[8]->data, 8);
    ASSERT_EQ(link[9]->data, 10);
}
