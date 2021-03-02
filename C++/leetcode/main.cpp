#include <iostream>

using namespace std;

typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode *next) : val(x), next(next){};
    *
} ListNode;

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int n1 = l1 ? l1->val : 0;
    int n2 = l2 ? l2->val : 0;
    int sum = n1 + n2;
    int carry = sum / 10;
    ListNode *tail = new ListNode(sum % 10);
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

int main()
{
}