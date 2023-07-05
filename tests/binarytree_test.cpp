#include "qTest/qTest.hpp"
#include "DSA/binarytree/binarytree.hpp"



TEST(test_binarytree, t1)
{
    std::vector<int> test = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto btree = dsa::ds::bt::build_btree(test.begin(), test.end());
    ASSERT_TRUE(true);

    std::vector<int> test1;
    dsa::ds::bt::inorder_btree<int>(btree, std::back_inserter(test1));
    ASSERT_TRUE(test1.size() == test.size());
    ASSERT_TRUE(test1.front() == test.front());
    ASSERT_TRUE(test1.back() == test.back());
    test1.clear();
    dsa::ds::bt::postorder_btree<int>(btree, std::back_inserter(test1));
    ASSERT_TRUE(test1.size() == test.size());
    ASSERT_TRUE(test1.front() == 1);
    ASSERT_TRUE(test1.back() == 5);
    test1.clear();
    dsa::ds::bt::preorder_btree<int>(btree, std::back_inserter(test1));
    ASSERT_TRUE(test1.size() == test.size());
    ASSERT_TRUE(test1.front() == 5);
    ASSERT_TRUE(test1.back() == 9);
}
