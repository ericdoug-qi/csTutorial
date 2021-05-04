#include <vector>
#include "tree_node.hpp"

class BTLevelOrder{
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        if (root == NULL) { 
            return result; 
        }

        queue<TreeNode*> que;
        if (root != NULL) {
            que.push(root);
        }

        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left){
                    que.push(node->left);
                }

                if (node->right) {
                    que.push(node->right);
                }
            }
            result.push_back(vec);
        }

        return result;
        
    }

};