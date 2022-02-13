#include "helper.h"

/*
1. 快速排序

流程：
    随机选取中枢点pivot, 左边区域均小于pivot,右边区域均大于pivot
    将pivot与nums[right]交换
    开始时 i=left-1,j=left
        如果nums[j]>=pivot,则直接将j++
        如果nums[j]< pivot,则将i++,然后swap(nums[i],nums[j]) （保证区间【i,right】内均为大于pivot）
    此时，【l,i】区间内的均小于pivot,[i+1,r-1]区间内的均大于pivot，再将nums[i+1]与nums[right]交换

优化：
    partition函数可以双向扫描，而非单向swap
 */
int partition(vector<int> &nums, int left, int right, int pivotIndex)
{
    int pivotValue = nums[pivotIndex];
    swap(nums[pivotIndex], nums[right]);
    int storeIndex = left; // i
    for (int j = left; j <= right - 1; j++)
    {
        if (nums[j] < pivotValue)
        {
            swap(nums[storeIndex], nums[j]);
            storeIndex++;
        }
    }
    swap(nums[right], nums[storeIndex]);
    return storeIndex;
}

void quickSort(vector<int> &nums, int left, int right)
{
    if (right > left)
    {
        int pivot = rand() % (right - left + 1) + left;
        int newPivot = partition(nums, left, right, pivot);
        // printf("p:%d newP:%d ", pivot, newPivot);
        // print_vector(nums);
        quickSort(nums, left, newPivot - 1);
        quickSort(nums, newPivot + 1, right);
    }
}

/* 变式-1 快速选择算法
   当pivotIndex==k时，返回
   小于，则在左边递归，大于在右边递归
 */
int quickSelect(vector<int> &nums, int left, int right, int targetIndex)
{
    int randPivotIndex = rand() % (right - left + 1) + left;
    int retPivotIndex = partition(nums, left, right, randPivotIndex);
    if (retPivotIndex == targetIndex)
    {
        return nums[retPivotIndex];
    }
    else if (retPivotIndex > targetIndex)
    {
        return quickSelect(nums, left, retPivotIndex - 1, targetIndex);
    }
    else if (retPivotIndex < targetIndex)
    {
        return quickSelect(nums, retPivotIndex + 1, right, targetIndex);
    }
    return 0;
}

/*
    2.堆排序 就地更新，逐个调整，保持性质
        1. 构建大顶堆
            自底向上构建，将大的值逐个上移
        2. 去掉堆顶元素
            与末尾元素交换，堆长度减一
        3. 调整堆，保证最大值上移至堆顶
        4. 直到长度为零
 */
void maxHeapify(vector<int> &nums, int len, int targetIndex)
{
    while ((2 * targetIndex + 1) <= len)
    {
        int leftChild = (2 * targetIndex) + 1;
        int rightChild = (2 * targetIndex) + 2;
        int maxIndex = targetIndex;

        if (leftChild <= len && nums[leftChild] > nums[targetIndex])
        {
            maxIndex = leftChild;
        }
        if (rightChild <= len && nums[rightChild] > nums[maxIndex])
        {
            maxIndex = rightChild;
        }

        if (maxIndex != targetIndex)
        {
            swap(nums[maxIndex], nums[targetIndex]);
            targetIndex = maxIndex;
        }
        else
        {
            break;
        }
    }
}

void buildHeap(vector<int> &nums, int len)
{
    for (int i = len / 2; i >= 0; i--)
    {
        maxHeapify(nums, len, i);
    }
}

void heapSort(vector<int> &nums)
{
    int len = nums.size() - 1;
    buildHeap(nums, len);
    for (int i = len; i > 0; i--)
    {
        swap(nums[0], nums[i]);
        maxHeapify(nums, --len, 0);
    }
}

class A
{
};
class B : public virtual A
{
};

int main(int argc, char const *argv[])
{
    // cout << 3 % 1 << endl;
    // vector<int> nums = {3, 2, 1, 1};
    srand((unsigned)time(NULL));
    // vector<int> nums = {1, 1, 1, 1, 2, 1};
    vector<int> nums = {1, 1, 2, 2, 3, 4, -1};
    nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    // quickSort(nums, 0, nums.size() - 1);
    heapSort(nums);
    print_vector(nums);

    int a = 3;
    int b = 4;
    const int *p = &a; // 底层const 修饰值，不可改 变值
    p = &b;
    cout << p << *p << endl;

    int *const hp = &a;
    *hp = 4;
    cout << *hp << endl;
    // hp = &a; // 顶层const 修饰指针,不可改变 指针
    printf("%d %d\n", sizeof(A), sizeof(B));

    return 0;
}
