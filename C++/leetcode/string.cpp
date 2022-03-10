#include "helper.h"

/* helper function */
void reverse(string &s, int start, int end)
{
    for (int i = start, j = end; i < j; i++, j--)
    {
        swap(s[i], s[j]);
    }
}

// 按顺序依次翻转每个word
void reverse_Words(string &s)
{
    int len = s.size();
    int left = 0;
    for (int right = 0; right < len; right++)
    {
        if (s[right] == ' ')
        {
            reverse(s, left, right - 1);
            left = right + 1;
        }
        else if (right == len - 1)
        {
            reverse(s, left, right);
        }
    }
}

/*
剑指 Offer 05. 替换空格
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
 */
std::size_t replace_all(std::string &inout, std::string_view what, std::string_view with)
{
    std::size_t count{};
    for (std::string::size_type pos{};
         inout.npos != (pos = inout.find(what.data(), pos, what.length()));
         pos += with.length(), ++count)
    {
        inout.replace(pos, what.length(), with.data(), with.length());
    }
    return count;
}

std::size_t remove_all(std::string &inout, std::string_view what)
{
    return replace_all(inout, what, "");
}
string replaceSpace(string s)
{
    // replace_all(s, " ", "%20");
    int count = 0; // 统计空格的个数
    int sOldSize = s.size();
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            count++;
        }
    }
    // 扩充字符串s的大小，也就是每个空格替换成"%20"之后的大小
    s.resize(s.size() + count * 2);
    int sNewSize = s.size();
    // 从后先前将空格替换为"%20"
    for (int i = sNewSize - 1, j = sOldSize - 1; j < i; i--, j--)
    {
        if (s[j] != ' ')
        {
            s[i] = s[j];
        }
        else
        {
            s[i] = '0';
            s[i - 1] = '2';
            s[i - 2] = '%';
            i -= 2;
        }
    }
    return s;
}

/*
剑指 Offer 58 - II. 左旋转字符串
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
 */
string reverseLeftWords(string s, int n)
{
    reverse(s.begin(), s.begin() + n);
    reverse(s.begin() + n, s.end());
    reverse(s.begin(), s.end());
    return s;
}
string reverseLeftWords2(string s, int n)
{
    string tem(n, ' ');
    for (int i = 0; i < n; i++)
    {
        tem[i] = s[i];
    }

    int len = s.size();
    for (int i = n; i < len; i++)
    {
        s[i - n] = s[i];
    }
    for (int i = 0; i < n; i++)
    {
        s[len - i - 1] = tem[n - i - 1];
    }
    return s;
}

void test_offer()
{
    string s = "a b c  d";
    // cout << replaceSpace(s) << endl;
    s = "abcdefg";
    int k = 2;
    string ret_expected = "cdefgab";
    print_expected(5, reverseLeftWords(s, k), ret_expected);

    s = "lrloseumgh";
    k = 6;
    ret_expected = "umghlrlose";
    print_expected(5, reverseLeftWords(s, k), ret_expected);
}

/*
3. 无重复字符的最长子串
https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 */
int lengthOfLongestSubstring(string s)
{
    int len = s.length();
    unordered_set<char> occ;
    int max_sub = 0;
    int tem = 0;
    int left = 0;

    for (int i = 0; i < len; i++)
    {
        if (occ.count(s[i]) == 0)
        { // 没找到
            occ.insert(s[i]);
            max_sub = max(max_sub, i - left + 1);
            continue;
        }

        while (s[left] != s[i])
        {
            occ.erase(s[left++]);
        }
        // set erase直接把对应重复key删除，需要保留，即如果擦除元素，直到重复的key.
        // 而left标识当前子串长度
        left++;
    }

    return max_sub;
}

int lengthOfLongestSubstring2(string s)
{
    // 哈希集合，记录每个字符是否出现过
    unordered_set<char> occ;
    int n = s.size();
    // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
    int rk = -1, ans = 0;
    // 枚举左指针的位置，初始值隐性地表示为 -1
    for (int i = 0; i < n; ++i)
    {
        if (i != 0)
        {
            // 左指针向右移动一格，移除一个字符
            occ.erase(s[i - 1]);
        }
        while (rk + 1 < n && !occ.count(s[rk + 1]))
        {
            // 不断地移动右指针
            occ.insert(s[rk + 1]);
            ++rk;
        }
        // 第 i 到 rk 个字符是一个极长的无重复字符子串
        ans = max(ans, rk - i + 1);
    }
    return ans;
}

