#include "helper.h"

/*
4. 寻找两个正序数组的中位数
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。;
请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。
 */
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size();
    int n = nums2.size();

    int sum = (m + n) / 2;
    int flag = (m + n) % 2;
    int i = 0, j = 0; // i,j=0; 这样i是未初始化的
    int pos = 0;
    int last_pos = 0;

    while (pos < sum)
    {
        if (i > m - 1)
        {
            j++;
            last_pos = 0;
        }
        else if (j > n - 1)
        {
            i++;
            last_pos = 1;
        }
        else if (nums1[i] <= nums2[j])
        {
            i++;
            last_pos = 1;
        }
        else
        {
            j++;
            last_pos = 0;
        }
        pos = i + j;
    }
    printf("%d %d %d\n", i, j, pos);
    return (last_pos == 1) ? nums1[i] : nums2[j];
}
void test_find()
{
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {4, 5};
    print_expected(4, findMedianSortedArrays(nums1, nums2), 3.0);
}
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
31. 下一个排列
实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列（即，组合出下一个更大的整数）。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须 原地 修改，只允许使用额外常数空间。
*/
void nextPermutation(vector<int> &nums)
{
    int len = nums.size();
    int min_pos = 0, max_pos = len - 1;
    while (max_pos > 0 && nums[max_pos - 1] >= nums[max_pos])
    { // 向左寻找最大值
        max_pos--;
    }
    if (max_pos != 0)
    {
        min_pos = len - 1;
        while (min_pos >= 0 && nums[max_pos - 1] >= nums[min_pos])
        {
            min_pos--;
        }
        printf("min_pos:%d max_pos:%d\n", min_pos, max_pos);
        swap(nums[max_pos - 1], nums[min_pos]);
    }
    reverse(nums.begin() + max_pos, nums.end()); // 2,3,1,,3,3 这个用reverse会错
}

void test_permutation()
{
    vector<int> nums = {1, 2, 3};
    nextPermutation(nums);
    print_expected(31, nums, vector<int>{1, 3, 2});

    nums = {3, 2, 1};
    nextPermutation(nums);
    print_expected(31, nums, vector<int>{1, 2, 3});

    nums = {1, 3, 2, 1, 1, 1};
    nextPermutation(nums);
    print_expected(31, nums, vector<int>{2, 1, 1, 1, 1, 3});

    nums = {1};
    nextPermutation(nums);
    print_expected(31, nums, vector<int>{1});

    nums = {1, 3, 2};
    nextPermutation(nums);
    print_expected(31, nums, vector<int>{2, 1, 3});

    nums = {2, 3, 1, 3, 3};
    nextPermutation(nums);
    print_expected(31, nums, vector<int>{2, 3, 3, 1, 3});
}

/*
48. 旋转图像
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
 */
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    // 水平翻转
    for (int i = 0; i < n / 2; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            swap(matrix[i][j], matrix[n - i - 1][j]);
        }
    }
    // 主对角线翻转
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
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

/*
73. 矩阵置零
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法
 */
const int FLAG = 9876543;
void setZeroes(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[0][j] = FLAG;
                matrix[i][0] = FLAG;
            }
        }
    }

    // 行
    for (int i = 0; i < col; i++)
    {
        if (matrix[0][i] == FLAG)
        {
            for (int j = 0; j < row; j++)
            {
                matrix[j][i] = 0;
            }
        }
    }

    // 列
    for (int i = 0; i < row; i++)
    {
        if (matrix[i][0] == FLAG)
        {
            for (int j = 0; j < col; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
}
void test_matrix()
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
56. 合并区间
以数组 intervals 表示若干个区间的集合，
其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回 一个不重叠的区间数组，
该数组需恰好覆盖输入中的所有区间 。
 */
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.size() == 0)
    {
        return {};
    }
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    for (int i = 0; i < intervals.size(); ++i)
    {
        int L = intervals[i][0], R = intervals[i][1];
        if (!merged.size() || merged.back()[1] < L)
        {
            merged.push_back({L, R});
        }
        else
        {
            merged.back()[1] = max(merged.back()[1], R);
        }
    }
    return merged;
}

static void test_merge()
{
    vector<vector<int>> nums = {{1, 2}, {3, 4}, {-1, 3}, {7, 8}};
    merge(nums);
}
/*
128. 最长连续序列
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题

hash 构建 哈希
 */
int longestConsecutive(vector<int> &nums)
{
    int len = nums.size();
    unordered_set<int> hash;
    for (auto n : nums)
    {
        hash.insert(n);
    }

    int longest = 0;
    int cur_num = 0;
    for (auto n : nums)
    {
        if (hash.find(n - 1) == hash.end())
        {
            cur_num = n;
            int tmp_longest = 1;
            while (hash.find(cur_num + 1) != hash.end())
            {
                tmp_longest++;
                cur_num++;
            }
            longest = max(tmp_longest, longest);
        }
    }
    return longest;
}

/*
200. 岛屿数量
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

矩阵模拟，深度优先搜索，广度优先搜索，dfs,
 */
