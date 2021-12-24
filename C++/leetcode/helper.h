#include <algorithm>
#include <cassert>
#include <chrono>
#include <climits>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

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
        // ListNode nd(i);
        // for (auto i : nums)
        // {
        // }
    }
};

typedef struct ListNode Node;

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

/*

****************************************************************
****************************************************************
*********** PRINT FUNCTION *************************************
****************************************************************
****************************************************************
 */
template <typename T>
void print_vector(vector<T> nums)
{
    cout << "[";
    for (auto i : nums)
    {
        cout << i << ",";
    }
    cout << "]" << endl;
}

template <typename T>
void print_queue(T q)
{ // NB: pass by value so the print uses a copy
    while (!q.empty())
    {
        std::cout << q.top() << ' ';
        q.pop();
    }
    std::cout << '\n';
}

void printf_node(Node *lt, bool simple)
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

void printf_node(Node *lt)
{
    printf_node(lt, true);
}

template <typename T>
void print_expected(int num, T ret, T expected)
{
    cout << "LeetCode " << num << ": Return: " << ret << " Expected: " << expected;
    if (ret == expected)
    {
        cout << " Pass" << endl;
    }
    else
    {
        cout << " Fail" << endl;
    }
}

template <typename T>
void print_expected(T ret, T expected)
{
    cout << "Return: " << ret << " Expected: " << expected;
    if (ret == expected)
    {
        cout << " Pass" << endl;
    }
    else
    {
        cout << " Fail" << endl;
    }
}

template <typename T>
vector<size_t> sort_indexes(vector<T> &v)
{
    vector<size_t> idx(v.size());
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(),
         [&v](size_t i1, size_t i2)
         { return v[i1] < v[i2]; });
    return idx;
}