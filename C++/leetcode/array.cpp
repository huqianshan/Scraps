#include "helper.h"

/*
15. 三数之和
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

双指针
关键在于重复值的去除
 */
vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int len = nums.size();
    vector<vector<int>> ans;

    for (int begin = 0; begin < len; begin++)
    {
        if (nums[begin] > 0)
        {
            return ans;
        }

        if (begin > 0 && nums[begin] == nums[begin - 1])
        {
            continue;
        }

        int right = len - 1;
        int left = begin + 1;

        while (left < right)
        {
            // 1. > 0 右边减
            if (nums[begin] + nums[left] + nums[right] > 0)
            {
                right--;
            }
            else if (nums[begin] + nums[left] + nums[right] < 0)
            {
                left++;
            }
            else
            {
                ans.push_back(vector<int>{nums[begin], nums[left], nums[right]});
                while (right > left && nums[right] == nums[right - 1])
                {
                    right--;
                }
                while (right > left && nums[left] == nums[left + 1])
                {
                    left++;
                }
                right--;
                left++;
            }
        }
    }
    return ans;
}

/*
16. 最接近的三数之和
给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。

返回这三个数的和。

假定每组输入只存在恰好一个解。

双指针
更新时，注意条件
 */
int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());

    int len = nums.size();
    int ans = 1e7;
    int sum = 0;

    for (int begin = 0; begin < len; begin++)
    {

        // 保证和上一次枚举的元素不相等
        if (begin > 0 && nums[begin] == nums[begin - 1])
        {
            continue;
        }
        int right = len - 1;
        int left = begin + 1;

        while (left < right)
        {
            sum = nums[begin] + nums[left] + nums[right];
            if (sum == target)
            {
                return target;
            }
            if (abs(sum - target) < abs(ans - target))
            {
                ans = sum;
            }

            if (sum > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
    }
    return ans;
}

/*
18. 四数之和
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。
 */
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int k = 0; k < nums.size(); k++)
    {
        // 去重
        if (k > 0 && nums[k] == nums[k - 1])
        {
            continue;
        }
        for (int i = k + 1; i < nums.size(); i++)
        {
            // 正确去重方法
            if (i > k + 1 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left)
            {
                // nums[k] + nums[i] + nums[left] + nums[right] > target 会溢出
                if (nums[k] + nums[i] > target - (nums[left] + nums[right]))
                {
                    right--;
                    // nums[k] + nums[i] + nums[left] + nums[right] < target 会溢出
                }
                else if (nums[k] + nums[i] < target - (nums[left] + nums[right]))
                {
                    left++;
                }
                else
                {
                    result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                    // 去重逻辑应该放在找到一个四元组之后
                    while (right > left && nums[right] == nums[right - 1])
                        right--;
                    while (right > left && nums[left] == nums[left + 1])
                        left++;

                    // 找到答案时，双指针同时收缩
                    right--;
                    left++;
                }
            }
        }
    }
    return result;
}

void test_15()
{
    string s = "[-1,2,1,-4]";
    vector<int> nums = stringToIntegerVector(s);
    int target = 1;
    // auto ret = threeSum(nums);
    // for (auto num : ret)
    // {
    //     print_vector(num);
    // }
    print_expected(16, threeSumClosest(nums, 1), 2);
    s = "[0,0,0]";
    nums = stringToIntegerVector(s);
    print_expected(16, threeSumClosest(nums, 1), 0);

    nums = {1, 1, 1, 0};
    target = 100;
    print_expected(16, threeSumClosest(nums, target), 3);

    nums = {1, 1, 1, 1};
    target = -100;
    print_expected(16, threeSumClosest(nums, target), 3);

    nums = {0, 2, 1, -3};
    target = 1;
    int ret_expected = 0;
    print_expected(16, threeSumClosest(nums, target), ret_expected);

    s = "[13,2,0,-14,-20,19,8,-5,-13,-3,20,15,20,5,13,14,-17,-7,12,-6,0,20,-19,-1,-15,-2,8,-2,-9,13,0,-3,-18,-9,-9,-19,17,-14,-19,-4,-16,2,0,9,5,-7,-4,20,18,9,0,12,-1,10,-17,-11,16,-13,-14,-3,0,2,-18,2,8,20,-15,3,-13,-12,-2,-19,11,11,-10,1,1,-10,-2,12,0,17,-19,-7,8,-19,-17,5,-5,-10,8,0,-12,4,19,2,0,12,14,-9,15,7,0,-16,-5,16,-12,0,2,-16,14,18,12,13,5,0,5,6]";
    nums = stringToIntegerVector(s);
    target = -59;
    ret_expected = -58;
    print_expected(16, threeSumClosest(nums, target), ret_expected);
}
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

