#include <cassert>
#include <chrono>
#include <climits>
#include <fstream>
#include <gtest/gtest.h>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
 */

vector<int> exchange(vector<int> &nums)
{
    int i = 0, j = nums.size() - 1;
    while (i < j)
    {
        while (i < j && (nums[i] & 1) == 1)
            i++;
        while (i < j && (nums[j] & 1) == 0)
            j--;
        swap(nums[i], nums[j]);
    }
    return nums;
}

vector<int> exchange2(vector<int> &nums)
{
    int len = nums.size();
    int slow = 0;
    int fast = 0;
    while (fast < len)
    {
        if (nums[fast] & 1)
        {
            swap(nums[slow], nums[fast]);
            slow++;
        }
        fast++;
    }
    return nums;
}

/*
https://leetcode-cn.com/problems/intersection-of-two-arrays/

Sol 1: for judge
Sol 2: Set 
Sol 3: 排序 + 双指针
*/

bool nums_exists(vector<int> &nums, int target)
{
    for (auto i : nums)
    {
        if (target == i)
        {
            return true;
        }
    }
    return false;
}

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    for (auto i : nums1)
    {
        if (!nums_exists(ans, i) && nums_exists(nums2, i))
        {
            ans.push_back(i);
        }
    }
    return ans;
}

template <typename T>
void print_vector(vector<T> nums)
{
    cout << "[";
    for (auto i : nums)
    {
        cout << i << ",";
    }
    cout << "]" << endl;
}

/*
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// solution 1 sort and select one
// solution 2 hashmap

// soulution 3 random O(n) O(1)
int rand_majority(vector<int> &nums)
{
    int len = nums.size();
    while (true)
    {
        int r_target = nums.at(rand() % len);
        int count = 0;

        for (int i : nums)
        {
            if (i == r_target)
            {
                count++;
            }
            if (count > len / 2)
            {
                return r_target;
            }
        }
    }
}

// soulution 4 vote O(n) O(1)
int vote_majority(vector<int> &nums)
{
    int ticket = 0;
    int target = -1;

    for (int i : nums)
    {
        if (i == target)
        {
            ticket++;
        }
        else if (--ticket < 0)
        {
            ticket = 0;
            target = i;
        }
    }
    return target;
}

int count_in_range(vector<int> &nums, int target, int lo, int hi)
{
    int count = 0;
    for (int i = lo; i <= hi; ++i)
        if (nums[i] == target)
            ++count;
    return count;
}
int majority_element_rec(vector<int> &nums, int lo, int hi)
{
    if (lo == hi)
        return nums[lo];
    int mid = (lo + hi) / 2;
    int left_majority = majority_element_rec(nums, lo, mid);
    int right_majority = majority_element_rec(nums, mid + 1, hi);
    if (count_in_range(nums, left_majority, lo, hi) > (hi - lo + 1) / 2)
        return left_majority;
    if (count_in_range(nums, right_majority, lo, hi) > (hi - lo + 1) / 2)
        return right_majority;
    return -1;
}

// soulution 4 divide-and-conquer O(n) O(1)
int dac_majority(vector<int> &nums)
{
    return majority_element_rec(nums, 0, nums.size() - 1);
}

int majorityElement(vector<int> &nums)
{
    // return rand_majority(nums);
    return vote_majority(nums);
}

/*

https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/

给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

 

示例：

输入："Let's take LeetCode contest"
输出："s'teL ekat edoCteeL tsetnoc"
 

提示：

在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

  */

string reverseWords(string s)
{
    int l = 0;
    int r = 0;

    // string ans(s);
    int len = s.length();

    while (l <= len)
    {
        while (s[r] != ' ' && s[r] != '\0')
        {
            r++;
        }
        r++;
        // cout << "r:" << r << " s[r]" << s[r] << endl;

        for (size_t j = 0; j < (r - l - 1); j++)
        {
            s[l + j] = s[r - j - 2];
            // swap(s[l+])
        }

        l = r;
        // cout << l << " " << r << endl;
    }
    return s;
}
/* 

https://leetcode-cn.com/problems/reverse-string/
 */