/*
*********************************
*****        回文子串       *****
*********************************
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
/*
5. 最长回文子串
给你一个字符串 s，找到 s 中最长的回文子串。

1. 如果i=0,
2. 如果i!=0, if i-1 == i+1 or i-1 == i or i+1 ==i, append
 */
string longestPalindrome(string s)
{
    int len = s.size();
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

/*
125. 验证回文串
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。
 */
bool isPalindrome(string s)
{
    int len = s.size();
    int left = 0;
    int right = len - 1;
    while (left < right)
    {
        while (left < right && !isalnum(s[left]))
        {
            left++;
        }
        while (left < right && !isalnum(s[right]))
        {
            right--;
        }
        if (left < right)
        {
            if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
            left++;
            right--;
            printf("%c %c\n", s[left], s[right]);
        }
    }
    return true;
}

/*647. 回文子串
给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。

回文字符串 是正着读和倒过来读一样的字符串。

子字符串 是字符串中的由连续字符组成的一个序列。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

方法一: 暴力 No
方法二： dp
方法三： 中心拓展

*/
int countSubstrings(string s)
{
    int len = s.size();
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int start = i;
            int end = i + j;
            while (start >= 0 && end < len && s[start] == s[end])
            {
                start--;
                end++;
                count++;
            }
        }
    }
    return count;
}

int countSubstrings_dp(string s)
{
    int len = s.size();
    vector<vector<int>> dp(len, vector<int>(len, 0));
    int count = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        for (int j = i; j < len; j++)
        {
            if (s[i] == s[j])
            {
                if (j - i <= 1)
                {
                    count++;
                    dp[i][j] = 1;
                }
                else if (dp[i + 1][j - 1])
                {
                    count++;
                    dp[i][j] = 1;
                }
            }
        }
    }
    return count;
}

bool checkPalindrome(string s, int start, int end)
{
    for (; start < end; start++, end--)
    {
        if (s[start] != s[end])
        {
            return false;
        }
    }
    return true;
}
/*
680. 验证回文字符串 Ⅱ
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串

s思路： 两次遍历，涉及两个变量，使用for-loop更优一点
 */
bool validPalindrome(string s)
{
    int len = s.size();
    int left = 0;
    int right = len - 1;
    for (; left < right && s[left] == s[right]; left++, right--)
    {
    }
    return left >= right || checkPalindrome(s, left + 1, right) || checkPalindrome(s, left, right--);
}
void test_palindrome()
{
    string s = "test test";
    print_expected(33, isPalindrome(s), false);
}

vector<int> computePrefix(const string needle)
{
    int s_len = needle.size();
    vector<int> pre(s_len, 0);
    int j = 0;
    for (int i = 1; i < s_len; i++)
    {
        while (j > 0 && needle[i] != needle[j])
        {
            j = pre[j - 1];
        }
        if (needle[i] == needle[j])
        {
            j++;
        }
        pre[i] = j;
    }
    return pre;
}

/*
28. 实现 strStr()
实现 strStr() 函数。

给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。

说明：
当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。
 */
int strStr_KMP(string haystack, string needle)
{
    int target_len = haystack.size();
    int pattern_len = needle.size();
    if (pattern_len == 0)
    {
        return 0;
    }

    vector<int> pre = computePrefix(needle);
    int j = 0;
    for (int i = 0; i < target_len; i++)
    {
        while (j > 0 && haystack[i] != needle[j])
        {
            j = pre[j - 1];
        }

        if (haystack[i] == needle[j])
        {
            j++;
        }
        if (j == pattern_len)
        {
            return (i - pattern_len + 1);
        }
    }
    return -1;
}

int strStr_API(string haystack, string needle)
{
    return haystack.find(needle);
}

int strStr(string haystack, string needle)
{
    return strStr_KMP(haystack, needle);
}

/*
459. 重复的子字符串
给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。
给定的字符串只含有小写英文字母，并且长度不超过10000。
 */
bool repeatedSubstringPattern(string s)
{
    int len = s.size();
    if (len == 0)
    {
        return false;
    }

    vector<int> pre = computePrefix(s);
    if (pre[len - 1] != 0 && (len - (pre[len - 1])) == 0)
    {
        return true;
    }

    return false;
}

/*
686. 重复叠加字符串匹配
给定两个字符串 a 和 b，寻找重复叠加字符串 a 的最小次数，使得字符串 b 成为叠加后的字符串 a 的子串，
如果不存在则返回 -1。

注意：字符串 "abc" 重复叠加 0 次是 ""，重复叠加 1 次是 "abc"，重复叠加 2 次是 "abcabc"。
 */

