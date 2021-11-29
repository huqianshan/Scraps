#include <iostream>
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

void print_vector(vector<int> nums)
{
    cout << "[";
    for (auto i : nums)
    {
        cout << i << ",";
    }
    cout << "]" << endl;
}

int main()
{
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    print_vector(intersection(nums1, nums2));
}