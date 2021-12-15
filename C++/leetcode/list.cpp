#include <iostream>
#include <stack>
#include <vector>

using namespace std;

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
        for (auto i : nums)
        {
        }
    }
};

/*
offer22
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。

例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。

链接：https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof
*/
ListNode *getKthFromEnd(ListNode *head, int k)
{
    ListNode *p1 = head;
    ListNode *p2 = head;
    int i = 1;

    while (p2 != nullptr && i <= k)
    {
        p2 = p2->next;
        i += 1;
    }

    while (p2 != nullptr && p1 != nullptr)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}

ListNode *reverseList(ListNode *head)
{
    ListNode *pre = nullptr;
    ListNode *cur = head;
    ListNode *suc = nullptr;

    while (cur)
    {
        suc = cur->next;
        cur->next = pre;
        pre = cur;
        cur = suc;
    }
    return pre;
}

ListNode *reverseList_recur(ListNode *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    ListNode *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr; // 确保首节点，被置为空，在下一次递归返回时，被上面一条语句修改
    return newHead;
}

typedef struct ListNode Node;
void printf_node(Node *lt)
{
    while (lt)
    {
        cout << lt << " " << lt->val << " " << lt->next << " " << endl;
        lt = lt->next;
    }
    cout << endl;
}

void test_init(void)
{
    int a;
    char c;
    char d = 0;
    printf("%x  %x\n", a, c);
}

Node *copyRandomList(Node *head)
{
    if (!head)
    {
        return NULL;
    }
    Node *raw_head = head;
    Node *tem_node = NULL;
    Node *new_list = NULL;
    // copy node in list
    while (head)
    {
        tem_node = new Node(head->val);
        tem_node->next = head->next;
        head->next = tem_node;
        // iter to next raw_list node
        head = tem_node->next;
    }
    //printf_node(raw_head);
    head = raw_head;

    // change random pointer in new_list
    while (head)
    {
        /*   new_list = head->next;
        if (head->random)
        {
            new_list->random = head->random->next;
        }
        head = new_list->next; */
    }
    //printf_node(raw_head);
    head = raw_head;
    tem_node = head->next;
    while (head)
    {
        new_list = head->next;
        head->next = new_list->next;
        head = head->next;
        if (head)
        {
            new_list->next = head->next;
        }
    }

    /*     head=raw_head;
    tem_node=head->next;
    head->next=tem_node->next;
    head=head->next;
    while(head){
        new_list=head->next;
        head->next=new_list->next;
    } */
    //printf_node(raw_head->next);
    return tem_node;
}

//https : //leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int n1 = l1 ? l1->val : 0;
    int n2 = l2 ? l2->val : 0;
    int sum = n1 + n2;
    int carry = sum / 10;
    ListNode *tail = new ListNode(sum % 10);
    ListNode *head = tail;
    l1 = l1 ? l1->next : l1;
    l2 = l2 ? l2->next : l2;

    while (l1 || l2)
    {
        n1 = l1 ? l1->val : 0;
        n2 = l2 ? l2->val : 0;
        sum = n1 + n2 + carry;

        tail->next = new ListNode(sum % 10);
        tail = tail->next;
        carry = sum / 10;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    if (carry > 0)
    {
        tail->next = new ListNode(carry);
    }
    return head;
}

/* 
234. 回文链表
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
 */
bool isPalindrome(ListNode *head)
{
    vector<int> stk;

    ListNode *tem(head);
    while (tem != nullptr)
    {
        stk.push_back(tem->val);
        tem = tem->next;
    }

    int i = 0;
    int j = stk.size();
    while (i < j)
    {
        if (stk[i] != stk[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main()
{
    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(2);
    Node *d = new Node(1);
    // Node *e = new Node(1);

    a->next = b;
    b->next = c;
    c->next = d;
    // d->next = e;
    printf_node(a);

 
}