int repeatedStringMatch(string a, string b)
{
    int an = a.size(), bn = b.size();
    int index = strStr(a, b);
    if (index == -1)
    {
        return -1;
    }
    if (an - index >= bn)
    {
        return 1;
    }
    return (bn + index - an - 1) / an + 2;
}

void test_match()
{
    string target = "hello";
    string pattern = "ll";
    int ret_expected = 2;
    print_expected(28, strStr(target, pattern), ret_expected);

    target = "";
    pattern = "";
    ret_expected = 0;
    print_expected(28, strStr(target, pattern), ret_expected);

    target = "bacbababaabcbab";
    pattern = "ababaca";
    ret_expected = -1;
    print_expected(28, strStr(target, pattern), ret_expected);

    target = "abcde";
    pattern = "cde";
    ret_expected = 2;
    print_expected(28, strStr(target, pattern), ret_expected);

    target = "abcdabcdabcd";
    print_vector(computePrefix(target));
    target = "ababcababc";
    print_vector(computePrefix(target));
    target = "abcabdabeabc";
    print_vector(computePrefix(target));
}

/*
*********************************
*****       Agrams          *****
*********************************
*/

/*
49. 字母异位词分组
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。
 */
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mp;
    for (string &str : strs)
    {
        string key = str;
        sort(key.begin(), key.end());
        mp[key].emplace_back(str);
    }
    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        ans.emplace_back(it->second);
    }
    return ans;
}
bool isAnagram(string s, string t);
vector<vector<string>> groupAnagrams2(vector<string> &strs)
{
    vector<vector<string>> ans;
    int len = strs.size();

    vector<string> tem;
    for (int i = 0; i < len; i++)
    {
        vector<string>().swap(tem);
        if (strs[i] != "A")
        {
            tem.push_back(strs[i]);
        }
        for (int j = i + 1; j < len; j++)
        {
            if (strs[j] != "A" && isAnagram(strs[i], strs[j]))
            {
                tem.push_back(strs[j]);
                strs[j] = "A";
            }
        }
        if (tem.size() != 0)
        {
            ans.push_back(tem);
        }
    }
    return ans;
}

/*
242. 有效的字母异位词
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词
*/
bool isAnagram(string s, string t)
{
    unordered_map<char, int> occ;
    for (auto c : t)
    {
        occ[c]++;
    }

    int len = s.size();
    int count = t.size();
    if (len != count)
        return false;
    for (size_t i = 0; i < len; i++)
    {
        if (occ.find(s[i]) != occ.end())
        {
            if (occ[s[i]] != 0)
            {
                count--;
            }
            occ[s[i]]--;
        }
    }
    return count == 0;
}

/*
438. 找到字符串中所有字母异位词
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

异位词 指由相同字母重排列形成的字符串（包括相同的字符串）
*/
vector<int> findAnagrams1(string s, string p)
{
    unordered_map<char, int> occ;
    for (auto c : p)
    {
        occ[c]++;
    }

    int left = 0, right = 0;
    vector<int> ans;
    int slen = s.size();
    int plen = p.size();
    int window = 0;
    int count = plen;
    while (right < slen)
    { // 1.扩大窗口
        if (occ[s[right]] > 0)
        {
            count--;
        }
        occ[s[right]]--;

        if (count == 0)
        {
            while (left < right && occ[s[left]] < 0)
            { // 2. 缩短滑动窗口
                occ[s[left++]]++;
            }
            // 3. 更新答案
            if ((right - left + 1) == plen)
            {
                ans.push_back(left);
            }
            // 4.去除一个答案
            occ[s[left]]++;
            left++;
            count++;
        }
        right++;
    }
    return ans;
}

vector<int> findAnagrams(string s, string p)
{
    int sLen = s.size(), pLen = p.size();

    if (sLen < pLen)
    {
        return vector<int>();
    }

    vector<int> ans;
    vector<int> sCount(26);
    vector<int> pCount(26);
    for (int i = 0; i < pLen; ++i)
    {
        ++sCount[s[i] - 'a'];
        ++pCount[p[i] - 'a'];
    }

    if (sCount == pCount)
    {
        ans.emplace_back(0);
    }

    for (int i = 0; i < sLen - pLen; ++i)
    {
        --sCount[s[i] - 'a'];
        ++sCount[s[i + pLen] - 'a'];

        if (sCount == pCount)
        {
            ans.emplace_back(i + 1);
        }
    }

    return ans;
}
/*
567. 字符串的排列
给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。如果是，返回 true ；否则，返回 false 。

换句话说，s1 的排列之一是 s2 的 子串 。

优化思路： 不需要比较整个子串，根据一进一出；只需要比较增量值
 */