static void dfs(vector<vector<char>> &grid, int row, int col, int max_row, int max_col)
{
    int cur = grid[row][col];

    if (cur == 'v' || cur == '0')
    {
        return;
    }

    grid[row][col] = 'v';

    if (row != 0)
    {
        dfs(grid, row - 1, col, max_row, max_col);
    }
    else if (row != max_row)
    {
        dfs(grid, row + 1, col, max_row, max_col);
    }

    if (col != 0)
    {
        dfs(grid, row, col - 1, max_row, max_col);
    }
    else if (col != max_col)
    {
        dfs(grid, row, col + 1, max_row, max_col);
    }
}
int numIslands(vector<vector<char>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();

    int ret = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == '1')
            {
                dfs(grid, i, j, row, col);
                ret++;
            }
        }
    }
    for (auto line : grid)
    {
        print_vector(line);
    }
    return ret;
}

/*
238. 除自身以外数组的乘积
给你一个长度为 n 的整数数组 nums，其中 n > 1，
返回输出数组 output ，
其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
 */
vector<int> productExceptSelf(vector<int> &nums)
{
    int left = 1;
    int len = nums.size();
    vector<int> ret(len, 1);
    for (int i = len - 2; i >= 0; i--)
    {
        ret[i] *= ret[i + 1] * nums[i + 1];
    }
    print_vector(ret);

    for (int i = 0; i < len; i++)
    {
        ret[i] *= left;
        left *= nums[i];
    }
    return ret;
}

void test_product()
{
    vector<int> nums = {1, 2, 3, 4};
    print_vector(productExceptSelf(nums));
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
560. 和为 K 的子数组
给你一个整数数组 nums 和一个整数 k ，
请你统计并返回该数组中和为 k 的连续子数组的个数。

如果直接用双指针，会丢失子数组，因为数组不是有序的
或者说，滑动窗口，也是不适用的，因为当值超过k时，会将左边界去掉，
但是负数的存在，使得窗口本应该继续向右移动的

前缀和 可以降低运算次数，虽然复杂度仍为n2 超时

hashmap: 记录pre-k存在的次数
 */
int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    mp[0] = 1;
    int count = 0, pre = 0;
    for (auto &x : nums)
    {
        pre += x;
        if (mp.find(pre - k) != mp.end())
        {
            count += mp[pre - k];
        }
        mp[pre]++;
    }
    return count;
}

int subarraySum_ex(vector<int> &nums, int k)
{
    int len = nums.size();
    unordered_map<int, int> hash_map;
    vector<int> prefix(len + 1);
    prefix[0] = 0;
    for (int i = 1; i < len + 1; i++)
    {
        prefix[i] = prefix[i - 1] + nums[i - 1];
    }

    int ret = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            if (prefix[j + 1] - prefix[i] == k)
            {
                ret++;
            }
        }
    }
    return ret;
}
int subarraySum_Nouse(vector<int> &nums, int k)
{
    // sort(nums.begin(), nums.end());
    int len = nums.size();
    int left = 0, right = 0;

    int ret = 0;
    int sum = 0;

    while (right != len)
    {
        sum += nums[right];

        while (sum > k)
        {
            sum -= nums[left];
            left++;
        }
        if (sum == k)
        {
            ret++;
            printf("left: %d right: %d Num: %d\n", left, right, ret);
        }
        // 小于k,右指针向右增加
        right++;
    }
    return ret;
}
void test_k()
{
    vector<int> s = {1, 2, 3};
    int k = 3;
    int ret_expected = 2;
    print_expected(560, subarraySum(s, k), ret_expected);

    s = {1, 1, 1};
    k = 2;
    ret_expected = 2;
    print_expected(560, subarraySum(s, k), ret_expected);

    s = {1, 3, 2, 5, 7, -2, 5, 3, 2};
    k = 5;
    ret_expected = 5;
    print_expected(560, subarraySum(s, k), ret_expected);
}
/* 581. 最短无序连续子数组
给你一个整数数组 nums ，你需要找出一个 连续子数组 ，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。

请你找出符合题意的 最短 子数组，并输出它的长度。 */
int findUnsortedSubarray(vector<int> &nums)
{

    int n = nums.size();
    int maxn = INT_MIN, right = -1;
    int minn = INT_MAX, left = -1;
    for (int i = 0; i < n; i++)
    {
        if (maxn > nums[i])
        {
            right = i;
        }
        else
        {
            maxn = nums[i];
        }
        if (minn < nums[n - i - 1])
        {
            left = n - i - 1;
        }
        else
        {
            minn = nums[n - i - 1];
        }
    }
    return right == -1 ? 0 : right - left + 1;
}

/* 739. 每日温度
请根据每日 气温 列表 temperatures ，
请计算在每一天需要等几天才会有更高的温度。
如果气温在这之后都不会升高，请在该位置用 0 来代替。
*/
vector<int> dailyTemperatures(vector<int> &T)
{
    vector<int> res(T.size());
    // 这里放元素索引，而不是元素
    stack<int> s;
    /* 单调栈模板 */
    for (int i = T.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && T[s.top()] <= T[i])
        {
            s.pop();
        }
        // 得到索引间距
        res[i] = s.empty() ? 0 : (s.top() - i);
        // 将索引入栈，而不是元素
        s.push(i);
    }
    return res;
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

    // test_matrix();
    // test_15();
    // test_k();
    // test_permutation();
    // test_merge();
    // test_product();
    test_find();
}

int main(int argc, char const *argv[])
{
    test_all();
    cout << "Test Array Finished" << endl;
    // vector<int> s = {1, 2};
    // cout << vector_sumrange(s, 0, 0) << endl;
    return 0;
}
