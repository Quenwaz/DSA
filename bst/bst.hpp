#ifndef __binary_search_tree_included_
#define __binary_search_tree_included_

namespace data_structure{
namespace bst
{
    

    typedef int NodeKeyType;

    /**
     * @brief key值比较函数指针
     *  返回值说明: 
     *      - 0 表示相等 
     *      - 小于0 表示左操作符<右操作符
     *      - 大于0 表示左操作符>右操作符 
     */
    typedef short(*KeyComp)(const NodeKeyType& , const NodeKeyType&);
    struct bst_node{
        bst_node* left_child;
        bst_node* right_child;
        bst_node* parent;
        NodeKeyType Key;
    };

    bst_node* new_node(NodeKeyType key)
    {
        return new bst_node{0, 0, 0, key};
    }

    /**
     * @brief 插入节点，递归版本    
     * 
     * @param root 根节点
     * @param key 值
     * @param comp 比较函数指针
     * @return 是否插入成功
     * 
     * @note 函数指针返回值说明:
     *  - 0 表示相等 
     *  - 小于0 表示左操作符<右操作符
     *  - 大于0 表示左操作符>右操作符 
     */
    bool insert_r(bst_node** root, NodeKeyType key, KeyComp comp)
    {
        if (root == nullptr || *root == nullptr)
        {
            *root = new_node(key); 
            return true;
        }

        if (comp(key, (*root)->Key) == 0){
            return false;
        }else if(comp(key, (*root)->Key) < 0){
            // lhs < rhs
            if (insert_r(&(*root)->left_child, key, comp)){
                (*root)->left_child->parent = *root;
                return true;
            }
        }else{
            // lhs > rhs
            if (insert_r(&(*root)->right_child, key, comp)){
                (*root)->right_child->parent = *root;
                return true;
            }
        }

        return false;
    }

    /**
     * @brief 递归中序遍历二叉搜索树，有序 
     * 
     * @param root 二叉树根节点
     * @param result 返回遍历的结果
     */
    void In_order_traversal_r(bst_node* root, std::vector<NodeKeyType>& result)
    {
        if (root == nullptr){
            return;
        }

        In_order_traversal_r(root->left_child, result);
        result.push_back(root->Key);
        In_order_traversal_r(root->right_child, result);
    }


} // namespace bst
} // namespace data_structure
    

#endif // __binary_search_tree_included_
