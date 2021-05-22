#include <cstdlib>
#include <vector>

#include "common/defs.h"
#include "common/utils.h"
#include "queue/queue_of_circle.hpp"
#include "binarysearch/binarysearch.hpp"
#include "sort/sort.hpp"
#include "bst/bst.hpp"


void test_queue()
{
    PRINNT_TEST_FN();
    data_structure::queue::queue_circle<int, 3> test1;

    TEST(test1.push(1) == true);
    TEST(test1.push(2) == true);
    TEST(test1.push(3) == true);
    TEST(test1.push(4) == false);
    TEST(test1.full() == true);
    TEST(test1.exist(1) == true);
    TEST(test1.exist(-1) == false);
    TEST(test1.front() == 1);
    TEST(test1.pop() == true);
    TEST(test1.pop() == true);
    TEST(test1.pop() == true);
    TEST(test1.pop() == false);
    TEST(test1.empty() == true);
}

void test_binary_search()
{
    PRINNT_TEST_FN();
    int test[5] = {1, 2, 3, 4, 5};
    TEST(search::binary_search(test, 5, 2) == 1);
    TEST(search::binary_search(test, 5, 8) == -1);
}

void test_sort()
{
    PRINNT_TEST_FN();
#define TEST_SORT(sort_name)                                                         \
    {                                                                                \
        PRINNT_TEST_FN_MSG(#sort_name);                                              \
        std::vector<int> vecTest = {9, 0, 5, 1, 2, 3, 8, 41, 32, 113, 4, 8};         \
        std::vector<int> vecTest1 = {5, 4, 3, 2, 1};                                 \
        sort::sort_name(vecTest.begin(), vecTest.end());                             \
        sort::sort_name(vecTest1.begin(), vecTest1.end());                           \
        TEST(vecTest == std::vector<int>({0, 1, 2, 3, 4, 5, 8, 8, 9, 32, 41, 113})); \
        TEST(vecTest != std::vector<int>({1, 1, 2, 3, 4, 5, 8, 8, 9, 32, 41, 113})); \
        TEST(vecTest1 == std::vector<int>({1, 2, 3, 4, 5}));                         \
    }

    TEST_SORT(insert_sort);
    TEST_SORT(bubble_sort);
    TEST_SORT(quick_sort);

#undef TEST_SORT
}

void test_bst()
{
    PRINNT_TEST_FN();

    int arr[] = {4, 2, 1, 7, 3, 8, 6};
    data_structure::bst::bst_node *root = NULL;

    const auto comp_less = [](const data_structure::bst::NodeKeyType &lhs, const data_structure::bst::NodeKeyType &rhs) -> short {
        if (lhs == rhs)
            return 0;
        else if (std::less<data_structure::bst::NodeKeyType>()(lhs, rhs))
            return -1;
        else
            return 1;
    };

    const auto comp_greater = [](const data_structure::bst::NodeKeyType &lhs, const data_structure::bst::NodeKeyType &rhs) -> short {
        if (lhs == rhs)
            return 0;
        else if (std::greater<data_structure::bst::NodeKeyType>()(lhs, rhs))
            return -1;
        else
            return 1;
    };

#define build_bst(root, fnComp)\
{\
    data_structure::bst::insert_r(&root, arr[0], fnComp);\
    for (size_t i = 1; i < (sizeof(arr) / sizeof(arr[0])); ++i)\
    {\
        data_structure::bst::insert_r(&root, arr[i], fnComp);\
    }\
}

    // 构建 左 < 根 < 右 的二叉搜索树
    build_bst(root,comp_less);
    std::vector<data_structure::bst::NodeKeyType> result;
    // 递归中序遍历
    in_order_traversal(root, result);
    TEST1(result == std::vector<data_structure::bst::NodeKeyType>({1, 2, 3, 4, 6, 7, 8}), "中序遍历");

    // BFS
    result.clear();
    data_structure::bst::bfs(root, result);
    TEST1(result == std::vector<data_structure::bst::NodeKeyType>({4, 2, 7, 1, 3, 6, 8}), "宽度优先搜素");
    
    // 查找
    data_structure::bst::bst_node* p_find = nullptr;
    data_structure::bst::find(&p_find, root, 7, comp_less);
    TEST1(p_find->Key == 7, "查找为7");
    TEST1(p_find->left_child->Key == 6, "左子树为7");

    // 删除节点
    data_structure::bst::remove_at(root, 2, comp_less);
    data_structure::bst::find_r(&p_find, root, 2, comp_less);
    TEST1(p_find == NULL, "检测删除情况");

    // free
    data_structure::bst::free(root);

    // 构建 左 > 根 > 右 的二叉搜索树
    root = NULL;
    build_bst(root,comp_greater);
    result.clear();
    // 递归中序遍历
    in_order_traversal(root, result);
    TEST1(result == std::vector<data_structure::bst::NodeKeyType>({8, 7, 6, 4, 3, 2, 1}), "中序遍历");

    // BFS
    result.clear();
    data_structure::bst::bfs(root, result);
    TEST1(result == std::vector<data_structure::bst::NodeKeyType>({4,7, 2, 8, 6, 3, 1}), "宽度优先搜素");

    // free
    data_structure::bst::free_r(root);
}


int main(int argc, char const *argv[])
{
    test_queue();
    test_binary_search();
    test_sort();
    test_bst();
    return 0;
}
