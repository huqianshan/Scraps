#include "helper.h"

/*
17. 电话号码的字母组合
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 */
vector<string> ret_words;
string words;
unordered_map<char, string> keyboard{
    {'1', ""},
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}};
void letterCore(string digits, int pos)
{
    if (pos >= digits.size())
    {
        ret_words.push_back(words);
        return;
    }
    //
    string button = keyboard[digits[pos]];
    int len = button.size();
    for (int i = 0; i < len; i++)
    {
        words.push_back(button[i]);
        letterCore(digits, pos + 1);
        words.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    letterCore(digits, 0);
    return ret_words;
}

/*
22. 括号生成
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 */
vector<string> ret_pair;
bool isValid(string s)
{
    int len = s.size();

    vector<char> stack;
    for (auto i : s)
    {
        if (i == '(' || i == '{' || i == '[')
        {
            stack.push_back(i);
            continue;
        }
        //'('与')'的ASCII值差1，'['与']'，'{'与'}'的ASCII值差2
        // 40 41 91 93 123 125
        else if (stack.size() == 0 || i - stack.back() <= 0 || (i - stack.back() > 2))
        {
            return false;
        }
        stack.pop_back();
    }

    return stack.size() ? false : true;
}
void parentThesisCore(int n, int leftPar, int rightPar, string parentthesis)
{
    if (leftPar + rightPar >= 2 * n)
    {
        if (leftPar == rightPar && isValid(parentthesis))
        {
            // cout << parentthesis << endl;
            ret_pair.push_back(parentthesis);
        }
        return;
    }

    if (leftPar < n)
    {
        parentThesisCore(n, leftPar + 1, rightPar, parentthesis + "(");
    }
    if (rightPar < n)
    {
        parentThesisCore(n, leftPar, rightPar + 1, parentthesis + ")");
    }
}
vector<string> generateParenthesis(int n)
{
    if (n < 1)
    {
        return {};
    }
    parentThesisCore(n, 1, 0, "(");
    return ret_pair;
}
/* 39. 组合总和
给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，
找出 candidates 中可以使数字和为目标数 target 的 所有不同组合 ，
并以列表形式返回。你可以按 任意顺序 返回这些组合。

candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。

对于给定的输入，保证和为 target 的不同组合数少于 150 个。 */
vector<vector<int>> ret_list;
void subSum(vector<int> candiates, vector<int> &tem, int pos, int diff)
{
    if (diff < 0)
    {
        return;
    }
    if (diff == 0)
    {
        ret_list.push_back(tem);
        return;
    }
    int len = candiates.size();
    for (int i = pos; i < len && diff - candiates[i] >= 0; i++) // 剪枝
    {
        tem.push_back(candiates[i]);
        subSum(candiates, tem, i, diff - candiates[i]);
        tem.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<int> tem;
    subSum(candidates, tem, 0, target);
    return ret_list;
}
/*
77. 组合
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。
 */
vector<vector<int>> arrs;
vector<int> tem;
void subCombint(int k, int begin, int end, int depth)
{
    if (depth == k)
    {
        arrs.push_back(tem);
        return;
    }
    for (int i = begin; i <= end - (k - tem.size()) + 1; i++)
    {
        tem.push_back(i);
        subCombint(k, i + 1, end, depth + 1);
        tem.pop_back();
    }
}
vector<vector<int>> combine(int n, int k)
{
    subCombint(k, 1, n, 0);
    return arrs;
}

/*
216. 组合总和 III
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：
所有数字都是正整数。
解集不能包含重复的组合。
 */
void subCombint(int k, int begin, int end, int depth, int target)
{
    int sum = accumulate(tem.begin(), tem.end(), 0);
    if (sum > target)
    {
        return;
    }
    if (depth == k && sum == target)
    {
        arrs.push_back(tem);
        return;
    }
    for (int i = begin; i <= end; i++)
    {
        tem.push_back(i);
        subCombint(k, i + 1, end, depth + 1, target);
        tem.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n)
{
    subCombint(k, 1, 9, 0, n);
    return arrs;
}

/* 79. 单词搜索
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。
如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，
其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
同一个单元格内的字母不允许被重复使用。 */
bool flag = false;
unordered_set<char> hashmap;
bool check(vector<vector<char>> &board, vector<vector<int>> &visited, int i, int j, string &s, int k)
{
    if (board[i][j] != s[k])
    {
        return false;
    }
    else if (k == s.length() - 1)
    {
        return true;
    }
    visited[i][j] = true;
    vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool result = false;
    for (const auto &dir : directions)
    {
        int newi = i + dir.first, newj = j + dir.second;
        if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size())
        {
            if (!visited[newi][newj])
            {
                bool flag = check(board, visited, newi, newj, s, k + 1);
                if (flag)
                {
                    result = true;
                    break;
                }
            }
        }
    }
    visited[i][j] = false;
    return result;
}

bool exist(vector<vector<char>> &board, string word)
{
    int h = board.size(), w = board[0].size();
    vector<vector<int>> visited(h, vector<int>(w));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            bool flag = check(board, visited, i, j, word, 0);
            if (flag)
            {
                return true;
            }
        }
    }
    return false;
}

void test_search()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    word = "SEE";
    print_expected(79, exist(board, word), true);
}
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

/*
494. 目标和
给你一个整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
 */
int ret_count = 0;
void subFind(vector<int> &nums, int pos, int sum)
{
    if (pos == nums.size())
    {
        if (sum == 0)
        {
            ret_count++;
        }
        return;
    }

    subFind(nums, pos + 1, sum - nums[pos]);
    subFind(nums, pos + 1, sum + nums[pos]);
}
int findTargetSumWays(vector<int> &nums, int target)
{
    subFind(nums, 0, target);
    return ret_count;
}
void test_all()
{

    /*    combinationSum3(4, 2);
       for (auto n : arrs)
       {
           print_vector(n);
       } */

    /*     string letters = "1";
        letterCombinations(letters);
        for (auto w : ret_words)
        {
            cout << w << endl;
        } */
    /* generateParenthesis(8);
    for (auto p : ret_pair)
    {
        cout << p << endl;
    } */

    // vector<int> nums = {2, 3, 6, 7};
    // int target = 7;
    // for (auto i : combinationSum(nums, target))
    // {
    //     print_vector(i);
    // }
    test_search();
}

int main(int argc, char const *argv[])
{
    /* code */
    test_all();

    cout << isValid("()()") << endl;
    return 0;
}
