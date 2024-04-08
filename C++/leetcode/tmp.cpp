#include "helper.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lookup(vector<vector<int>> &arr, int n, int m)
{
    // 向上查找
    int row = arr.size();
    int col = arr[0].size() - 1;
    int ret = 0;
    int i = n;
    int j = m;
    while (i > 0)
    {
        i--;
        if (arr[i][j] == 0)
        {
            ret++;
        }
        else
        {
            break;
        }
    }
    i = n;
    while (i < col)
    {
        i++;
        if (arr[i][j] == 0)
        {
            ret++;
        }
        else
        {
            break;
        }
    }
    // left
    j = m;
    while (j > 0)
    {
        j--;
        if (arr[i][j] == 0)
        {
            ret++;
        }
        else
        {
            break;
        }
    }
    j = m;
    while (j < col)
    {
        j++;
        if (arr[i][j] == 0)
        {
            ret++;
        }
        else
        {
            break;
        }
    }
    return ret;
}
int do_find(vector<vector<int>> &arr, int n, int m)
{
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] != 0)
            {
                ret += lookup(arr, i, j);
            }
        }
    }
    return ret;
}

/* int main(int argc, char const *argv[])
{

    int n, m;
    int tem;
    cin >> n >> m;
    vector<vector<int>> nums(n, vector<int>(m, 0));
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cin >> tem;
            nums[i][j] = tem;
        }
        // printf("ts %d \n", i);
    }
    for (auto &&n : nums)
    {
        print_vector(n);
    }
    cout << do_find(nums, n, m);

    return 0;
} */

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
