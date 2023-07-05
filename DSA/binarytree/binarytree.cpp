#include "binarytree.hpp"

using dsa::ds::bt::TreeNode;

namespace __internal{
template <typename T>
TreeNode<T>* buildTree(const std::vector<T>& nums, size_t left, size_t right) {
    if (left > right) {
        return nullptr;
    }
    int mid = (left + right) / 2;
    TreeNode<T>* root = new TreeNode<T>(nums[mid]);
    root->left = buildTree(nums, left, mid - 1);
    root->right = buildTree(nums, mid + 1, right);
    return root;
}

template <typename T>
void inorderTraversal(TreeNode<T>* root, std::vector<T>& res) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left, res);
    res.push_back(root->val);
    inorderTraversal(root->right, res);
}
}

