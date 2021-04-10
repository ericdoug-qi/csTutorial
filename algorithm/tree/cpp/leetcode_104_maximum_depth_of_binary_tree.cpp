#include <iostream>
#include "tree_node.hpp"

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        return root ? 1 max(maxDepth(root->left), maxDepth(root->right)):0;
    }
};