void reverseString(vector<char> &s)
{
    int l = 0;
    int r = s.size() - 1;

    char tem = 0;
    while (l < r)
    {
        tem = s[l];
        s[l] = s[r];
        s[r] = tem;
        l++;
        r--;
    }
}

/* 

https://leetcode-cn.com/problems/reverse-string-ii/
 */

void reverse(string &s, int start, int end)
{
    for (int i = start, j = end; i < j; i++, j--)
    {
        swap(s[i], s[j]);
    }
}
string reverseStr(string s, int k)
{
    int len = s.size();
    for (int i = 0; i < len; i += 2 * k)
    {
        // 1. 每隔 2k 个字符的前 k 个字符进行反转
        // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
        if (i + k <= len)
        {
            reverse(s, i, i + k - 1);
            continue;
        }
        // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
        reverse(s, i, len - 1);
    }
    return s;
}

/* 

https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 */

int lengthOfLongestSubstring(string s)
{
    int len = s.length();
    unordered_set<char> occ;
    int max_sub = 0;
    int tem = 0;
    int left = 0;

    for (int i = 0; i < len; i++)
    {
        if (occ.count(s[i]) == 0)
        { // 没找到
            occ.insert(s[i]);
            max_sub = max(max_sub, i - left + 1);
            continue;
        }

        while (s[left] != s[i])
        {
            occ.erase(s[left++]);
        }
        // set erase直接把对应重复key删除，需要保留，即如果擦除元素，直到重复的key.
        // 而left标识当前子串长度
        left++;
    }

    return max_sub;
}

int lengthOfLongestSubstring2(string s)
{
    // 哈希集合，记录每个字符是否出现过
    unordered_set<char> occ;
    int n = s.size();
    // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
    int rk = -1, ans = 0;
    // 枚举左指针的位置，初始值隐性地表示为 -1
    for (int i = 0; i < n; ++i)
    {
        if (i != 0)
        {
            // 左指针向右移动一格，移除一个字符
            occ.erase(s[i - 1]);
        }
        while (rk + 1 < n && !occ.count(s[rk + 1]))
        {
            // 不断地移动右指针
            occ.insert(s[rk + 1]);
            ++rk;
        }
        // 第 i 到 rk 个字符是一个极长的无重复字符子串
        ans = max(ans, rk - i + 1);
    }
    return ans;
}

/* 
76. 最小覆盖子串
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

 
注意：

对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。
 */

/* 
 1. 找到包含目标字串的最小子串
 2. 去除第一个目标字串元素，找到下一个目标字串元素，更新长度
 3. 直到找到字符串末尾
 */
string minWindow(string s, string t)
{
    int len = s.size();
    int count = t.size();

    unordered_map<char, int> occ;
    for (auto c : t)
    {
        occ[c]++;
    }

    int left = 0;
    int right = 0;
    int max_len = INT_MAX;
    int start = 0;

    while (right < len)
    {
        if (occ[s[right]] > 0)
        {
            count--;
        }
        occ[s[right]]--;

        if (count == 0)
        {
            while (left < right && occ[s[left]] < 0)
            { // 缩短滑动窗口
                occ[s[left++]]++;
            }
            if (right - left + 1 < max_len)
            {
                // 更新返回值
                max_len = right - left + 1;
                start = left;
            }
            // 去除一个目标元素，开启新的查找
            occ[s[left]]++;
            left++;
            count++;
        }
        right++;
    }
    return max_len == INT_MAX ? string() : s.substr(start, max_len);
}

#define ABS(N) ((N < 0) ? (-N) : (N))
/* 

647. 回文子串
给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。

回文字符串 是正着读和倒过来读一样的字符串。

子字符串 是字符串中的由连续字符组成的一个序列。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
 */
