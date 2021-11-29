#include <bits/stdc++.h>
using namespace std;

/* Definition for a binary tree node. */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* 
https://leetcode-cn.com/problems/diameter-of-binary-tree/
543. 二叉树的直径
给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

若是能够想到递推性，从下往上，计算。
还有长度等价于遍历的节点路径，等于左右两个节点的路径之和
 */

class Solution
{
public:
    int maxd = 1;
    int diameterOfBinaryTree(TreeNode *root)
    {
        int ans = depth(root);
        return maxd - 1;
    }
    int depth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int left = depth(root->left);
        int right = depth(root->right);

        maxd = max(maxd, left + right + 1);
        return max(left, right) + 1;
    }
};

/* 
https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/
124. 二叉树中的最大路径和
路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

路径和 是路径中各节点值的总和。

给你一个二叉树的根节点 root ，返回其 最大路径和 。

 */

int maxd = INT_MIN;
int sumDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = max(sumDepth(root->left), 0);
    int right = max(sumDepth(root->right), 0);

    maxd = max(maxd, left + right + root->val);
    return max(left, right) + root->val;
}
int maxPathSum(TreeNode *root)
{
    int ans = sumDepth(root);
    return maxd;
}

/* 

https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/

给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数
 */

int maxdd = 0;
int maxDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    maxdd = max(right, left);
    return max(left, right) + 1;
}

int main(int argc, char const *argv[])
{
    int n = 3;
    vector<int> input = {1, 2, 3};
    struct TreeNode *root = new TreeNode[n];
    for (size_t i = 0; i < n; i++)
    {
        root[i].val = input[i];
        root[i].left = &root[2 * i + 1];
        root[i].right = &root[2 * i + 2];
    }
    // root[n - 1].left = NULL;
    // root[n-2]

    Solution sol;
    cout << sol.diameterOfBinaryTree(root) << endl;
    return 0;
}