bool checkInclusion(string s1, string s2)
{
    // unordered_map<char, int> occ1;
    vector<int> occ1(26, 0);
    for (auto c : s1)
    {
        occ1[c - 'a']++;
    }

    int alen = s1.size();
    int blen = s2.size();
    if (alen > blen)
    {
        return false;
    }
    // unordered_map<char, int> occ(occ1);
    vector<int> occ(occ1);
    for (int i = 0; i <= blen - alen; i++)
    {

        int count = 0;
        for (int j = 0; j < alen; j++)
        { // 第一个不匹配就直接跳过
            if (occ[s2[i + j]] == 0)
            {
                break;
            }
            else if (occ[s2[i + j]] != 0)
            { // 如果重复char 需要比较多次
                count++;
                occ[s2[i + j]]--;
            }
        }
        if (count == alen)
        {
            return true;
        }
        else
        {
            occ = occ1;
        }
    }
    return false;
}

bool checkInclusion2(string s1, string s2)
{
    string base = s1;
    sort(base.begin(), base.end());

    int blen = s2.size();
    int alen = s1.size();
    for (int i = 0; i < blen - alen; i++)
    {
        string target = s2.substr(i, alen);
        sort(target.begin(), target.end());
        if (target == base)
        {
            return true;
        }
    }
    return false;
}

bool checkInclusion3(string s1, string s2)
{
    unordered_map<char, int> occ1;
    for (auto c : s1)
    {
        occ1[c]++;
    }

    int alen = s1.size();
    int blen = s2.size();
    if (alen != blen)
    {
        return false;
    }
    unordered_map<char, int> occ(occ1);
    for (int i = 0; i <= blen - alen; i++)
    {

        int count = 0;

        if (occ.find(s2[i]) == occ.end())
        { // 第一个不匹配就直接跳过
            continue;
        }
        for (int j = 0; j < alen; j++)
        {
            if (occ.find(s2[i + j]) == occ.end())
            {
                break;
            }
            else if (occ[s2[i + j]] != 0)
            { // 如果重复char 需要比较多次
                count++;
                occ[s2[i + j]]--;
            }
        }
        if (count == alen)
        {
            return true;
        }
        else
        {
            occ = occ1;
        }
    }
    return false;
}

bool checkInclusion4(string s1, string s2)
{
    int n = s1.length(), m = s2.length();
    if (n > m)
    {
        return false;
    }
    vector<int> cnt1(26), cnt2(26);
    for (int i = 0; i < n; ++i)
    {
        ++cnt1[s1[i] - 'a'];
        ++cnt2[s2[i] - 'a'];
    }
    if (cnt1 == cnt2)
    {
        return true;
    }
    for (int i = n; i < m; ++i)
    {
        ++cnt2[s2[i] - 'a'];
        --cnt2[s2[i - n] - 'a'];
        if (cnt1 == cnt2)
        {
            return true;
        }
    }
    return false;
}

/*
76. 最小覆盖子串
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。


注意：

对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。
 */

/*
 1. 找到包含目标字串的最小子串
 2. 去除第一个目标字串元素，找到下一个目标字串元素，更新长度
 3. 直到找到字符串末尾
 */
