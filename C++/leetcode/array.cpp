#include "helper.h"
/*
27. 移除元素
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

双指针，快慢指针
 */
int removeElement(vector<int> &nums, int val)
{
    int len = nums.size();
    int l = 0;
    for (int r = 0; r < len; r++)
    {
        if (nums[r] != val)
        {
            nums[l++] = nums[r];
        }
    }
    return l;
}

/*
54. 螺旋矩阵
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 */
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int column = matrix[0].size();
    int left = 0, right = column;

    vector<int> ans(row * column, 0);

    int low = 0;
    int high = row;
    while (left < right)
    {
        // 1. 横向
        for (left < right)
        {
        }
    }
}

/*
977. 有序数组的平方
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 */
vector<int> sortedSquares(vector<int> &nums)
{
    int len = nums.size();
    vector<int> ans(len, 0);

    for (int i = 0, j = len - 1, pos = len - 1; i <= j; pos--)
    {
        if (nums[i] * nums[i] > nums[j] * nums[j])
        {
            ans[pos] = nums[i] * nums[i];
            i++;
        }
        else
        {
            ans[pos] = nums[j] * nums[j];
            j--;
        }
    }
    return ans;
}

void test_977(vector<int> &nums)
{
    print_vector(sortedSquares(nums));
}

void test_all()
{
    /* test 977*/
    vector<int> s = {-4, -1, 0, 3, 10};
    test_977(s);
    s = {-7, -3, 2, 3, 11};
    test_977(s);
}

int main(int argc, char const *argv[])
{
    test_all();
    return 0;
}
