#ifndef __binary_tree_tree_included_
#define __binary_tree_tree_included_
#include <queue>
#include <stack>
#include <cstdio>
#include <algorithm>



namespace dsa{
namespace ds{
namespace bt{
/**
 一个二叉树至少具备如下接口:
 - 构建
    - 逐个构建
    - 整体构建
 - 删除节点
 - 查找节点
 - 遍历节点
    - 前中后序遍历
 */

template <typename T>
struct Node{
    Node* parent;
    Node* left_child;
    Node* right_child;
    T value;
};




}}}


#endif // __binary_tree_tree_included_