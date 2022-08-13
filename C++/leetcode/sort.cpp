#include "../../C/intel_tsc/tsc.h"
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
    partition函数可以双向扫描，而非单向swap，也就是 双指针 方法
 */
int partition_double(vector<int> &nums, int left, int right, int pivotIndex)
{
    int pivotValue = nums[pivotIndex];
    swap(nums[pivotIndex], nums[right]);
    int l = left, r = right; // 这里我也不知道为什么不能取right-1
    while (l < r)
    {
        while (l < r && nums[l] <= pivotValue)
        {
            l++;
        }
        while (l < r && nums[r] >= pivotValue)
        {
            r--;
        }
        if (l < r)
        {
            swap(nums[l], nums[r]); // 此时 nums[r]<nums[pivotValue]<nums[l]
        }
    }
    swap(nums[right], nums[l]);
    return l;
}
int partition_raw(vector<int> &nums, int left, int right, int pivotIndex)
{
    int pivotValue = nums[pivotIndex];
    swap(nums[pivotIndex], nums[right]);
    int storeIndex = left; // i
    for (int j = left; j < right; j++)
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
int partition(vector<int> &nums, int left, int right, int pivotIndex)
{
    return partition_double(nums, left, right, pivotIndex);
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

   优化：
    五路查询、取中位数
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

/*
*********************************
*****       MergeSort       *****
*********************************
*/
void mergeSort(vector<int> &nums, vector<int> &tmp, int start, int end)
{
    if (start >= end) // why equal?
    {
        return;
    }
    int mid = start + (end - start) / 2;
    mergeSort(nums, tmp, start, mid);
    mergeSort(nums, tmp, mid + 1, end);

    int i = start;
    int j = mid + 1;
    int cnt = 0;
    while (i <= mid && j <= end)
    {
        if (nums[i] <= nums[j])
        {
            tmp[cnt++] = nums[i++];
        }
        else
        {
            tmp[cnt++] = nums[j++];
        }
    }
    while (i <= mid)
    {
        tmp[cnt++] = nums[i++];
    }
    while (j <= end)
    {
        tmp[cnt++] = nums[j++];
    }
    for (int i = 0; i < end - start + 1; i++)
    {
        nums[i + start] = tmp[i];
    }
}

vector<int> sortArray(vector<int> &nums)
{
    vector<int> tmp((int)nums.size(), 0);
    mergeSort(nums, tmp, 0, (int)nums.size() - 1);
    return nums;
}

class A
{
};
class B : public virtual A
{
};

class Foo
{
public:
    int value_a;
    int value_b;
    Foo(int a, int b) : value_a(a), value_b(b) {}
};

class MagicFoo
{
public:
    std::vector<int> vec;
    /*    MagicFoo(std::initializer_list<int> list)
       {
           for (std::initializer_list<int>::iterator it = list.begin();
                it != list.end(); ++it)
               vec.push_back(*it);
       } */
};

template <typename... T>
auto sum(T... t)
{
    return (t + ...);
}

void reference(int &v)
{
    std::cout << "left value" << std::endl;
}
void reference(int &&v)
{
    std::cout << "right value" << std::endl;
}
template <typename T>
void pass(T &&v)
{
    std::cout << "Normal argumenttt:";
    reference(v); // 始终调用 reference(int&)
}

int test_string(string s)
{
    cout << s << endl;
    return 3;
}
int main(int argc, char const *argv[])
{
    // cout << 3 % 1 << endl;
    // vector<int> nums = {3, 2, 1, 1};
    srand((unsigned)time(NULL));
    // vector<int> nums = {1, 1, 1, 1, 2, 1};
    /*   vector<int> nums = {1, 1, 2, 2, 3, 4, -1};
    nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    quickSort(nums, 0, nums.size() - 1);
    // heapSort(nums);
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

    // Foo s = {1, 2};
    MagicFoo ms{vector<int>{1, 2}};
    print_vector(ms.vec);

    cout << sum(1, 2, 3, 4, 5) << endl;

    std::cout << "right value" << std::endl;
    pass(std::move(1)); // 1是右值, 但输出是左值

    std::cout << "left value" << std::endl;
    int l = 1;
    pass(std::move(l)); // l 是左值, 输出左值    return 0;

    const char *str = "abc";
    // str[2] = 'c';
    cout << str << endl;

    string s1("12345");
    string s2 = s1;
    cout << (s1 == s2) << endl;
    s1[0] = '6';
    cout << "s1 = " << s1 << endl; // 62345
    cout << "s2 = " << s2 << endl; // 12345
    cout << (s1 == s2) << endl;

    char t[] = "123";

    string s = (std::move(string(static_cast<const char *>(t))));
    test_string(s); */

    uint64_t size = 384ul * 1024 * 1024;

    uint64_t begin = bench_start();
    vector<int> nums_big(size, 0);
    uint64_t end = bench_end();
    printf("Vector %4.4lf ms\n", cycles_to_sec(end - begin));

    begin = bench_start();
    for (auto &i : nums_big)
    {
        i = (uint64_t)rand() * rand();
    }
    end = bench_end();
    printf("Give value %4.4lf s\n", cycles_to_sec(end - begin));

    begin = bench_start();
    // quickSort(nums_big, 0, size - 1);
    sort(nums_big.begin(), nums_big.end());
    end = bench_end();
    printf("Sort %4.4lf s\n", cycles_to_sec(end - begin));
}
