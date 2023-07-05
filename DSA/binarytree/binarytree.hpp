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
struct TreeNode{
   //  Node* parent;
    TreeNode* left_child;
    TreeNode* right_child;
    T value;
    explicit TreeNode(const T& v):value(v), left_child(nullptr), right_child(nullptr){}
};

template <typename ForwardIter>
TreeNode<typename ForwardIter::value_type>* build_btree(ForwardIter beg, ForwardIter end)
{
   if (std::distance(beg, end) < 1){
      return nullptr;
   }

   struct RangePair{
      ForwardIter l;
      ForwardIter r;
      TreeNode<typename ForwardIter::value_type>* node;
      enum Type{
         root,
         left,
         right
      }type;
      RangePair(const ForwardIter& _l, const ForwardIter& _r, Type t, 
               TreeNode<typename ForwardIter::value_type>* n = nullptr)
      : l(_l), r(_r),type(t),node(n){}
   };

   TreeNode<typename ForwardIter::value_type>* root = nullptr;
   TreeNode<typename ForwardIter::value_type>* cur_node = nullptr;
   std::stack<RangePair> st_iter;
   st_iter.push({beg, end, RangePair::root});

   for (;!st_iter.empty();)
   {
      RangePair range = st_iter.top();
      st_iter.pop();
      const auto size_range  = std::distance(range.l, range.r);
      if (size_range < 1){
         continue;
      }
      ForwardIter middle = range.l + size_range/ 2;
      if (*middle == 0)
      {
         int debug = 0;
      }

      auto node = new TreeNode<typename ForwardIter::value_type>(*middle);
      if (range.type == RangePair::root){
         root = node;
      }else if (range.type == RangePair::left){
         range.node->left_child = node;
      }else{
         range.node->right_child = node;
      }
      st_iter.push({range.l, middle, RangePair::left, node});
      st_iter.push({middle+ 1, range.r, RangePair::right, node});
   }

   return root;
}


template <typename ValueType,typename ForwardIter>
void inorder_btree(TreeNode<ValueType>* tree, ForwardIter beg)
{
   struct Node{
      TreeNode<ValueType>* v;
      bool flag = false;
   };

   std::stack<Node> st_val;
   st_val.push({tree});
   for(;!st_val.empty();)
   {
      auto &node = st_val.top();
      if ((!node.flag) && node.v->left_child != nullptr)
      {
         node.flag = true;
         st_val.push({node.v->left_child});
      }else{
         *beg++ = std::move(node.v->value);
         st_val.pop();
         if (node.v->right_child != nullptr){
            st_val.push({node.v->right_child});
         }
      }
   }
}



template <typename ValueType,typename ForwardIter>
void preorder_btree(TreeNode<ValueType>* tree, ForwardIter beg)
{

   std::stack<TreeNode<ValueType>* > st_val;
   st_val.push(tree);
   for(;!st_val.empty();)
   {
      auto node = st_val.top();
      st_val.pop();
      *beg++ = std::move(node->value);
      if (node->right_child != nullptr){
         st_val.push(node->right_child);
      }
      
      if (node->left_child != nullptr)
      {
         st_val.push(node->left_child);
      }



   }
}



template <typename ValueType,typename ForwardIter>
void postorder_btree(TreeNode<ValueType>* tree, ForwardIter beg)
{
   struct Node{
      TreeNode<ValueType>* v;
      unsigned short flag = 0;
   };

   std::stack<Node> st_val;
   st_val.push({tree});
   for(;!st_val.empty();)
   {
      auto &node = st_val.top();
      if (node.flag == 0 && node.v->left_child != nullptr)
      {
         node.flag = 1;
         st_val.push({node.v->left_child});
      }else{
         if (node.flag != 2 && node.v->right_child != nullptr){
            node.flag = 2;
            st_val.push({node.v->right_child});
         }else{
            *beg++ = std::move(node.v->value);
            st_val.pop();
         }
      }
   }
}


}
}  // namespace ds
}  // namespace dsa

#endif // __binary_tree_tree_included_