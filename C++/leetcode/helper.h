/**
 * @file helper.h
 * @author hjl-N501 (1196455147@qq.com)
 * @brief 头文件包含以及一些辅助函数
 * @version 0.1
 * @date 2022-03-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <algorithm>
#include <cassert>
#include <chrono>
#include <climits>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

/* Color for output */
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined(_WIN64)
// do nothing
#elif defined(__linux) || defined(__linux__) || defined(__unix) || defined(__unix__) || deined(__APPLE__)
// the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.
#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */
#endif

/* Definition for a binary tree node. */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* Definition for a multi tree node. */
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    ListNode(vector<int> &nums)
    {
    }
};

// typedef struct ListNode Node;

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch)
                                       { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch)
                        { return !isspace(ch); })
                    .base(),
                input.end());
}

vector<int> stringToIntegerVector(string input)
{
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim))
    {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode *stringToListNode(string input)
{
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode *dummyRoot = new ListNode(0);
    ListNode *ptr = dummyRoot;
    for (int item : list)
    {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

TreeNode *stringToTreeNode(string input)
{
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size())
    {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (true)
    {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null")
        {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null")
        {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string treeNodeToString(TreeNode *root)
{
    if (root == nullptr)
    {
        return "[]";
    }

    string output = "";
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        if (node == nullptr)
        {
            output += "null, ";
            continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

/*
****************************************************************
****************************************************************
*********** PRINT FUNCTION *************************************
****************************************************************
****************************************************************
*/
template <typename T>
void print_vector(const vector<T> &nums)
{
    cout << "[";
    for (auto i : nums)
    {
        cout << i << ",";
    }
    cout << "]" << endl;
}

template <typename T>
void print_queue(const T &q)
{ // NB: pass by value so the print uses a copy
    while (!q.empty())
    {
        std::cout << q.top() << ' ';
        q.pop();
    }
    std::cout << '\n';
}

void printf_node(ListNode *lt, bool simple)
{

    while (lt)
    {
        if (simple)
        {
            cout << lt->val;
            if (lt->next != nullptr)
            {
                cout << "->";
            }
        }
        else
        {

            cout << lt << " " << lt->val << " " << lt->next << " " << endl;
        }
        lt = lt->next;
    }
    cout << endl;
}

void printf_node(ListNode *lt)
{
    printf_node(lt, true);
}

template <typename T>
void print_expected(int num, T ret, T expected)
{
    cout << "LeetCode " << num << ": ";
    if (ret == expected)
    {
        cout << " Pass" << endl;
    }
    else
    {
        cout << " Fail" << endl;
    }
    cout << "    Return:   [" << ret << "];" << endl
         << "    Expected: [" << expected << "]; " << endl
         << endl;
}

template <typename T>
void print_expected(int num, const vector<T> &ret, const vector<T> &expected)
{
    cout << "LeetCode " << num << ": ";
    if (ret == expected)
    {
        cout << " Pass" << endl;
    }
    else
    {
        cout << " Fail" << endl;
    }
    cout << "    Return:   ";
    print_vector(ret);
    cout << "    Expected: ";
    print_vector(expected);
}

template <typename T>
void print_expected(T ret, T expected)
{
    print_expected(0, ret, expected);
}
/*
****************************************************************
****************************************************************
*********** COMPUTE/HELPER FUNCTION *************************************
****************************************************************
****************************************************************
*/
template <typename T>
vector<size_t> sort_indexes(const vector<T> &v)
{
    vector<size_t> idx(v.size());
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(),
         [&v](size_t i1, size_t i2)
         { return v[i1] < v[i2]; });
    return idx;
}

int lowbit(int x)
{
    return x & (-x);
}

int charToInt(char c)
{
    return (int)(c - '0');
}
char intToChar(int n)
{
    return (char)(n + '0');
}

bool isDigit(char c)
{
    if (c >= '0' && c <= '9')
    {
        return true;
    }
    return false;
}

/*
计算 begin 到end 之间区间和
左开右闭
 */
template <typename T>
T vector_sumrange(const vector<T> &arr, int begin, int end)
{
    int len = arr.size();
    T ret = 0;
    for (int i = begin; i < end; i++)
    {
        ret += arr[i];
    }
    return ret;
}
// boolg islower