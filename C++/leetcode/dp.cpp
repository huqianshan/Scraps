#include "helper.h"

/*
5. 最长回文子串
给你一个字符串 s，找到 s 中最长的回文子串。
 */
pair<int, int> expand_center(int begin, int end, string s, int size)
{
    while (begin >= 0 && end < size && s[begin] == s[end])
    {
        begin--;
        end++;
    }
    return {begin + 1, end - 1};
}
string longestPalindrome(string s)
{
    int len = s.size();
    cout << len << endl;

    int begin = 0;
    int end = 0;
    for (int i = 0; i < len; i++)
    {
        auto [l1, r1] = expand_center(i, i, s, len);
        auto [l2, r2] = expand_center(i, i + 1, s, len);

        if (r1 - l1 > end - begin)
        {
            begin = l1;
            end = r1;
        }

        if (r2 - l2 > end - begin)
        {
            begin = l2;
            end = r2;
        }
    }
    return s.substr(begin, end - begin + 1);
}

string longestPalindrome_dp(string s)
{
    int len = s.size();
    vector<vector<int>> dp(len, vector<int>(len, 0));
    int ans = 0;
    string ret;
    int begin = 0;
    int end = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        for (int j = i; j < len; j++)
        {
            if (s[i] == s[j])
            {
                if (j - i <= 1)
                {
                    dp[i][j] = 1;
                }
                else if (dp[i + 1][j - 1])
                {
                    dp[i][j] = 1;
                }
            }
            if (dp[i][j] == 1)
            {
                int tem = j - i + 1;
                if (tem > ans)
                {
                    ans = tem;
                    begin = i;
                    end = j;
                }
            }
        }
    }
    return s.substr(begin, end - begin + 1);
}
void test_5()
{
    string s = "cbbd";
    print_expected(5, longestPalindrome(s), string("bb"));
}

/*
62. 不同路径
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？
 */
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    for (auto line : dp)
    {
        print_vector(line);
    }
    return dp[m][n];
}

/*
63. 不同路径 II
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 */
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (obstacleGrid[i - 1][j - 1] == 1)
            {
                dp[i][j] = 0;
            }
            else if (i == 1 && j == 1)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[m][n];
}

/*
64. 最小路径和
给定一个包含非负整数的 m x n 网格 grid ，
请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。
 */
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1)
            {
                dp[i][j] = dp[i][j - 1] + grid[i - 1][j - 1];
            }
            else if (j == 1)
            {
                dp[i][j] = dp[i - 1][j] + grid[i - 1][j - 1];
            }
            else
            {

                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
    }
    for (auto line : dp)
    {
        print_vector(line);
    }
    return dp[m][n];
}

void test_path()
{
    vector<vector<int>> nums = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    // uniquePaths(9, 26);
    for (auto line : nums)
    {
        print_vector(line);
    }
    print_expected(64, minPathSum(nums), 7);
}

/*
198. 打家劫舍
你是一个专业的小偷，计划偷窃沿街的房屋。
每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，
一夜之内能够偷窃到的最高金额
 */
int rob(vector<int> &nums)
{
    int len = nums.size();
    if (len < 1)
    {
        return len;
    }
    vector<int> dp(len + 1);
    dp[0] = 0;
    dp[1] = nums[0];
    for (int i = 1; i < len; i++)
    {
        dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
    }
    return dp[len];
}
/*
213. 打家劫舍 II
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。
这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。
同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
 */
int rob2(vector<int> &nums)
{
    int len = nums.size();

    if (len < 1)
    {
        return len;
    }

    vector<int> nums1(nums.begin() + 1, nums.end());
    vector<int> nums2(nums.begin(), nums.end() - 1);
    return max(rob(nums1), rob(nums2));
}
/*
337. 打家劫舍 III
在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。
这个地区只有一个入口，我们称之为“根”。
除了“根”之外，每栋房子有且只有一个“父“房子与之相连。
一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。
如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

层次遍历是不行的，因为叔节点也是不相邻的。
 */
