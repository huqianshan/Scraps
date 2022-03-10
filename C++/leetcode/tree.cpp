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
96. 不同的二叉搜索树
给你一个整数 n ，
求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？
返回满足题意的二叉搜索树的种数。
 */
int numTrees(int n)
{
    if (n <= 2)
    {
        return n;
    }

    vector<int> nums(n + 1, 0);
    nums[0] = 1;
    nums[1] = 1;
    nums[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            nums[i] += nums[j] * nums[i - 1 - j];
        }
    }
    return nums[n];
}
void test_96()
{
    vector<int> nums{1, 2, 3, 4};
    for (auto n : nums)
    {
        cout << numTrees(n) << endl;
    }
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
106. 从中序与后序遍历序列构造二叉树
根据一棵树的中序遍历与后序遍历构造二叉树。
注意:
你可以假设树中没有重复的元素
*/
// 中序区间：[inorderBegin, inorderEnd)，后序区间[postorderBegin, postorderEnd)
TreeNode *traversal(vector<int> &inorder, int inorderBegin, int inorderEnd,
                    vector<int> &postorder, int postorderBegin, int postorderEnd)
{
    if (postorderBegin == postorderEnd)
        return NULL;

    int rootValue = postorder[postorderEnd - 1];
    TreeNode *root = new TreeNode(rootValue);

    if (postorderEnd - postorderBegin == 1)
        return root;

    int delimiterIndex;
    for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++)
    {
        if (inorder[delimiterIndex] == rootValue)
            break;
    }
    // 切割中序数组
    // 左中序区间，左闭右开[leftInorderBegin, leftInorderEnd)
    int leftInorderBegin = inorderBegin;
    int leftInorderEnd = delimiterIndex;
    // 右中序区间，左闭右开[rightInorderBegin, rightInorderEnd)
    int rightInorderBegin = delimiterIndex + 1;
    int rightInorderEnd = inorderEnd;

    // 切割后序数组
    // 左后序区间，左闭右开[leftPostorderBegin, leftPostorderEnd)
    int leftPostorderBegin = postorderBegin;
    int leftPostorderEnd = postorderBegin + delimiterIndex - inorderBegin; // 终止位置是 需要加上 中序区间的大小size
    // 右后序区间，左闭右开[rightPostorderBegin, rightPostorderEnd)
    int rightPostorderBegin = postorderBegin + (delimiterIndex - inorderBegin);
    int rightPostorderEnd = postorderEnd - 1; // 排除最后一个元素，已经作为节点了

    root->left = traversal(inorder, leftInorderBegin, leftInorderEnd, postorder, leftPostorderBegin, leftPostorderEnd);
    root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, postorder, rightPostorderBegin, rightPostorderEnd);

    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    if (inorder.size() == 0 || postorder.size() == 0)
        return NULL;
    // 左闭右开的原则
    return traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
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
208. 实现 Trie (前缀树)
Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。

请你实现 Trie 类：

Trie() 初始化前缀树对象。
void insert(String word) 向前缀树中插入字符串 word 。
boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。
 */

class Trie
{
private:
    vector<Trie *> children;
    bool isEnd;

    Trie *searchPrefix(string prefix)
    {
        Trie *node = this;
        for (char ch : prefix)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr)
            {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }

public:
    Trie() : children(26), isEnd(false) {}

    void insert(string word)
    {
        Trie *node = this;
        for (char ch : word)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr)
            {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        Trie *node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix)
    {
        return this->searchPrefix(prefix) != nullptr;
    }
};

/*
222. 完全二叉树的节点个数
给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。

完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。
 */
