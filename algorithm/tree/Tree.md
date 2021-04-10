# 树

## 树的定义

```cpp
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} 
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){} 
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

```

## 树的递归

* [104. 二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/) `easy`

* [110. 平衡二叉树](https://leetcode-cn.com/problems/balanced-binary-tree/) `easy`

* [543. 二叉树的直径](https://leetcode-cn.com/problems/diameter-of-binary-tree/) `easy`

* [437. 路径总和 III](https://leetcode-cn.com/problems/path-sum-iii/) `medium`