vector<vector<int>> level_travel(TreeNode *root)
{
    vector<vector<int>> level;
    queue<TreeNode *> que;
    if (root != nullptr)
    {
        que.push(root);
    }

    while (!que.empty())
    {
        int len = que.size();
        vector<int> tem;
        for (int i = 0; i < len; i++)
        {
            TreeNode *cur = que.front();
            tem.push_back(cur->val);
            que.pop();
            if (cur->left)
            {
                que.push(cur->left);
            }
            if (cur->right)
            {
                que.push(cur->right);
            }
        }
        level.push_back(tem);
        tem.clear();
    }
    return level;
}
int rob3(TreeNode *root)
{
    vector<vector<int>> level = level_travel(root);
    int len = level.size();
    if (len < 1)
    {
        return len;
    }
    vector<int> dp(len + 1);
    dp[0] = 0;
    dp[1] = accumulate(level[0].begin(), level[0].end(), 0);
    for (int i = 1; i < len; i++)
    {
        dp[i + 1] = max(dp[i], dp[i - 1] + accumulate(level[i].begin(), level[i].end(), 0));
    }
    return dp[len];
}

/*
221. 最大正方形
在一个由 '0' 和 '1' 组成的二维矩阵内，
找到只包含 '1' 的最大正方形，并返回其面积。

这种题需要 找准dp数组的含义，
    dp[i][j] 定义为 以(i，j)为右下角的正方形边长最大数
 */
int maximalSquare(vector<vector<char>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int big = 0;

    vector<vector<int>> dp(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                if (i == 0 || j == 0)
                { //注意边界条件
                    dp[i][j] = matrix[i][j] - '0';
                }
                else
                {
                    dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
                }
                big = max(big, dp[i][j]);
            }
        }
    }
    for (auto n : dp)
    {
        print_vector(n);
    }
    return big;
}
struct NodeStatus
{
    int select;
    int not_select;
};

static NodeStatus dfs(TreeNode *root)
{
    if (root == nullptr)
    {
        return {0, 0};
    }
    NodeStatus left = dfs(root->left);
    NodeStatus right = dfs(root->right);

    int s = left.not_select + right.not_select + root->val;
    int n = max(left.select, left.not_select) + max(right.select, right.not_select);
    return {s, n};
}
int rob3_3(TreeNode *root)
{
    auto [sel, not_sel] = dfs(root);
    return max(sel, not_sel);
}

/* 322. 零钱兑换
给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 最少的硬币个数 。
如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。

贪心是不可以的，如【1，7，9】，amount=15,先选最大的，导致剩余找零存在更多的coin
 */
int coinChange(vector<int> &coins, int amount)
{
    return 3;
}
/*
518. 零钱兑换 II
给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。

请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。

假设每一种面额的硬币有无限个。

题目数据保证结果符合 32 位带符号整数。 */
int change(int amount, vector<int> &coins)
{

    int len = coins.size();
    vector<vector<int>> dp(len, vector<int>(amount + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (i != 0)
            {
                dp[i][j] += dp[i - 1][j];
            }
            if (j >= coins[i])
            {
                dp[i][j] += dp[i][j - coins[i]]; // not i-1 是从本coin中新增，而不是上一轮coin中
            }
        }
    }
    for (auto n : dp)
    {
        print_vector(n);
    }
    return dp[len - 1][amount];
}

int changeTrue(int amount, vector<int> coins)
{
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < coins.size(); i++)
    { // 遍历物品
        for (int j = coins[i]; j <= amount; j++)
        { // 遍历背包
            dp[j] += dp[j - coins[i]];
        }
        print_vector(dp);
    }
    return dp[amount];
}
/*
343. 整数拆分
给定一个正整数 n，
将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
 */
int integerBreak(int n)
{
    if (n == 2)
    {
        return 1;
    }
    else if (n == 3)
    {
        return 2;
    }
    int num3 = n / 3;
    int num2 = 0;
    int big = INT_MIN;
    for (int i = 0; i <= num3; i++)
    {
        int reminder = n - i * 3;
        num2 = reminder / 2;

        printf("num2:%d num3:%d\n", num2, i);
        int tem = 1;
        for (int j = 0; j < i; j++)
        {
            tem *= 3;
        }
        for (int i = 0; i < num2; i++)
        {
            tem *= 2;
        }
        big = max(tem, big);
    }
    return (big == INT_MIN) ? 1 : big;
}

