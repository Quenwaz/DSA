#ifndef __binary_search_tree_included_
#define __binary_search_tree_included_
#include <queue>
#include <stack>
#include <cstdio>

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
        bst_node* father;
        NodeKeyType Key;
    };

    bst_node* _new_node(NodeKeyType key)
    {
        return new bst_node{0, 0,0,  key};
    }

    /**
     * @brief 递归后序遍历删除链表二叉树
     * @param root 根节点
     * 
     */
    void free_r(bst_node* root)
    {
        if (nullptr == root){
            return;
        }

        free_r(root->left_child);
        free_r(root->right_child);
        delete root;
        root = nullptr;
    }



    /**
     * @brief 非递归后序遍历删除链表二叉树
     * @param root 根节点
     * 
     */
    void free(bst_node* root)
    {
        if (nullptr == root){
            return;
        }
        
        std::stack<bst_node**> stack_bst;
        stack_bst.push(&root);
        for(;!stack_bst.empty();){
            auto pNode = stack_bst.top();
            if ((*pNode)->left_child != nullptr){
                stack_bst.push(&(*pNode)->left_child);
            }
            else if ((*pNode)->right_child != nullptr){
                stack_bst.push(&(*pNode)->right_child);
            }else{
                stack_bst.pop();
                void* will_be_delete = (*pNode);
                if ((*pNode)->father != nullptr){
                    if ((*pNode)->father->left_child == (*pNode)){
                        (*pNode)->father->left_child = nullptr;
                    }else{
                        (*pNode)->father->right_child = nullptr;
                    }
                }
                delete will_be_delete;
            }
        }
    }

    /**
     * @brief 递归查找指定key值
     * 
     * @param root 根节点   
     * @param key key值
     * @param comp 比较函数指针
     * @return const bst_node* 返回节点指针
     */
    bool find_r(bst_node** pfind, bst_node* root, const NodeKeyType& key, KeyComp comp)
    {
        if (root == nullptr){
            *pfind = nullptr;
            return false;
        }

        if (comp(key, root->Key) == 0){
            *pfind = root;
            return true;
        }else if (comp(key, root->Key) < 0){
            return find_r(pfind, root->left_child, key, comp);
        }else{
            return find_r(pfind, root->right_child, key, comp);
        }

    }

    /**
     * @brief 找到二叉树中最大最小结点  
     * 
     * @param root 根节点指针
     * @return std::pair<bst_node**, bst_node**>  first->最小  second->最大
     */
    std::pair<bst_node**, bst_node**> find_minmax_r(bst_node* root)
    {
        if (root == nullptr){
            return {};
        }
        std::pair<bst_node**, bst_node**> ret;
        find_minmax_r((root)->left_child);
        ret.first = &root;
        find_minmax_r((root)->right_child);
        ret.second = &root;
        return ret;
    }

    /**
     * @brief 删除指定值的结点
     * 
     * @param root 根节点
     * @param key key值
     * @param comp 比较函数
     * @return true 删除成功
     * @return false 不存在删除失败
     */
    bool remove_at(bst_node* root, const NodeKeyType& key, KeyComp comp)
    {
        bst_node* pfind = nullptr;
        if (!find_r(&pfind, root, key, comp)){
            return false;
        }

        bst_node* willbefree = pfind;
        if (pfind->left_child == nullptr)
        {
           pfind = pfind->right_child;
        }else if ((pfind)->right_child == nullptr){
            pfind = (pfind)->left_child;
        }else{
            auto min_max = find_minmax_r((pfind)->left_child);
            (*min_max.second)->right_child = (pfind)->right_child;
            (pfind)->right_child->father = (*min_max.second);
            (pfind)->right_child = nullptr;

            if (pfind->father->left_child == pfind){
                pfind->father->left_child= (pfind)->left_child;
                (pfind)->left_child->father = pfind->father;
            }else{
                pfind->father->right_child= (pfind)->left_child;
                (pfind)->left_child->father = pfind->father;
            }
        }

        delete willbefree;
        willbefree = nullptr;
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
            *root = _new_node(key); 
            return true;
        }

        if (comp(key, (*root)->Key) == 0){
            return false;
        }else if(comp(key, (*root)->Key) < 0){
            // lhs < rhs
            if (insert_r(&(*root)->left_child, key, comp)){
                (*root)->left_child->father = (*root);
                return true;
            }
        }else{
            // lhs > rhs
            if (insert_r(&(*root)->right_child, key, comp)){
                (*root)->right_child->father = (*root);
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
    void in_order_traversal_r(bst_node* root, std::vector<NodeKeyType>& result)
    {
        if (root == nullptr){
            return;
        }

        in_order_traversal_r(root->left_child, result);
        result.push_back(root->Key);
        in_order_traversal_r(root->right_child, result);
    }

    /**
     * @brief 非递归中序遍历二叉搜索树，有序 
     * 
     * @param root 二叉树根节点
     * @param result 返回遍历的结果
     */
    void in_order_traversal(bst_node* root, std::vector<NodeKeyType>& result)
    {
        if (root == nullptr){
            return;
        }

        std::stack<bst_node*> stack_bst;
        stack_bst.push(root);
        bool visit_leftchild = true;
        for (;!stack_bst.empty();){
            auto pNode = stack_bst.top();
            if (visit_leftchild && pNode->left_child != nullptr){
                stack_bst.push(pNode->left_child);
                continue;
            }
            stack_bst.pop();
            if (pNode->right_child != nullptr){
                stack_bst.push(pNode->right_child);
                visit_leftchild = true;
            }
            else 
                visit_leftchild = false;
            result.push_back(pNode->Key);
        }
    }

    /**
     * @brief 宽度优先搜索二叉树
     * 
     * @param root 根节点
     * @param result 结果列表
     */
    void bfs(bst_node* root, std::vector<NodeKeyType>& result)
    {
        if(root == nullptr){
            return;
        }

        std::queue<bst_node*> queue_bst;
        queue_bst.push(root);
        for(;!queue_bst.empty();)
        {
            const auto node = queue_bst.front();
            if(node->left_child != nullptr)
                queue_bst.push(node->left_child);
            if(node->right_child != nullptr)
                queue_bst.push(node->right_child);
            queue_bst.pop();
            result.push_back(node->Key);
        }

    }


} // namespace bst
} // namespace data_structure
    

#endif // __binary_search_tree_included_
