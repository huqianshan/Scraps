#include <iostream>

using namespace std;

typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode *next) : val(x), next(next){};
} ListNode;

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

//138  复制带随机指针的链表

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
void printf_node(Node *lt)
{
    while (lt)
    {
        cout << lt << " " << lt->val << " " << lt->next << " " << lt->random << endl;
        lt = lt->next;
    }
    cout << endl;
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
        new_list = head->next;
        if (head->random)
        {
            new_list->random = head->random->next;
        }
        head = new_list->next;
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

    b->random = a;
    c->random = e;
    d->random = c;
    e->random = a;
    Node *ret = copyRandomList(a);
    /*     free(a);
    free(b);
    free(c);
    free(d);
    free(e); */

    printf_node(a);
    printf_node(ret);
}