string minWindow(string s, string t)
{
    int len = s.size();
    int count = t.size();

    unordered_map<char, int> occ;
    for (auto c : t)
    {
        occ[c]++;
    }

    int left = 0;
    int right = 0;
    int max_len = INT_MAX;
    int start = 0;

    while (right < len)
    {
        if (occ[s[right]] > 0)
        {
            count--;
        }
        occ[s[right]]--;

        if (count == 0)
        {
            while (left < right && occ[s[left]] < 0)
            { // 缩短滑动窗口
                occ[s[left++]]++;
            }
            if (right - left + 1 < max_len)
            {
                // 更新返回值
                max_len = right - left + 1;
                start = left;
            }
            // 去除一个目标元素，开启新的查找
            occ[s[left]]++;
            left++;
            count++;
        }
        right++;
    }
    return max_len == INT_MAX ? string() : s.substr(start, max_len);
}
void test_minWindow_76()
{
    string s = "cbaebabacd";
    string t = "abc";
    // cout << countSubstrings(t) << endl;
    /*    print_vector(findAnagrams(s, t));
       s = "abab";
       t = "ab";
       print_vector(findAnagrams(s, t));
       s = "baa";
       t = "aa";
       print_vector(findAnagrams(s, t));
       s = "abaacbabc";
       t = "abc";
       print_vector(findAnagrams(s, t));
       // cout << countSubstrings(t) << endl; */
}
/*
151. 翻转字符串里的单词
给你一个字符串 s ，逐个翻转字符串中的所有 单词 。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

请你返回一个翻转 s 中单词顺序并用单个空格相连的字符串。

说明：

输入字符串 s 可以在前面、后面或者单词间包含多余的空格。
翻转后单词间应当仅用一个空格分隔。
翻转后的字符串中不应包含额外的空格。
 */
string reverseWords(string s)
{
    // 1.去除重复空格,开始处空格，结尾处空格
    while (replace_all(s, "  ", " ") != 0)
    {
    }
    if (s[s.size() - 1] == ' ')
    {
        s.erase(s.size() - 1, 1);
    }
    if (s[0] == ' ')
    {
        s.erase(0, 1);
    }

    int len = s.size() - 1;
    reverse(s, 0, len);

    reverse_Words(s);

    return s;
}
/*
344. 反转字符串
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
https://leetcode-cn.com/problems/reverse-string/
 */
void reverseString(vector<char> &s)
{
    int len = s.size();
    for (int left = 0, right = len - 1; left < right; left++, right--)
    {
        swap(s[left], s[right]);
    }
}

/*
541. 反转字符串 II
给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样
https://leetcode-cn.com/problems/reverse-string-ii/
 */
string reverseStr(string s, int k)
{
    int len = s.size();
    for (int i = 0; i < len; i += 2 * k)
    {
        // 1. 每隔 2k 个字符的前 k 个字符进行反转
        // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
        if (i + k <= len)
        {
            reverse(s, i, i + k - 1);
            continue;
        }
        // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
        reverse(s, i, len - 1);
    }
    return s;
}
/*
557. 反转字符串中的单词 III
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
示例：

输入："Let's take LeetCode contest"
输出："s'teL ekat edoCteeL tsetnoc"
 
提示：
在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
*/
/* string reverseWords(string s)
{
    int len = s.size();
    int left = 0;
    for (int right = 0; right < len; right++)
    {
        if (s[right] == ' ')
        {
            reverse(s, left, right - 1);
            left = right + 1;
        }
        else if (right == len - 1)
        {
            reverse(s, left, right);
        }
    }
    return s;
} */

string reverseWords3(string s)
{
    int l = 0;
    int r = 0;

    // string ans(s);
    int len = s.length();

    while (l <= len)
    {
        while (s[r] != ' ' && s[r] != '\0')
        {
            r++;
        }
        r++;

        for (size_t j = 0; j < (r - l - 1); j++)
        {
            s[l + j] = s[r - j - 2];
        }

        l = r;
    }
    return s;
}

void test_reverse()
{
    string s = "Let's take LeetCode contest";
    string ret_expected = "s'teL ekat edoCteeL tsetnoc";
    // print_expected(557, reverseWords(s), ret_expected);

    s = "the sky is blue";
    ret_expected = "blue is sky the";
    print_expected(151, reverseWords(s), ret_expected);

    s = "  hello world  ";
    ret_expected = "world hello";
    print_expected(151, reverseWords(s), ret_expected);

    s = "a good   example";
    ret_expected = "example good a";
    print_expected(151, reverseWords(s), ret_expected);

    s = "  Bob    Loves  Alice   ";
    ret_expected = "Alice Loves Bob";
    print_expected(151, reverseWords(s), ret_expected);

    s = " Alice does not even like bob ";
    ret_expected = "bob like even not does Alice";
    print_expected(151, reverseWords(s), ret_expected);
}
/*
*********************************
*****  big Int String       *****
*********************************
*/
/*
    计算 m mm mmm ，共n次之和
 */
