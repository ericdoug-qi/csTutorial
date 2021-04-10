#include <iostream>
#include "tree_node.hpp"

class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        helper(root, diameter);
        return diameter;
    }

    int helper(TreeNode *root, int& diameter)
    {
        if (!root) {
            return 0;
        }

        int left = helper(root->left, diameter);
        int right = helper(root->right, diameter);

        diameter = max(left + right, diameter);
        return max(left, right) + 1;
    }
};