int countSubstrings(string s)
{
    int len = s.size();
    vector<vector<int>> dp(len, vector<int>(len, 0));
    int count = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        for (int j = i; j < len; j++)
        {
            if (s[i] == s[j])
            {
                if (j - i <= 1)
                {
                    count++;
                    dp[i][j] = 1;
                }
                else if (dp[i + 1][j - 1])
                {
                    count++;
                    dp[i][j] = 1;
                }
            }
        }
    }
    return count;
}

/* 

5. 最长回文子串
给你一个字符串 s，找到 s 中最长的回文子串。

1. 如果i=0, 
2. 如果i!=0, if i-1 == i+1 or i-1 == i or i+1 ==i, append

 */
string longestPalindrome(string s)
{
    int left = 0;
    int right = s.size();
    while (left < right)
    {

        left++;
    }
    return string();
}

void test_minWindow_76()
{
    string s = "ABCDE";
    string t = "ACE";
    cout << countSubstrings(t) << endl;
    s = "ADOBECODEBANC";
    t = "AAA";
    cout << countSubstrings(t) << endl;
}
/* 
动态规划
70. 爬楼梯
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。
https://leetcode-cn.com/problems/climbing-stairs/
 */
int climbStairs(int n)
{
    if (n <= 2)
    {
        return n;
    }

    vector<int> r(n + 1);
    r[0] = 0;
    r[1] = 1;
    r[2] = 2;
    int steps = 1;

    for (int i = 3; i < n + 1; i++)
    {
        r[i] = r[i - 1] + r[i - 2];
    }
    return r[n];
}

/* 

https://leetcode-cn.com/problems/min-cost-climbing-stairs/
 */
int minCostClimbingStairs(vector<int> &cost)
{
    int len = cost.size();
    vector<int> r(len);

    for (int i = 0; i < len; i++)
    {
        if (i < 2)
        {
            r[i] = cost[i];
        }
        else
        {
            r[i] = min(r[i - 2], r[i - 1]) + cost[i];
        }
    }

    return min(r[len - 1], r[len - 2]);
}

int fib(int n)
{
    if (n < 2)
    {
        return n;
    }
    int p = 0, q = 0, r = 1;
    for (int i = 2; i <= n; ++i)
    {
        p = q;
        q = r;
        r = p + q;
    }
    return r;
}

/* 
121. 买卖股票的最佳时机
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 
 */
/* int maxProfit(vector<int> &prices)
{
    int min_price = INT_MAX;
    int max_profit = INT_MIN;
    for (auto i : prices)
    {
        min_price = min(i, min_price);
        max_profit = max(i - min_price, max_profit);
    }
    return max_profit;
} */

/* 
309. 最佳买卖股票时机含冷冻期
给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
 */
int maxProfit(vector<int> &prices)
{
    return 0;
}

void test_maxProfit()
{
    vector<int> s = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(s) << endl;
    s = {7, 6, 4, 3, 1};
    cout << maxProfit(s) << endl;
}
/* 
338. 比特位计数
给你一个整数 n ，对于 0 <= i <= n 中的每个 i ，计算其二进制表示中 1 的个数 ，返回一个长度为 n + 1 的数组 ans 作为答案。
 */
vector<int> countBits(int n)
{
    // __builtin_popcount()
    vector<int> ans(n + 1);
    for (int i = 0; i <= n; i++)
    {
        ans[i] = __builtin_popcount(i);
    }
    return ans;
}

void test_climStairs_70()
{
    cout << climbStairs(2) << endl;
    cout << climbStairs(3) << endl;
    cout << climbStairs(4) << endl;

    vector<int> s = {10, 15, 20};
    cout << minCostClimbingStairs(s) << endl;
    cout << minCostClimbingStairs(s) << endl;
    test_maxProfit();

    // cout << __builtin_popcount(3) << endl;
}

int main()
{

    // test_minWindow_76();
    // test_climStairs_70();
    cout << countSubstrings("baa") << endl;
}