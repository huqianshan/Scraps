#include "helper.h"

/*
42. 接雨水
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 */
int trap(vector<int> &height)
{
    stack<int> stk;
    int rain = 0;
    int len = height.size();
    for (int i = 0; i < len; i++)
    {
        while (!stk.empty() && height[i] > height[stk.top()])
        {
            int tem = stk.top();
            stk.pop();

            if (stk.empty())
            {
                break;
            }
            int left = stk.top();
            int curr_width = i - left - 1;
            int curr_hegith = min(height[left], height[i]) - height[tem];
            rain += (curr_hegith * curr_width);
        }
        stk.push(i);
    }
    return rain;
}
/*
150. 逆波兰表达式求值
根据 逆波兰表示法，求表达式的值。
有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
说明：
整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
 */
int evalRPN(vector<string> &tokens)
{
    stack<string> stk;
    string c1, c2;
    int tem = 0;
    for (auto t : tokens)
    {
        if (t != "+" && t != "-" && t != "*" && t != "/")
        {
            stk.push(t);
            continue;
        }
        c1 = stk.top();
        stk.pop();
        c2 = stk.top();
        stk.pop();
        if (t == "+")
        {
            tem = stoi(c1) + stoi(c2);
        }
        else if (t == "-")
        {
            tem = stoi(c2) - stoi(c1);
        }
        else if (t == "*")
        {
            tem = stoi(c1) * stoi(c2);
        }
        else if (t == "/")
        {
            tem = stoi(c2) / stoi(c1);
        }
        stk.push(to_string(tem));
        // cout << tem << endl;
    }

    return stoi(stk.top());
}
void test_polish()
{
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    print_expected(150, evalRPN(tokens), 9);

    tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    print_expected(150, evalRPN(tokens), 22);

    tokens = {"9", "3", "/"};
    print_expected(150, evalRPN(tokens), 3);
}
/*
232. 用栈实现队列
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
*/
class MyQueue
{
public:
    stack<int> input;
    stack<int> output;
    MyQueue()
    {
    }

    void push(int x)
    {
        input.push(x);
    }

    int pop()
    {
        int ret = -1;
        // 1. 检测output是否为空
        if (output.empty() == true)
        {
            // 2. 将input中数据迁移到output中
            while (input.empty() != true)
            {
                output.push(input.top());
                input.pop();
            }
        }
        // 3. 弹出output最高的
        ret = output.top();
        output.pop();
        return ret;
    }

    int peek()
    {
        int ret = pop();
        output.push(ret);
        return ret;
    }

    bool empty()
    {
        return input.empty() && output.empty();
    }
};

/*
225. 用队列实现栈
请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
 */
class MyStack
{
public:
    queue<int> stk;
    queue<int> bak;
    MyStack()
    {
    }

    void push(int x)
    {
        stk.push(x);
    }

    int pop()
    {
        while (stk.empty() != true && stk.size() != 1)
        {
            bak.push(stk.front());
            stk.pop();
        }
        int ret = stk.front();
        stk.pop();
        stk.swap(bak);
        return ret;
    }

    int top()
    {
        return stk.back();
    }

    bool empty()
    {
        return stk.empty();
    }
};

class MonoQueue
{
public:
    deque<int> que;
    void pop(int value)
    {
        if (que.empty() != true && que.front() == value)
        {
            que.pop_front();
        }
    }

    void push(int value)
    {
        while (que.empty() != true && value > que.back())
        {
            que.pop_back();
        }
        que.push_back(value);
    }

    int front()
    {
        return que.front();
    }
};

/*
239. 滑动窗口最大值
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。z
 */
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int len = nums.size();
    vector<int> ret(len - k + 1, 0);
    int pos = 0;
    MonoQueue que;

    for (int i = 0; i < k; i++)
    {
        que.push(nums[i]);
    }
    ret[pos++] = que.front();

    for (int i = k; i < len; i++)
    {
        que.pop(nums[i - k]);
        que.push(nums[i]);
        ret[pos++] = que.front();
    }
    return ret;
}

vector<int> maxSlidingWindow_ExcedTime(vector<int> &nums, int k)
{

    int len = nums.size();
    vector<int> ret(len - k + 1, 0);
    int pos = 0;
    MonoQueue que;

    for (int i = 0; i < k; i++)
    {
        que.push(nums[i]);
    }
    ret[pos++] = que.front();

    for (int i = k; i < len; i++)
    {
        que.pop(nums[i - k]);
        que.push(nums[i]);
        ret[pos++] = que.front();
    }
    return ret;
}