string cal_arr(int m, int n)
{
    int base = 10;
    int cur = 0;
    int plus = 0;
    string ret;
    while (n != 0)
    {
        cur = n * m + plus;
        plus = cur / base;
        ret.push_back('0' + cur % 10);
        n--;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

/*
415. 字符串相加
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。

你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。
 */
string addStrings(string num1, string num2)
{
    string ret;
    int len1 = num1.size() - 1;
    int len2 = num2.size() - 1;
    int tem = 0;
    int carry = 0;
    int base = 10;
    while (len1 >= 0 || len2 >= 0 || carry > 0)
    {
        int x = (len1 >= 0) ? num1[len1] - '0' : 0;
        int y = (len2 >= 0) ? num2[len2] - '0' : 0;
        tem = x + y + carry;
        carry = tem / base;
        // printf("%d %d\n", x, y);
        ret.push_back(tem % base + '0');
        len1--;
        len2--;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

/*
445. 两数相加 II
给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 */
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    stack<int> s1, s2;
    while (l1)
    {
        s1.push(l1->val);
        l1 = l1->next;
    }
    while (l2)
    {
        s2.push(l2->val);
        l2 = l2->next;
    }
    int carry = 0;
    ListNode *ans = nullptr;
    while (!s1.empty() or !s2.empty() or carry != 0)
    {
        int a = s1.empty() ? 0 : s1.top();
        int b = s2.empty() ? 0 : s2.top();
        if (!s1.empty())
            s1.pop();
        if (!s2.empty())
            s2.pop();
        int cur = a + b + carry;
        carry = cur / 10;
        cur %= 10;
        auto curnode = new ListNode(cur);
        curnode->next = ans;
        ans = curnode;
    }
    return ans;
}

// k is a char
string single_multiply(char k, string nums)
{
    int base = 10;
    int cur = 0;
    int carry = 0;
    int len = nums.size() - 1;
    int x = k - '0'; // 转换为int
    string ret;
    while (len >= 0 || carry != 0)
    {
        int tem = (len >= 0) ? nums[len] - '0' : 0;
        cur = x * tem + carry;
        carry = cur / base;
        ret.push_back(cur % base + '0');
        len--;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

/*
43. 字符串相乘
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。

方法一： 直接模拟
方法二： 构造数组，填充对应位
方法三： 傅里叶变换 卷积
 */
string multiply(string num1, string num2)
{
    if (num1[0] == '0' || num2[0] == '0')
    {
        return {'0'};
    }
    string ret;
    int len1 = num1.size() - 1;
    int len2 = num2.size() - 1;
    for (int i = len1; i >= 0; i--)
    {
        string tem = single_multiply(num1[i], num2);
        for (int j = i; j < len1; j++)
        {
            tem.push_back('0');
        }
        // cout << "" << tem << "" << endl;
        ret = addStrings(tem, ret);
    }
    return ret;
}

void test_bigint()
{
    string a = "123";
    string b = "111";
    string ret_expected = "444";
    print_expected(multiply(a, b), ret_expected);

    a = "9";
    b = "111";
    ret_expected = "9";
    print_expected(multiply(a, b), ret_expected);

    a = "0";
    b = "9999";
    ret_expected = "10008";
    print_expected(multiply(a, b), ret_expected);

    a = "9";
    b = "123";
    ret_expected = "132";
    print_expected(multiply(a, b), ret_expected);

    cout << "" << single_multiply(a[0], b) << "" << endl;
}
int compareVersion(string version1, string version2)
{
    int left = 0;
    int right = 0;
    int len1 = version1.size();
    int len2 = version2.size();
    while (left < len1 || right < len2)
    {
        int x = 0;
        while (left < len1 && version1[left] != '.')
        {
            x = x * 10 + (version1[left++] - '0');
        }
        left++;
        int y = 0;
        while (right < len2 && version2[right] != '.')
        {
            y = y * 10 + (version2[right++] - '0');
        }
        right++;
        if (x == y)
        {
            continue;
        }
        else
        {
            // cout<<x<<" "<<y<<endl;
            return (x < y) ? -1 : 1;
        }
    }
    return 0;
}

/*
709. 转换成小写字母
给你一个字符串 s ，将该字符串中的大写字母转换成相同的小写字母，返回新的字符串。
 */
string toLowerCase(string s)
{
    for (auto &i : s)
    {
        if (i <= 'Z' && i >= 'A')
        {
            i += 32;
        }
    }
    return s;
}

void test_all()
{
    // test_offer();
    // test_reverse();
    // test_match();
    // test_bigint();
    test_palindrome();
}

int main(int argc, char const *argv[])
{
    test_all();
    /* string s = "123456";
    cout << "" << s.substr(1, 3) << "" << endl; */
    cout << "String Test"
         << " Finished" << endl;
    return 0;
}