关键在于： 左闭右闭区间，保证渠道。后两个需要去重。
 */
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int column = matrix[0].size();
    int left = 0, right = column - 1;
    int up = 0, down = row - 1;
    vector<int> ans(row * column, 0);

    int j = 0;
    while (left <= right && up <= down)
    {
        // 1. 横向,左→右
        for (int i = left; i <= right; i++)
        {
            ans[j++] = matrix[up][i];
        }
        // 2. 纵向,上→下
        for (int i = up + 1; i <= down; i++)
        {
            ans[j++] = matrix[i][right];
        }
        // 3. 横向, 右→左

        if (left < right && up < down) // 必须的，提前结束遍历，防止重复
        {

            for (int i = right - 1; i > left; i--)
            {
                ans[j++] = matrix[down][i];
            }
            // 4. 纵向, 下→上
            for (int i = down; i > up; i--)
            {
                ans[j++] = matrix[i][left];
            }
        }
        up++;
        left++;
        right--;
        down--;
        // printf("left:%d right:%d up:%d down:%d\n", left, right, up, down);
    }
    // print_vector(ans);
    return ans;
}

/*
59. 螺旋矩阵 II
给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 */
vector<vector<int>> generateMatrix(int n)
{
    int row = n;
    int column = n;
    int left = 0, right = column - 1;
    int up = 0, down = row - 1;
    vector<vector<int>> matrix(row, vector<int>(column, 0));

    int j = 1;
    while (left <= right && up <= down)
    {
        // 1. 横向,左→右
        for (int i = left; i <= right; i++)
        {
            matrix[up][i] = (j++);
        }
        // 2. 纵向,上→下
        for (int i = up + 1; i <= down; i++)
        {
            matrix[i][right] = (j++);
        }
        // 3. 横向, 右→左

        if (left < right && up < down)
        {

            for (int i = right - 1; i > left; i--)
            {
                matrix[down][i] = (j++);
            }
            // 4. 纵向, 下→上
            for (int i = down; i > up; i--)
            {
                matrix[i][left] = (j++);
            }
        }
        up++;
        left++;
        right--;
        down--;
        // printf("left:%d right:%d up:%d down:%d\n", left, right, up, down);
    }
    // print_vector(ans);
    return matrix;
}

void test_54()
{
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};
    print_vector(spiralOrder(matrix));

    matrix = {{1, 2, 3, 4},
              {5, 6, 7, 8},
              {9, 10, 11, 12}};
    print_vector(spiralOrder(matrix));

    matrix = {{1, 2, 3, 4},
              {5, 6, 7, 8},
              {9, 10, 11, 12},
              {13, 14, 15, 16}};
    print_vector(spiralOrder(matrix));

    matrix = {{1}};
    print_vector(spiralOrder(matrix));

    matrix = {{6, 9, 7}};
    print_vector(spiralOrder(matrix));

    matrix = {{6}, {9}};
    print_vector(spiralOrder(matrix));
}

/*
454. 四数相加 II
给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 */
int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
{
    unordered_map<int, int> kmap;
    for (auto i : nums1)
    {
        for (auto j : nums2)
        {
            for (auto k : nums3)
            {

                kmap[i + j + k]++;
            }
        }
    }

    int count = 0;

    for (auto j : nums4)
    {
        if (kmap.find(0 - j) != kmap.end())
        {
            count += kmap[-j];
        }
    }

    return count;
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
    // vector<int> s = {-4, -1, 0, 3, 10};
    // test_977(s);
    // s = {-7, -3, 2, 3, 11};
    // test_977(s);

    // test_54();
    test_15();
}

int main(int argc, char const *argv[])
{
    test_all();
    return 0;
}
