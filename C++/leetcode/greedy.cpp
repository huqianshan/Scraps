#include "helper.h"

/*
11. 盛最多水的容器
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器

双指针
 */
int maxArea(vector<int> &height)
{
    int len = height.size();
    int left = 0;
    int right = len - 1;
    int area = 0;
    int tem = 0;

    while (left < right)
    {
        tem = min(height[left], height[right]) * (right - left);
        area = max(tem, area);
        if (height[left] < height[right])
        {
            ++left;
        }
        else
        {
            right--;
        }
    }
    return area;
}

/*
45. 跳跃游戏 II
给你一个非负整数数组 nums ，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

假设你总是可以到达数组的最后一个位置。
 */

int jump(vector<int> &nums)
{
    int maxPos = 0, n = nums.size(), end = 0, step = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (maxPos >= i)
        {
            maxPos = max(maxPos, i + nums[i]);
            if (i == end)
            {
                end = maxPos;
                ++step;
            }
        }
    }
    return step;
}
int jump2(vector<int> &nums)
{ // 从后向前遍历
    int len = nums.size();
    int r = len - 1;
    int minor = len - 1;
    int steps = 0;

    while (minor != 0)
    {
        for (int i = minor - 1; i >= 0; i--)
        {
            if (nums[i] + i >= r)
            {
                minor = min(i, minor);
            }
        }
        r = minor;
        steps++;
    }
    return steps;
}

/*
55. 跳跃游戏
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标。
 */
bool canJump(vector<int> &nums)
{ // 贪心
    int len = nums.size();
    int most = 0;
    for (int i = 0; i < len; i++)
    {
        if (i <= most)
        {
            most = max(i + nums[i], most);
            if (most >= len - 1)
            {
                return true;
            }
        }
    }
    return false;
}

bool canJump2(vector<int> &nums)
{ // 从后向前遍历
    int len = nums.size();
    int i = 0;
    int j = len - 2;
    int pos = len - 1;
    while (j >= i)
    {
        if (nums[j] >= len - j - 1)
        {
            pos = j;
        }
        else
        {
            if (nums[j] + j >= pos)
            {
                pos = j;
            }
        }
        j--;
    }
    return pos == 0;
}

/*
406. 根据身高重建队列
假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。

请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。
 */
vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
{
    int len = people.size();
    vector<int> index(len);
    iota(index.begin(), index.end(), 0);
    sort(index.begin(), index.end(), [&people](int l, int r)
         { return people[l][0] < people[r][0]; });
    // print_vector(index);

    vector<vector<int>> ans(len, {-1, -1});

    for (int i = 0; i < len; i++)
    {
        int offset = people[index[i]][1];
        int j = 0;
        int tem = 0;
        for (; j < len; j++)
        {
            if (ans[j][0] == -1 || ans[j][0] == people[index[i]][0])
            {
                tem++;
            }
            if (tem == offset)
            {
                break;
            }
        }
        ans[j][0] = people[index[i]][0];
        ans[j][1] = people[index[i]][1];
    }
    return ans;
}

/*

307. 区域和检索 - 数组可修改
给你一个数组 nums ，请你完成两类查询，其中一类查询要求更新数组下标对应的值，另一类查询要求返回数组中某个范围内元素的总和。

实现 NumArray 类：

NumArray(int[] nums) 用整数数组 nums 初始化对象
void update(int index, int val) 将 nums[index] 的值更新为 val
int sumRange(int left, int right) 返回子数组 nums[left, right] 的总和（即，nums[left] + nums[left + 1], ..., nums[right]）
 */
class NumArray
{
public:
    vector<int> bits;
    vector<int> nums;
    int len;
    int lowbit(int x)
    {
        return x & (-x);
    }

    //注：这里的求和将汇集到非终端结点（D00形式）
    // BIT中仅非终端结点i值是 第0~i元素的和
    //终端结点位置的元素和，将在求和函数中求得
    // BIT中的index，比原数组中大1
    NumArray(vector<int> &nums)
    {
        len = nums.size();
        this->nums = nums;
        bits.resize(len + 1);
        for (int i = 1; i < len + 1; i++)
        {
            bits[i] = nums[i - 1];
            for (int j = i - 2; j >= i - lowbit(i); j--)
            {
                bits[i] += nums[j];
            }
        }
    }

    void add(int index, int val)
    {

        for (int j = index; j < len + 1; j += lowbit(j))
        {
            // cout << j << endl;
            bits[j] += val;
        }
    }

