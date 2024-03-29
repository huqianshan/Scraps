#include "helper.h"

/*
1. 两数之和
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案
 */
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> ans(2);
    int len = nums.size();
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ans[0] = i;
                ans[1] = j;
            }
        }
    }
    return ans;
}
vector<int> twoSum2(vector<int> &nums, int target)
{
    unordered_map<int, int> hashtable;
    for (int i = 0; i < nums.size(); ++i)
    {
        auto it = hashtable.find(target - nums[i]);
        if (it != hashtable.end())
        {
            return {it->second, i}; // 还能这么构造？
        }
        hashtable[nums[i]] = i;
    }
    return {};
}

/*
704. 二分查找
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
 */
int search(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    int mid = 0;
    while (left <= right)
    {
        mid = (right - left) / 2 + left;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
    }
    return -1;
}

/*
34. 在排序数组中查找元素的第一个和最后一个位置
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：

你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？


[1] 1
[1,2,3] 1
 */
/* vector<int> searchRange(vector<int> &nums, int target)
{
    int begin = -1, end = -1;
    int len = nums.size();
    int i = 0;
} */
vector<int> searchRange2(vector<int> &nums, int target)
{
    int begin = -1, end = -1;
    int len = nums.size();
    int i = 0;

    while (i < len)
    {
        if (nums[i++] == target)
        {
            begin = i - 1;
            end = i - 1;
            break;
        }
    }

    while (i < len)
    {
        if (nums[i] != target)
        {
            end = i - 1;
            break;
        }
        else if (i == len - 1)
        {
            end = i;
        }
        i++;
    }

    return {begin, end};
}

/*
33. 搜索旋转排序数组
整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，
使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ...,
nums[k-1]]（下标 从 0 开始 计数）。
例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
 */
int search_range(vector<int> &nums, int begin, int end, int target)
{
    int len = nums.size();
    if (end >= len || begin < 0 || begin > end)
    {
        return -1;
    }
    int left = begin, right = end;
    int mid = 0;
    while (left <= right)
    {
        mid = (right - left) / 2 + left;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
    }
    return -1;
}