void test_max()
{
    string s = "[1,3,-1,-3,5,3,6,7]";
    vector<int> nums = stringToIntegerVector(s);
    int k = 3;
    print_vector(maxSlidingWindow(nums, k));

    nums = {1};
    k = 1;
    print_vector(maxSlidingWindow(nums, k));

    nums = {1, -1};
    k = 1;
    print_vector(maxSlidingWindow(nums, k));

    nums = {1, 3, 1, 2, 0, 5};
    k = 3;
    print_vector(maxSlidingWindow(nums, k)); // 3,3,2,5
}
static bool cmp(pair<int, int> &m, pair<int, int> &n)
{
    return m.second > n.second;
}

/*
347. 前 K 个高频元素
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
 */
vector<int> topKFrequent(vector<int> &nums, int k)
{
    // 优化： 无需为所有频率数组构建一个大顶堆
    // 构建一个大小为K的小顶堆，能够降低操作复杂度
    int len = nums.size();
    vector<int> ret(k, 0);
    unordered_map<int, int> hashmap;
    for (auto n : nums)
    {
        hashmap[n]++;
    }

    // less 默认为大顶堆
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    for (auto [item, count] : hashmap)
    { // 先做插入，再做比较
        if (que.size() < k)
        {
            que.emplace(count, item);
            continue;
        }
        if (que.top().first < count)
        {
            que.pop();
            que.emplace(count, item);
        }
    }

    for (int i = 0; i < k; i++)
    {
        // que.second 是元素，first是出现次数
        auto [count, item] = que.top();
        ret[i] = item;
        que.pop();
    }
    // printf("QueSize: %d \n", que.size());
    return ret;
}

void test_topK()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    print_vector(topKFrequent(nums, k));

    nums = {1};
    k = 1;
    print_vector(topKFrequent(nums, k));
}

/*
394. 字符串解码
给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
 */
string decodeString(string s)
{
    stack<char> stk_char;

    for (auto c : s)
    {
        if (c == ']')
        { // 出栈
            string tem;
            while (stk_char.top() != '[')
            {
                tem = stk_char.top() + tem;
                stk_char.pop();
            }
            stk_char.pop(); // 弹出'['
            string digit;
            while (!stk_char.empty() && isdigit(stk_char.top()))
            {
                digit = stk_char.top() + digit;
                stk_char.pop();
            }
            int num = stoi(digit);
            for (int i = 0; i < num; i++)
            {
                for (auto j : tem)
                {
                    stk_char.push(j);
                }
            }
        }
        else
        {
            stk_char.push(c);
        }
    }
    int len = stk_char.size();
    string ret(len, '0');
    for (int i = len - 1; i >= 0; i--)
    {
        ret[i] = stk_char.top();
        stk_char.pop();
    }
    return ret;
}
void test_decode()
{
    string s = "3[a]2[bc]";
    string ret_expected = "aaabcbc";
    print_expected(394, decodeString(s), ret_expected);

    s = "10[leetcode]";
    cout << decodeString(s) << endl;
}

/*
1047. 删除字符串中的所有相邻重复项
给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

在 S 上反复执行重复项删除操作，直到无法继续删除。

在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
 */
string removeDuplicates(string s)
{
    stack<char> stk;

    for (auto c : s)
    {
        if (stk.empty() != true && stk.top() == c)
        {
            stk.pop();
            continue;
        }
        stk.push(c);
    }
    int len = stk.size();
    string ret(len, 0);
    while (len > 0)
    {
        ret[len - 1] = stk.top();
        stk.pop();
        len--;
    }
    return ret;
}

void test_remove()
{
    string s = "abbaca";
    string expected = "ca";
    print_expected(1047, removeDuplicates(s), expected);
}

int main(int argc, char const *argv[])
{
    /* code */
    // printf("%d %d %d %d %d %d\n", '(', ')', '[', ']', '{', '}');

    // test_remove();

    // test_polish();

    // test_max();

    // test_topK();

    test_decode();

    char c = '1';
    // return 0 indicates true
    printf("%d %d %d %d \n", isdigit(c), islower('c'), isalpha('Z'), isupper('C'));

    string s(3, 'c');
    return 0;
}
