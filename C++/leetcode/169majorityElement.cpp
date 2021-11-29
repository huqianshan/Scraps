#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

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

int main(int argc, char *argv[])
{
}