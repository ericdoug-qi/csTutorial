#ifndef __H_BINARY_TREE_TRAVERSAL_H__
#include "tree_node.hpp"
#include <vector>

class BinaryTreeTraversal
{
public: 
    void travelsal(TreeNode* cur, vector<int>& vec);

    // 前序遍历
    vector<int> preorderTraversal(TreeNode* root);

};

#endif 