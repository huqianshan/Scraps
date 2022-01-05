#include "helper.h"

/*
5. 最长回文子串
给你一个字符串 s，找到 s 中最长的回文子串。
 */

pair<int, int> expand_center(int begin, int end, string s, int size)
{
    while (begin >= 0 && end < size && s[begin] == s[end])
    {
        begin--;
        end++;
    }
    return {begin + 1, end - 1};
}
string longestPalindrome(string s)
{
    int len = s.size();
    cout << len << endl;

    int begin = 0;
    int end = 0;
    for (int i = 0; i < len; i++)
    {
        auto [l1, r1] = expand_center(i, i, s, len);
        auto [l2, r2] = expand_center(i, i + 1, s, len);

        if (r1 - l1 > end - begin)
        {
            begin = l1;
            end = r1;
        }

        if (r2 - l2 > end - begin)
        {
            begin = l2;
            end = r2;
        }
    }
    return s.substr(begin, end - begin + 1);
}

string longestPalindrome_dp(string s)
{
    int len = s.size();
    vector<vector<int>> dp(len, vector<int>(len, 0));
    int ans = 0;
    string ret;
    int begin = 0;
    int end = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        for (int j = i; j < len; j++)
        {
            if (s[i] == s[j])
            {
                if (j - i <= 1)
                {
                    dp[i][j] = 1;
                }
                else if (dp[i + 1][j - 1])
                {
                    dp[i][j] = 1;
                }
            }
            if (dp[i][j] == 1)
            {
                int tem = j - i + 1;
                if (tem > ans)
                {
                    ans = tem;
                    begin = i;
                    end = j;
                }
            }
        }
    }
    return s.substr(begin, end - begin + 1);
}
void test_5()
{
    string s = "cbbd";
    print_expected(5, longestPalindrome(s), string("bb"));
}
/*
516. 最长回文子序列
给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。

子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
 */
int longestPalindromeSubseq(string s)
{
    int len = s.size();
    vector<vector<int>> dp(len, vector<int>(len, 0));

    for (int i = len - 1; i >= 0; i--)
    {
        dp[i][i] = 1;
        for (int j = i + 1; j < len; j++)
        {
            if (s[i] == s[j])
            {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    for (int i = 0; i < len; i++)
    {
        print_vector(dp[i]);
    }
    return dp[0][len - 1];
}

/*
674. 最长连续递增序列
给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。

连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。
 */
int findLengthOfLCIS(vector<int> &nums)
{
    int len = nums.size();
    int count = 1;
    int ans = 1;
    for (int i = 0; i < len - 1; i++)
    {
        if (nums[i] < nums[i + 1])
        {
            count++;
        }
        else
        {
            count = 1;
        }

        ans = max(count, ans);
    }
    return ans;
}

/*
1143. 最长公共子序列
给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。
 */
int longestCommonSubsequence(string text1, string text2)
{
    return 1;
}

void test_all()
{

    // test_5();
    // test_516();
}

int main(int argc, char const *argv[])
{
    test_all();
    return 0;
}
