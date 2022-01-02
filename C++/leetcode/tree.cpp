#include "helper.h"

/*
94. 二叉树的中序遍历
给定一个二叉树的根节点 root ，返回它的 中序 遍历。
144. 二叉树的前序遍历
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
 */

void traverse(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    traverse(root->left, ans);
    ans.push_back(root->val);
    traverse(root->right, ans);
}

vector<int> preorderTraversal(TreeNode *root)
{
    /*  vector<int> ans;
     traverse(root, ans);
     return ans; */
    if (root == NULL)
    {
        return {};
    }
    stack<TreeNode *> stk;
    TreeNode *cur = nullptr;
    vector<int> ans;
    stk.push(root);
    while (stk.empty() != true)
    {
        cur = stk.top();
        ans.push_back(cur->val);
        stk.pop();
        if (cur->right)
        {
            stk.push(cur->right);
        }
        if (cur->left)
        {
            stk.push(cur->left);
        }
    }
    return ans;
}

vector<int> inorderTraversal(TreeNode *root)
{
    stack<TreeNode *> stk;
    TreeNode *cur = root;
    vector<int> ans;
    while (stk.empty() != true || cur != nullptr)
    {
        if (cur != nullptr)
        {
            stk.push(cur);
            cur = cur->left;
        }
        else
        {
            cur = stk.top();
            ans.push_back(cur->val);
            stk.pop();
            cur = cur->right;
        }
    }
    return ans;
}

vector<int> postorderTraversal(TreeNode *root)
{
    stack<TreeNode *> st;
    vector<int> result;
    if (root == NULL)
        return result;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *node = st.top();
        st.pop();
        result.push_back(node->val);
        if (node->left)
            st.push(node->left); // 相对于前序遍历，这更改一下入栈顺序 （空节点不入栈）
        if (node->right)
            st.push(node->right); // 空节点不入栈
    }
    reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
    return result;
}

vector<int> postorderTraversal_all(TreeNode *root)
{
    vector<int> result;
    stack<TreeNode *> st;
    if (root != NULL)
        st.push(root);
    while (!st.empty())
    {
        TreeNode *node = st.top();
        if (node != NULL)
        {
            st.pop();
            st.push(node); // 中
            st.push(NULL);

            if (node->right)
                st.push(node->right); // 右
            if (node->left)
                st.push(node->left); // 左
        }
        else
        {
            st.pop();
            node = st.top();
            st.pop();
            result.push_back(node->val);
        }
    }
    return result;
}

void test_94()
{
    string s = "[5,4,6]";
    TreeNode *root = stringToTreeNode(s);
    vector<int> ans = inorderTraversal(root);
    print_vector(ans);
}

/*
101. 对称二叉树
给定一个二叉树，检查它是否是镜像对称的。
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 */
bool symmetric(TreeNode *rt1, TreeNode *rt2)
{
    // if (root->left == nullptr && root->right)
    return true;
}

bool isSymmetric(TreeNode *root)
{
    return true;
}

/*
102. 二叉树的层序遍历
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）
 */
vector<vector<int>> levelOrder(TreeNode *root)
{
    queue<TreeNode *> que;
    if (root != nullptr)
    {
        que.push(root);
    }
    vector<vector<int>> ans;
    while (que.empty() != true)
    {
        int len = que.size();
        vector<int> tmp;
        for (int i = 0; i < len; i++)
        {
            TreeNode *cur = que.front();
            que.pop();
            tmp.push_back(cur->val);
            if (cur->left)
            {
                que.push(cur->left);
            }
            if (cur->right)
            {
                que.push(cur->right);
            }
        }
        ans.push_back(tmp);
    }
    return ans;
}

/*
107. 二叉树的层序遍历 II
给定一个二叉树，返回其节点值自底向上的层序遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 */
vector<vector<int>> levelOrderBottom(TreeNode *root)
{
    vector<vector<int>> ans = levelOrder(root);
    reverse(ans.begin(), ans.end());
    return ans;
}

void test_102(TreeNode *root)
{
    auto ans = levelOrder(root);
    for (auto i : ans)
    {
        print_vector(i);
    }
}

/*
104. 二叉树的最大深度
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

/*
111. 二叉树的最小深度
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明：叶子节点是指没有子节点的节点。
 */
int minDepth(TreeNode *root)
{
    queue<TreeNode *> que;
    if (root != nullptr)
    {
        que.push(root);
    }
    int depth = 0;
    while (que.empty() != true)
    {
        int len = que.size();
        depth++;
        for (int i = 0; i < len; i++)
        {
            TreeNode *cur = que.front();
            que.pop();
            if (cur->left)
            {
                que.push(cur->left);
            }
            if (cur->right)
            {
                que.push(cur->right);
            }

            if (cur->left == nullptr && cur->right == nullptr)
            {
                return depth;
            }
        }
    }
    return depth;
}

