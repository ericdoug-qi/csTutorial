
#include <vector>
#include "binary_tree_traversal.hpp"


void BinaryTreeTraversal::travelsal(TreeNode* cur, vectore<int>& vec) 
{
    if (cur == NULL) return;

    vec.push_back(cur->val);
    travelsal(cur->left, vec);
    travelsal(cur->right, vec);
}

vector<int> BinaryTreeTraversal::preorderTraversal(TreeNode* root)
{
    vector<int> result;
    travelsal(root, result);
    return result;
}
