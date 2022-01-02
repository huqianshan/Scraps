#include "helper.h"

/*
78. 子集
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 */
vector<vector<int>> ret;
vector<int> path;
void subsetsCore(vector<int> &nums, int index)
{
    if (index == nums.size())
    {
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        path.push_back(nums[i]);
        ret.push_back(path);
        subsetsCore(nums, i + 1);
        path.pop_back();
    }
}
vector<vector<int>> subsets(vector<int> &nums)
{
    ret.push_back(path);
    subsetsCore(nums, 0);
    return ret;
}

void test_all()
{
}

int main(int argc, char const *argv[])
{
    /* code */
    test_all();
    return 0;
}
