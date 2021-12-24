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
}

int main(int argc, char const *argv[])
{
    test_greedy();

    vector<int> a{3, 0, 12, 2};
    print_vector(sort_indexes(a));
    return 0;
}