int search_rotate(vector<int> &nums, int target)
{
    int len = nums.size();
    if (len == 1)
    {
        return (nums[0] == target) ? 0 : -1;
    }
    int point = -1;
    for (int i = 1; i < len; i++)
    {
        if (nums[i - 1] <= nums[i])
        { // 升序排列
            continue;
        }
        else
        {
            point = i;
            break;
        }
    }
    point = (point == -1) ? len : point;
    int ret = search_range(nums, 0, point - 1, target);
    if (ret != -1)
    {
        return ret;
    }
    ret = search_range(nums, point, len - 1, target);
    return ret;
}
int search_rotate2(vector<int> &nums, int target)
{
    int len = nums.size();
    if (len == 1)
    {
        return (nums[0] == target) ? 0 : -1;
    }
    int left = 0, right = len - 1;
    int mid = 0;
    while (left <= right)
    {
        mid = (right + left) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[0] <= nums[mid])
        {
            if (target >= nums[0] && target < nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            if (target <= nums[len - 1] && target > nums[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return -1;
}

void test_binary_search()
{
    vector<int> nums = {3, 4, 1, 2};
    print_expected(33, search_rotate2(nums, 5), -1);
    print_expected(33, search_rotate2(nums, 2), 3);
    nums = {1, 2, 3, 4};
    print_expected(33, search_rotate2(nums, 1), 0);
    nums = {3};
    print_expected(33, search_rotate2(nums, 3), 0);
    print_expected(33, search_rotate2(nums, 2), -1);

    nums = {3, 1};
    print_expected(33, search_rotate2(nums, 1), 1);
}
/*
209. 长度最小的子数组
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0
滑动窗口
 */
int minSubArrayLen(int target, vector<int> &nums)
{
    int minLen = INT_MAX;
    int len = nums.size();
    int left = 0, right = 0;

    int sum = 0;
    while (right < len)
    {
        sum += nums[right];

        if (sum >= target)
        {
            while (left < right && sum >= (target + nums[left]))
            {
                sum -= nums[left++];
            }

            minLen = min(right - left + 1, minLen);

            sum -= nums[left++];
        }
        right++;
    }
    return (minLen == INT_MAX) ? 0 : minLen;
}

/*
283. 移动零
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序
 */
void moveZeroes(vector<int> &nums)
{
    int cnt = 0;
    for (auto it = nums.begin(); it != nums.end();)
    {
        if (*it == 0)
        {
            it = nums.erase(it);
            cnt++;
        }
        else
        {
            ++it;
        }
    }

    for (int i = 0; i < cnt; i++)
    {
        nums.push_back(0);
    }
}

/*
双指针
 */
void moveZeroes_2(vector<int> &nums)
{
    int left = 0;
    int right = 0;
    int len = nums.size();

    while (right < len)
    {
        if (nums[right])
        {
            swap(nums[left], nums[right]);
            left++;
        }
        right++;
    }
}

/*
287. 寻找重复数
给定一个包含 n + 1 个整数的数组 nums ，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。

假设 nums 只有 一个重复的整数 ，找出 这个重复的数 。

你设计的解决方案必须不修改数组 nums 且只用常量级 O(1) 的额外空间。
*/
int findDuplicate(vector<int> &nums)
{
    /*     int len = nums.size() - 1;
        int target = 0;
        int sum = 0;
        for (int i : nums)
        {
            sum += i;
        }

        target = ((1 + len) * len) / 2;
        return (target > sum) ? (target - sum) : (sum - target); */
    return 1;
}

/*
448. 找到所有数组中消失的数字
给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。
 */
vector<int> findDisappearedNumbers(vector<int> &nums)
{
    int len = nums.size();
    vector<int> ans;

    for (int i = 0; i < len; i++)
    {
        while (nums[i] != nums[nums[i] - 1])
        {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    for (int i = 0; i < len; i++)
    {
        if (nums[i] != (i + 1))
        {
            ans.push_back(i + 1);
        }
    }
    return ans;
}
/*
442. 数组中重复的数据
给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。

找到所有出现两次的元素。

你可以不用到任何额外空间并在O(n)时间复杂度内解决这个问题吗？
 */
vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> ans;
    int len = nums.size();
    for (auto i : nums)
    {
        nums[(i - 1) % len] += len;
    }

    for (int i = 0; i < len; i++)
    {
        if (nums[i] > (2 * len))
        {
            ans.push_back(i % (2 * len) + 1);
        }
    }
    return ans;
}

/*
461. 汉明距离
两个整数之间的 汉明距离 指的是这两个数字对应二进制位不同的位置的数目。

给你两个整数 x 和 y，计算并返回它们之间的汉明距离。
 */
int hammingDistance(int x, int y)
{
    return __builtin_popcount(x ^ y);
}

void test_findDisappearedNumbers_448()
{
    vector<int> s{1, 3, 3, 5, 7, 8, 9, 10};
    int target = 3;
    // s = {1, 4, 4};
    // target = 4;
    // s = {1, 1, 1, 1, 1};
    // target = 11;
    // s = {1, 1, 1, 2};
    // cout << findDisappearedNumbers(s) << endl;
    // auto ret = findDuplicates(s);
    // print_vector(s);
    // print_vector(searchRange(s, target));
    cout << search(s, target) << endl;
}

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

#define ABS(N) ((N < 0) ? (-N) : (N))

/*
718. 最长重复子数组
给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度
 */
int findLength(vector<int> &nums1, vector<int> &nums2)
{
    int alen = nums1.size();
    int blen = nums2.size();
    vector<vector<int>> dp(alen + 1, vector<int>(blen + 1, 0));

    int max_len = INT_MIN;
    for (int i = 0; i < alen; i++)
    { // dp 行列数加一，作为边界
        for (int j = 0; j < blen; j++)
        {
            if (nums1[i] == nums2[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else
            { // 为什么不需要这一段呢？ 加上这一段为子序列，即不连续的也可以递推
              // dp[i + 1][j + 1] = max(dp[i][j + 1], max(dp[i + 1][j], dp[i][j]));
            }

            max_len = max(dp[i + 1][j + 1], max_len);
        }
    }

    for (int i = 0; i < alen; i++)
    {
        print_vector(dp[i]);
    }
    return max_len;
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
int maxProfit1(vector<int> &prices)
{
    int min_price = INT_MAX;
    int max_profit = INT_MIN;
    for (auto i : prices)
    {
        min_price = min(i, min_price);
        max_profit = max(i - min_price, max_profit);
    }
    return max_profit;
}

/*
122. 买卖股票的最佳时机 II
给定一个数组 prices ，其中 prices[i] 是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 */
int maxProfit2(vector<int> &prices)
{
    /* int len = prices.size();

    if (len < 2)
    {
        return 0;
    }

    vector<int> dp(len + 2, 0);
    int ret = 0;
    for (int i = 1; i < len; i++)
    {
        if (prices[i] > prices[i - 1])
        {
            dp[i + 2] = max(dp[i] + prices[i] - prices[i - 1], dp[i + 1] + prices[i] - prices[i - 1]);
            ret = max(dp[i + 2], ret);
        }
        else
        {
            dp[i + 2] = dp[i + 1];
        }
    }
    return ret; */

    int n = prices.size();
    int dp[n][2];
    dp[0][0] = 0, dp[0][1] = -prices[0];
    for (int i = 1; i < n; ++i)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp[n - 1][0];
}

/*
123. 买卖股票的最佳时机 III
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 */
int maxProfit3(vector<int> &prices)
{

    int n = prices.size();
    int buy1 = -prices[0], sell1 = 0;
    int buy2 = -prices[0], sell2 = 0;
    for (int i = 1; i < n; ++i)
    {
        buy1 = max(buy1, -prices[i]);
        sell1 = max(sell1, buy1 + prices[i]);
        buy2 = max(buy2, sell1 - prices[i]);
        sell2 = max(sell2, buy2 + prices[i]);
    }
    return sell2;
}

/*
188. 买卖股票的最佳时机 IV
给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 */
int maxProfit4(vector<int> &prices)
{
    return 1;
}

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

void test_dp()
{
    vector<int> s = {1, 2, 3, 2, 1};
    vector<int> t = {7, 6, 4, 3, 1};
    // print_expected(findLength(s, t), 4);
    maxProfit2(s);
    maxProfit2(t);
    s = {1, 2, 3, 4, 5};
    print_expected(maxProfit2(s), 4);
    t = {7, 1, 5, 3, 6, 4};
    print_expected(maxProfit2(t), 7);
    t = {3, 2, 6, 5, 0, 3};
    print_expected(maxProfit2(t), 7);
    // print_expected(findLength(s, t), 2);
    // s = {7, 6, 4, 3, 1};
    // cout << maxProfit(s) << endl;
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
    // test_maxProfit();

    // cout << __builtin_popcount(3) << endl;
}

int fib3(int n)
{
    std::function<int(int, int, int)> iter;
    iter = [n, &iter](int a, int b, int i)
    {
        if (i >= n)
        {
            return a;
        }
        else
        {
            return iter(b, b + a, i + 1);
        }
    };
    return iter(0, 1, 0);
}

int main()
{

    // test_minWindow_76();
    // test_climStairs_70();
    // cout << toLowerCase("Abaa") << endl;
    // printf("%d %d %d %d\n", 'a', 'z', 'A', 'Z');
    // test_findDisappearedNumbers_448();
    // test_dp();

    test_binary_search();
    cout << fib3(10) << endl;
    // fib3(3);
}