/*
114. 二叉树展开为链表
给你二叉树的根结点 root ，请你将它展开为一个单链表：

展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
展开后的单链表应该与二叉树 先序遍历 顺序相同。
 */
vector<TreeNode *> ans;
void preTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    ans.push_back(root);
    preTraversal(root->left);
    preTraversal(root->right);
}
void flatten(TreeNode *root)
{
    preTraversal(root);

    int len = ans.size();
    ans.push_back({});
    for (int i = 0; i < len; i++)
    {
        auto cur = ans.at(i);
        auto next = ans.at(i + 1);
        cur->left == nullptr;
        cur->right = next;
    }
}

/*
116. 填充每个节点的下一个右侧节点指针
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
Node *connect(Node *root)
{
    queue<Node *> que;
    if (root != nullptr)
    {
        que.push(root);
    }
    while (que.empty() != true)
    {
        int len = que.size();
        Node *prev = nullptr;
        for (int i = 0; i < len; i++)
        {
            Node *cur = que.front();
            que.pop();
            if (prev != nullptr)
            {
                prev->next = cur;
            }
            prev = cur;
            // tmp.push_back(cur->val);
            if (cur->left)
            {
                que.push(cur->left);
            }
            if (cur->right)
            {
                que.push(cur->right);
            }
        }
    }
    return root;
}

/*
199. 二叉树的右视图
给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 */
vector<int> rightSideView(TreeNode *root)
{
    queue<TreeNode *> que;
    if (root != nullptr)
    {
        que.push(root);
    }
    vector<int> ans;
    while (que.empty() != true)
    {
        int len = que.size();
        for (int i = 0; i < len; i++)
        {
            TreeNode *cur = que.front();
            que.pop();
            if (i == len - 1)
            {
                ans.push_back(cur->val);
            }
            if (cur->left)
            {
                que.push(cur->left);
            }
            if (cur->right)
            {
                que.push(cur->right);
            }
        }
    }
    return ans;
}

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
226. 翻转二叉树
翻转一棵二叉树。
 */
void invertNode(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertNode(root->left);
    invertNode(root->right);
}

TreeNode *invertTree(TreeNode *root)
{
    invertNode(root);
    return root;
}

/*
515. 在每个树行中找最大值
给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
 */
vector<int> largestValues(TreeNode *root)
{
    queue<TreeNode *> que;
    if (root != nullptr)
    {
        que.push(root);
    }
    vector<int> ans;
    while (que.empty() != true)
    {
        int len = que.size();
        int max_item = INT_MIN;
        for (int i = 0; i < len; i++)
        {
            TreeNode *cur = que.front();
            que.pop();
            max_item = max(cur->val, max_item);
            if (cur->left)
            {
                que.push(cur->left);
            }
            if (cur->right)
            {
                que.push(cur->right);
            }
        }
        ans.push_back(max_item);
    }
    return ans;
}

/*
538. 把二叉搜索树转换为累加树
给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。

提醒一下，二叉搜索树满足下列约束条件：

节点的左子树仅包含键 小于 节点键的节点。
节点的右子树仅包含键 大于 节点键的节点。
左右子树也必须是二叉搜索树。
 */
int sum = 0;
TreeNode *convertBST(TreeNode *root)
{
    if (root != nullptr)
    {
        convertBST(root->right);
        sum += root->val;
        root->val = sum;
        convertBST(root->left);
    }
    return root;
}

void test_538()
{
    string s = "[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]";
    TreeNode *root = stringToTreeNode(s);
    auto ret = convertBST(root);
    // TreeNode *ret = postTraversal(root, 6);
    string ret_string = treeNodeToString(ret);
    cout << ret_string << endl;
}

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
617. 合并二叉树
给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。

你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。
 */
TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    if (root1 == nullptr)
    {
        return root2;
    }
    if (root2 == nullptr)
    {
        return root1;
    }
    auto merged = new TreeNode(root1->val + root2->val);
    merged->left = mergeTrees(root1->left, root2->left);
    merged->right = mergeTrees(root1->right, root2->right);
    return merged;
}

/*
637. 二叉树的层平均值
给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。
 */
vector<double> averageOfLevels(TreeNode *root)
{
    auto ans = levelOrder(root);
    vector<double> ret;
    for (auto level : ans)
    {
        int sum = 0;
        for (auto v : level)
        {
            sum += v;
        }
        double avg = sum * 1.0 / level.size();
        ret.push_back(avg);
    }
    return ret;
}

void test_tree()
{
    string s = "[1,2,3,4]";
    TreeNode *root = stringToTreeNode(s);
    // test_94();
    // test_102(root);

    // s = "[3,9,20,null,null,15,7]";
    // root = stringToTreeNode(s);
    // test_102(root);

    // s = "[]";
    // root = stringToTreeNode(s);
    // test_102(root);
    // flatten(root);
    test_538();
}

int main(int argc, char const *argv[])
{
    test_tree();
    return 0;
}