void test_intbiger()
{
    print_expected(343, integerBreak(2), 1);
    print_expected(343, integerBreak(3), 2);
    print_expected(343, integerBreak(4), 4);
    print_expected(343, integerBreak(5), 6);
    print_expected(343, integerBreak(10), 36);
    print_expected(343, integerBreak(11), 54);
}

/*
416. 分割等和子集
给你一个 只包含正整数 的 非空 数组 nums 。
请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 */
bool canPartition(vector<int> &nums)
{
    int len = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0)
    {
        return false;
    }

    int target = sum / 2;
    vector<int> dp(target + 1);
    for (int i = 0; i < len; i++)
    {
        for (int j = target; j >= nums[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        }
    }
    return (dp[target] == target) ? true : false;
}

/*
1049. 最后一块石头的重量 II
有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。

每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。
 */
int lastStoneWeightII(vector<int> &stones)
{
    int len = stones.size();
    int sum = accumulate(stones.begin(), stones.end(), 0);

    int target = sum / 2;
    vector<int> dp(target + 1);
    for (int i = 0; i < len; i++)
    {
        for (int j = target; j >= stones[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
        }
    }
    return sum - dp[target] - dp[target];
}

int findTargetSumWays(vector<int> &nums, int S)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
        sum += nums[i];
    if (abs(S) > sum)
        return 0; // 此时没有方案
    if ((S + sum) % 2 == 1)
        return 0; // 此时没有方案
    int bagSize = (S + sum) / 2;
    vector<int> dp(bagSize + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = bagSize; j >= nums[i]; j--)
        {
            dp[j] += dp[j - nums[i]];
        }
        print_vector(dp);
    }
    return dp[bagSize];
}

void test_bag()
{
    vector<int> nums = {1, 5, 5, 11};
    print_expected(416, canPartition(nums), true);

    nums = {1, 2, 3};
    print_expected(416, canPartition(nums), true);

    nums = {1, 5, 5, 5, 6};
    print_expected(416, canPartition(nums), true);

    nums = {1, 1, 1, 1, 1};
    // findTargetSumWays(nums, 3);

    nums = {5, 2, 1};
    cout << change(5, nums) << endl;

    // findTargetSumWays(nums, 4);

    nums = {1, 2, 5};
    cout << change(5, nums) << endl;
    cout << "tss" << endl;
}

void test_coin()
{
    vector<int> nums = {5, 1, 2};
    int amount = 5;
    changeTrue(amount, nums);
    cout << "" << endl;
    change(amount, nums);

    nums = {1, 2, 5};
    change(4, nums);
    cout << "" << endl;
    changeTrue(4, nums);
}
/*
516. 最长回文子序列
给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。

子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
 */
int longestPalindromeSubseq(string s)
{
    int len = s.size();
    vector<vector<int>> dp(len, vector<int>(len, 0));

    for (int i = len - 1; i >= 0; i--)
    {
        dp[i][i] = 1;
        for (int j = i + 1; j < len; j++)
        {
            if (s[i] == s[j])
            {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    for (int i = 0; i < len; i++)
    {
        print_vector(dp[i]);
    }
    return dp[0][len - 1];
}

/*
674. 最长连续递增序列
给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。
连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。
 */
int findLengthOfLCIS(vector<int> &nums)
{
    int len = nums.size();
    int count = 1;
    int ans = 1;
    for (int i = 0; i < len - 1; i++)
    {
        if (nums[i] < nums[i + 1])
        {
            count++;
        }
        else
        {
            count = 1;
        }

        ans = max(count, ans);
    }
    return ans;
}

/*
1143. 最长公共子序列
给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。
 */
int longestCommonSubsequence(string text1, string text2)
{
    return 1;
}

void test_all()
{

    // test_5();
    // test_516();
    // test_path();
    // test_intbiger();
    // test_bag();
    test_coin();
}

int main(int argc, char const *argv[])
{
    test_all();
    cout << "Test DP Finished" << endl;
    return 0;
}
