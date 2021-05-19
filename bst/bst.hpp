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

    bst_node* new_node(NodeKeyType key, bst_node* parent)
    {
        return new bst_node{0, 0, parent, key};
    }

    /**
     * @brief 插入节点，递归版本    
     * 
     * @param root 根节点
     * @param key 值
     * @param comp 比较函数指针
     * @return bst_node* 返回插入的节点指针
     * 
     * @note 函数指针返回值说明:
     *  - 0 表示相等 
     *  - 小于0 表示左操作符<右操作符
     *  - 大于0 表示左操作符>右操作符 
     */
    bst_node* insert_r(bst_node* root, NodeKeyType key, KeyComp comp)
    {
        if (root == nullptr)
        {
            root = new_node(key, root);
            return root;
        }

        if (comp(key, root->Key) == 0){
            return root;
        }else if(comp(key, root->Key) < 0){
            // lhs < rhs
            return insert_r(root->left_child, key, comp);
        }else{
            // lhs > rhs
            return insert_r(root->right_child, key, comp);
        }
    }


} // namespace bst
} // namespace data_structure
    

#endif // __binary_search_tree_included_
