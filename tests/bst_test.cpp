#include "qTest/qTest.hpp"
#include "DSA/bst/bst.hpp"

TEST(test_bst, t1)
{
    int arr[] = {4, 2, 1, 7, 3, 8, 6};
    dsa::ds::bst::bst_node *root = NULL;

    const auto comp_less = [](const dsa::ds::bst::NodeKeyType &lhs, const dsa::ds::bst::NodeKeyType &rhs) -> short {
        if (lhs == rhs)
            return 0;
        else if (std::less<dsa::ds::bst::NodeKeyType>()(lhs, rhs))
            return -1;
        else
            return 1;
    };

    const auto comp_greater = [](const dsa::ds::bst::NodeKeyType &lhs, const dsa::ds::bst::NodeKeyType &rhs) -> short {
        if (lhs == rhs)
            return 0;
        else if (std::greater<dsa::ds::bst::NodeKeyType>()(lhs, rhs))
            return -1;
        else
            return 1;
    };

#define build_bst(root, fnComp)\
{\
    dsa::ds::bst::insert_r(&root, arr[0], fnComp);\
    for (size_t i = 1; i < (sizeof(arr) / sizeof(arr[0])); ++i)\
    {\
        dsa::ds::bst::insert_r(&root, arr[i], fnComp);\
    }\
}

    // 构建 左 < 根 < 右 的二叉搜索树
    build_bst(root,comp_less);
    std::vector<dsa::ds::bst::NodeKeyType> result;
    // 递归中序遍历
    in_order_traversal(root, result);
    EXPECT_TRUE(result == std::vector<dsa::ds::bst::NodeKeyType>({1, 2, 3, 4, 6, 7, 8})) << "中序遍历";

    // BFS
    result.clear();
    dsa::ds::bst::bfs(root, result);
    EXPECT_TRUE(result == std::vector<dsa::ds::bst::NodeKeyType>({4, 2, 7, 1, 3, 6, 8}))<< "宽度优先搜素";
    
    // 查找
    dsa::ds::bst::bst_node* p_find = nullptr;
    dsa::ds::bst::find(&p_find, root, 7, comp_less);
    EXPECT_TRUE(p_find->Key == 7) <<"查找为7";
    EXPECT_TRUE(p_find->left_child->Key == 6)<< "左子树为7";

    // 删除节点
    dsa::ds::bst::remove_at(root, 2, comp_less);
    dsa::ds::bst::find_r(&p_find, root, 2, comp_less);
    EXPECT_TRUE(p_find == NULL)<<"检测删除情况";

    // free
    dsa::ds::bst::free(root);

    // 构建 左 > 根 > 右 的二叉搜索树
    root = NULL;
    build_bst(root,comp_greater);
    result.clear();
    // 递归中序遍历
    in_order_traversal(root, result);
    EXPECT_TRUE(result == std::vector<dsa::ds::bst::NodeKeyType>({8, 7, 6, 4, 3, 2, 1}))<< "中序遍历";

    // BFS
    result.clear();
    dsa::ds::bst::bfs(root, result);
    EXPECT_TRUE(result == std::vector<dsa::ds::bst::NodeKeyType>({4,7, 2, 8, 6, 3, 1}))<<"宽度优先搜素";

    // free
    dsa::ds::bst::free_r(root);
}