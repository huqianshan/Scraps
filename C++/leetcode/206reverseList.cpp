#include <iostream>

using namespace std;

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    head->next = nullptr;
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
int main()
{
    Node *a = new Node(7);
    Node *b = new Node(13);
    Node *c = new Node(11);
    Node *d = new Node(10);
    Node *e = new Node(1);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    printf_node(a);
    printf_node(reverseList(a));

    printf_node(reverseList_recur(e));
}