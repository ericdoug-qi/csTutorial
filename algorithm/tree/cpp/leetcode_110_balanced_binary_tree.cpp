#include <iostream>
#include "tree_node.hpp"


class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return helper(root) != -1;
    }

    /**
     * 求最大深度
     *  
     **/
    int helper(TreeNode *root)
    {
        if (!root) {
            return 0;
        }
        int left = helper(root->left);
        int right = helper(root->right);

        // 若子树已经不平衡， 返回-1
        if (left == -1 || right == -1 || abs(left - right) > 1) {
            return -1;
        }
        return 1 + max(left, right);
    }
};