    void update(int i, int val)
    {
        // 原有的值是 nums[i]，要使得修改为 val，需要增加 val - nums[i]
        add(i + 1, val - nums[i]);
        nums[i] = val;
    }

    int
    sum(int k)
    {
        int ans = 0;
        for (int i = k; i > 0; i -= lowbit(i))
        {
            ans += bits[i];
        }
        return ans;
    }

    int sumRange(int left, int right)
    {
        return sum(right + 1) - sum(left);
    }
};

void does(vector<int> &nums)
{
    vector<int> tmp = nums;
    sort(tmp.begin(), tmp.end());
    for (auto &n : nums)
    {
        n = lower_bound(tmp.begin(), tmp.end(), n) - tmp.begin() + 1;
    }
}

/*
剑指 Offer 51. 数组中的逆序对
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组，求出这个数组中的逆序对的总数
 */
int reversePairs(vector<int> &nums)
{
    int len = nums.size();

    does(nums);

    vector<int> t(len);
    NumArray bit(t);
    int ans = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        ans += bit.sum(nums[i] - 1);
        bit.add(nums[i], 1);
    }
    return ans;
}

int getId(int x, vector<int> a)
{
    return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
}

/*
315
 */
vector<int> countSmaller(vector<int> &nums)
{
    int len = nums.size();

    does(nums);

    vector<int> t(len);
    NumArray bit(t);
    int tmp = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        tmp += bit.sum(nums[i] - 1);
        bit.add(nums[i], 1);
    }
    return {};
}

/*
621. 任务调度器
给你一个用字符数组 tasks 表示的 CPU 需要执行的任务列表。
其中每个字母表示一种不同种类的任务。
任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完。
在任何一个单位时间，CPU 可以完成一个任务，或者处于待命状态。

然而，两个 相同种类 的任务之间必须有长度为整数 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。

你需要计算完成所有任务所需要的 最短时间 。


方法一： 模拟
失败尝试： 双循环 遍历n次，问题在于 hashmap可能会选择
        n,m
        z,s
        a,x
        a,x
而不是
        a,n
        a,m,
        z,s

所以，需要选择 未命中的、出现次数最多的task

方法二：归纳
    ret=max( (max_times-1)*n + count(times==max_times),
             task.size())
 */
int leastInterval(vector<char> &tasks, int n)
{
    vector<int> vec(26);
    for (auto t : tasks)
    {
        vec[t - 'A']++;
    }
    auto max_char = max_element(vec.begin(), vec.end());
    int max_occ_num = *max_char;
    int done_time = 0;
    for (auto v : vec)
    {
        if (v == max_occ_num)
        {
            done_time++;
        }
    }
    return max(done_time + (n + 1) * (max_occ_num - 1), static_cast<int>(tasks.size()));
}

void test_greedy()
{
    /*  vector<int> nums = {2, 3, 1, 1, 4};
     print_expected(jump(nums), 2);

     nums = {5, 0, 0, 1, 4};
     print_expected(jump(nums), 1);

     nums = {2, 3, 1, 1, 4};
     print_expected(jump(nums), 2);

     // nums = {0};
     // print_expected( jump(nums), true);

     nums = {2, 3, 0, 1, 4};
     print_expected(jump(nums), 2);
  */
    // vector<vector<int>> s{{7, 0}, {4, 0}};
    // auto a = reconstructQueue(s);
    // vector<vector<int>> a(3, {-1, -1});
    /*     vector<int> s{-1};
        NumArray numArray(s);

        print_vector(numArray.bits);
        print_expected(numArray.sumRange(0, 0), -1); // 返回 9 ，sum([1,3,5]) = 9
        numArray.update(0, 1);
        print_vector(numArray.bits);                // nums = [1,2,5]
        print_expected(numArray.sumRange(0, 0), 1); // 返回 8 ，sum([1,2,5]) = 8 */

    /*   vector<int> nums = {7, 5, 6, 4};
      does(nums);
      print_vector(nums);
      print_vector(countSmaller(nums)); */

    // task_schedule
    vector<char> s = {'A', 'A', 'B', 'A', 'B', 'A'};
    int n = 2;
    print_expected(621, leastInterval(s, n), 10);

    n = 1;
    print_expected(621, leastInterval(s, n), 7);
}

int main(int argc, char const *argv[])
{
    test_greedy();
    cout << "Test Finishedn" << endl;
    return 0;
}
