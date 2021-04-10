#include <iostream>
#include "tree_node.hpp"

/**
 * 前缀和 + 回溯
 * 
 */

class Solution
{
private:
    unordered_map<int, int> prefix_sum;
    // 前缀和
    void dfs(TreeNode *root, int sum, int cur_sum, int &res)
    {
        if (!root)
        {
            return;
        }

        cur_sum += root->val; // 更新前缀和
        // 当前路径中存在以当前节点为终点的和为sum的子路径
        if (prefix_sum.find(cur_sum - sum) != prefix_sum.end())
        {
            res += prefix_sum[cur_sum - sum];
        }
        prefix_sum[cur_sum]++;               // 将当前节点加入路径
        dfs(root->left, sum, cur_sum, res);  // 在左子树中寻找
        dfs(root->right, sum, cur_sum, res); // 在右子树中寻找
        prefix_sum[cur_sum]--;               // 回溯
    }
    int helper(TreeNode *root, int target)
    {
        if (!root)
        {
            return 0;
        }
        int count = root->val == target ? 1 : 0;
        std::cout << count << std::endl;
        count += helper(root->left, target - root->val);
        count += helper(root->right, target - root->val);
        return count;
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        // return root ? helper(root, targetSum) + helper(root->left, targetSum) + helper(root->right, targetSum) : 0; // [1,null,2,null,3,null,4,null,5] 该case过不了
        int res = 0;       // 满足条件的路径数
        prefix_sum[0] = 1; // 前缀和为0的路径只有一条，哪个节点都不选
        dfs(root, targetSum, 0, res);
        return res;
    }
};