int countNodes(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    TreeNode *left = root->left;
    TreeNode *right = root->right;
    int leftHeight = 0, rightHeight = 0; // 这里初始为0是有目的的，为了下面求指数方便
    while (left)
    { // 求左子树深度
        left = left->left;
        leftHeight++;
    }
    while (right)
    { // 求右子树深度
        right = right->right;
        rightHeight++;
    }
    if (leftHeight == rightHeight)
    {
        return (2 << leftHeight) - 1; // 注意(2<<1) 相当于2^2，所以leftHeight初始为0
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}
int countNodes_On(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int num = countNodes_On(root->left);
    int mun = countNodes_On(root->right);
    return num + mun + 1;
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
257. 二叉树的所有路径
给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。

叶子节点 是指没有子节点的节点。
 */
vector<string> path;
void traves_recur(TreeNode *root, string single_path)
{
    // 1.确定递归基
    if (root == nullptr)
    {
        return;
    }

    single_path += to_string(root->val);
    if (root->left == nullptr && root->right == nullptr)
    {
        path.push_back(single_path);
        return;
    }
    single_path += "->";

    traves_recur(root->left, single_path);
    traves_recur(root->right, single_path);
}

vector<string>
binaryTreePaths(TreeNode *root)
{
    return {};
}

class Codec
{
public:
    void rserialize(TreeNode *root, string &str)
    {
        if (root == nullptr)
        {
            str += "null,";
        }
        else
        {
            str += to_string(root->val) + ",";
            rserialize(root->left, str);
            rserialize(root->right, str);
        }
    }

    string serialize(TreeNode *root)
    {
        string ret;
        rserialize(root, ret);
        return ret;
    }

    TreeNode *rdeserialize(list<string> &dataArray)
    {
        if (dataArray.front() == "null")
        {
            dataArray.erase(dataArray.begin());
            return nullptr;
        }

        TreeNode *root = new TreeNode(stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        root->left = rdeserialize(dataArray);
        root->right = rdeserialize(dataArray);
        cout << "List size" << dataArray.size() << "" << endl;
        if (dataArray.size() == 0)
        {
            cout << "ok>?" << dataArray.front() << "" << endl;
        }
        return root;
    }

    TreeNode *deserialize(string data)
    {
        list<string> dataArray;
        string str;
        for (auto &ch : data)
        {
            if (ch == ',')
            {
                dataArray.push_back(str);
                str.clear();
            }
            else
            {
                str.push_back(ch);
            }
        }
        /*   if (!str.empty())
          {
              dataArray.push_back(str);
              str.clear();
          } */
        return rdeserialize(dataArray);
    }
};

void test_ser()
{
    string s = "[1,2,3]";
    // s = "[3,9,20,null,null,15,7]";
    TreeNode *root = stringToTreeNode(s);
    Codec ser;
    cout << "" << ser.serialize(root) << "" << endl;
    cout << treeNodeToString(ser.deserialize(ser.serialize(root))) << "" << endl;
    cout << "" << treeNodeToString(root) << "" << endl;
}

/*
404. 左叶子之和
计算给定二叉树的所有左叶子之和。
 */
int sumOfLeftLeaves(TreeNode *root)
{
    // 1. base
    if (root == nullptr)
    {
        return 0;
    }

    int cur = 0;
    if (root->left && root->left->right == nullptr && root->left->left == nullptr)
    {
        cur = root->left->val;
        printf("%p %d \n", root, cur);
    }
    return cur + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}

/*
437. 路径总和 III
给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
 */
int travels(TreeNode *root, int pathSum)
{
    if (root == nullptr)
    {
        return 0;
    }

    int ret = 0;
    if (pathSum - root->val == 0)
    {
        ret++;
    }
    ret += travels(root->left, pathSum - root->val);
    ret += travels(root->right, pathSum - root->val);
    return ret;
}

int pathSum(TreeNode *root, int targetSum)
{
    if (root == nullptr)
    {
        return 0;
    }
    int ret = 0;
    ret = travels(root, targetSum);
    ret += pathSum(root->left, targetSum);
    ret += pathSum(root->right, targetSum);
    return ret;
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

/*
814. 二叉树剪枝
给你二叉树的根结点 root ，此外树的每个结点的值要么是 0 ，要么是 1 。

返回移除了所有不包含 1 的子树的原二叉树。

节点 node 的子树为 node 本身加上所有 node 的后代。
h后序遍历
 */
TreeNode *pruneTree(TreeNode *root)
{
    // 1. 递归基
    if (root == nullptr)
    {
        return nullptr;
    }
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (root->left == nullptr && root->right == nullptr && root->val == 0)
    {
        return nullptr;
    }
    return root;
}

void test_tree()
{
    // test_94();
    // test_102(root);

    // s = "[3,9,20,null,null,15,7]";
    // root = stringToTreeNode(s);
    // test_102(root);

    // s = "[]";
    // root = stringToTreeNode(s);
    // test_102(root);
    // flatten(root);
    // test_538();
    // print_expected(222, countNodes(root), 4);
    // traves_recur(root, "");
    // print_vector(path);
    // cout << sumOfLeftLeaves(root) << endl;
    // test_96();
    // test_ser();
}

int main(int argc, char const *argv[])
{
    test_tree();
    int a = 1;
    int b = 0;
    // int c = (++(++a)) + (++a);
    cout << "Ret " << a << " " << endl;

    return 0;
}
