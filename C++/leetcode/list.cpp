#include "helper.h"

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
/*
19. 删除链表的倒数第 N 个结点
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 */
ListNode *removeNthFromEnd(ListNode *head, int n)
{

    ListNode *dummy = new ListNode(0, head);
    ListNode *first = head;
    ListNode *second = dummy;
    for (int i = 0; i < n; ++i)
    {
        first = first->next;
    }
    while (first)
    {
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    ListNode *ans = dummy->next;
    delete dummy;
    return ans;
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
    // printf_node(raw_head);
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
    // printf_node(raw_head);
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
    // printf_node(raw_head->next);
    return tem_node;
}

// https : //leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/

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
141. 环形链表
给你一个链表的头节点 head ，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

如果链表中存在环，则返回 true 。 否则，返回 false 。
 */
bool hasCycle(ListNode *head)
{
    ListNode *left = head;
    ListNode *right = (head) ? head->next : head;

    int lnum = 0;
    int rnum = 0;

    while (left && right)
    {
        if (left == right)
        {
            cout << lnum << " " << rnum << endl;
            return true;
        }
        left = left->next;
        lnum++;
        if (right->next == nullptr)
        {
            break;
        }
        rnum++;
        right = right->next->next;
    }
    return false;
}

/*
142. 环形链表 II
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

不允许修改 链表。

 */
ListNode *detectCycle(ListNode *head)
{ //如果可以修改链表呢？ 将访问过的值置为INT_MAX, 再次访问就是环开始的结点

    /*     ListNode *left = head;
        while (left)
        {
            if (left->val == INT_MAX)
            {
                return left;
            }
            left->val = INT_MAX;
            left = left->next;
        }
        return nullptr; */
    ListNode *slow = head, *fast = head;
    while (fast != nullptr)
    {
        slow = slow->next;
        if (fast->next == nullptr)
        {
            return nullptr;
        }
        fast = fast->next->next;
        if (fast == slow)
        {
            ListNode *ptr = head;
            while (ptr != slow)
            {
                ptr = ptr->next;
                slow = slow->next;
            }
            return ptr;
        }
    }
    return nullptr;
}

/*
146. LRU 缓存机制
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
实现 LRUCache 类：

LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。


进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作
 */
class LRUCache
{
    typedef struct Entry
    {
        int k;
        int v;
        Entry *next;
        Entry *prev;
        Entry() : k(0), v(0), next(nullptr), prev(nullptr) {}
        Entry(int key, int value) : k(key), v(value), next(nullptr), prev(nullptr) {}
        Entry(int key, int value, Entry *n) : k(key), v(value), next(n), prev(nullptr) {}
    } Entry;

    Entry *dummy_lru_list = new Entry(INT_MIN, INT_MIN);
    Entry *tail_lru_list = new Entry(INT_MAX, INT_MAX);
    unordered_map<int, Entry *> hashmap;
    int cap = 0;
    int len = 0;

public:
    LRUCache(int capacity)
    {
        cap = capacity;
        len = 0;
        hashmap.reserve(capacity);
        dummy_lru_list->next = tail_lru_list;
        tail_lru_list->prev = dummy_lru_list;
    }

    Entry *delete_node(Entry *cur)
    {
        Entry *pre = cur->prev;
        Entry *nxt = cur->next;
        // 从原地方删除
        pre->next = nxt;
        nxt->prev = pre;
        return cur;
    }

    Entry *add_head(Entry *cur)
    {
        // 加入头部
        cur->next = dummy_lru_list->next;
        dummy_lru_list->next->prev = cur;

        dummy_lru_list->next = cur;
        cur->prev = dummy_lru_list;
        return cur;
    }

    int get(int key)
    {
        // 查找通过hashmap
        if (hashmap.find(key) != hashmap.end())
        {
            // 获得链表结点
            Entry *cur = hashmap[key];
            cur = delete_node(cur);
            cur = add_head(cur);
            return cur->v;
        }
        return -1;
    }

    void put(int key, int value)
    {
        Entry *cur = nullptr;
        if (hashmap.find(key) == hashmap.end())
        { // 没找到目标结点,
            if (len < cap)
            { // 1. 容量够，可以继续插入
                cur = new Entry(key, value);
                cur = add_head(cur);
                hashmap[cur->k] = cur;
                len++;
                return;
            }
            // 2. 容量不够且没找到 找末尾结点淘汰, 暂存末尾结点
            cur = tail_lru_list->prev;
            hashmap.erase(cur->k);
            cur->k = key;
            hashmap[cur->k] = cur; // 更新
        }
        else
        {
            // 3. 找到目标结点 需要挪到首位
            cur = hashmap[key];
        }

        // 如果是3 需要update; 如果是2 需要赋予新值
        cur->v = value;
        cur = delete_node(cur);
        cur = add_head(cur);
    }
};

/*

147. 对链表进行插入排序
对链表进行插入排序。


插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。
 */
ListNode *insertionSortList(ListNode *head)
{
    if (head == nullptr)
    {
        return head;
    }
    ListNode tem = ListNode(0, head);
    ListNode *dummyHead = &tem;
    ListNode *lastSorted = head;
    ListNode *curr = head->next;
    ListNode *prev = dummyHead;
    int key = 0;

    while (curr != nullptr)
    {
        if (lastSorted->val <= curr->val)
        {
            lastSorted = lastSorted->next;
        }
        else
        {
            if (curr->val < prev->val)
            {
                prev = dummyHead;
            }
            while (prev->next->val <= curr->val)
            {
                prev = prev->next;
            }

            // 完成插入
            lastSorted->next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
        }
        curr = lastSorted->next;
    }
    // delete dummyHead;
    return dummyHead->next;
}

/*
148. 排序链表
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

进阶：

你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗
 */
ListNode *sortList(ListNode *head)
{
    return insertionSortList(head);
}

/*
160. 相交链表
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
 */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int t1 = 0, t2 = 0;   // t1为A链表的个数，t2为B链表的个数
    ListNode *p1 = headA; //指针1
    ListNode *p2 = headB; //指针2
    while (p1)
    { //统计A的个数
        t1++;
        p1 = p1->next;
    }
    while (p2)
    { //统计B的个数
        t2++;
        p2 = p2->next;
    }
    p1 = headA;
    p2 = headB;
    //将两个指针对齐
    if (t1 > t2)
    {
        int tmp = t1 - t2;
        while (tmp)
        {
            p1 = p1->next;
            tmp--;
        }
    }
    else
    {
        int tmp = t2 - t1;
        while (tmp)
        {
            p2 = p2->next;
            tmp--;
        }
    }
    while (p1 && p1 != p2)
    { //指针对齐后，一起向后同步移动，要么为null，要么找到交点
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
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

void test_list()
{

    string s = "[5,4,3,1,2]";
    ListNode *head = stringToListNode(s);
    printf_node(head, true);
    // print_expected(141, hasCycle(head), false);

    // print_expected(19, removeNthFromEnd(head, 2));
    // printf_node(removeNthFromEnd(head, 5), true);
    printf_node(sortList(head));
    s = "[2,1,1,1]";
    head = stringToListNode(s);
    printf_node(sortList(head));
}

void test_lru()
{
    {

        LRUCache lRUCache = LRUCache(2);
        lRUCache.put(1, 1);      // 缓存是 {1=1}
        lRUCache.put(2, 2);      // 缓存是 {1=1, 2=2}
        cout << lRUCache.get(1); // 返回 1
        lRUCache.put(3, 3);      // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
        cout << lRUCache.get(2); // 返回 -1 (未找到)
        lRUCache.put(4, 4);      // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
        cout << lRUCache.get(1); // 返回 -1 (未找到)
        cout << lRUCache.get(3); // 返回 3
        cout << lRUCache.get(4); // 返回 4
    }

    /*    {
           LRUCache lRUCache = LRUCache(1);
           lRUCache.put(2, 1);
           cout << lRUCache.get(2);
       } */
}

int main()
{
    // test_list();
    test_lru();
}