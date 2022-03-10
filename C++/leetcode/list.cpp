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

/*
92. 反转链表 II
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。
请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
*/
q
    /*
    206. 反转链表
    给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
     */
    ListNode *
    reverseList(ListNode *head)
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

/*
21. 合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 */
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *retNode = new ListNode(INT_MIN, nullptr);
    ListNode *storeNode = retNode;
    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->val < l2->val)
        {
            retNode->next = l1;
            l1 = l1->next;
        }
        else
        {
            retNode->next = l2;
            l2 = l2->next;
        }
        retNode = retNode->next;
    }
    retNode->next = (l1 == nullptr) ? l2 : l1;
    return storeNode->next;
}

/*
23. 合并K个升序链表
给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。
*/
ListNode *merge(vector<ListNode *> &lists, int l, int r)
{
    if (l == r)
        return lists[l];
    if (l > r)
        return nullptr;
    int mid = (l + r) >> 1;
    return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    return merge(lists, 0, lists.size() - 1);
}

/*
24. 两两交换链表中的节点
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）
 */
ListNode *
swapPairs(ListNode *head)
{
    // 1. 递归基
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    // 2. 交换
    ListNode *nxt = head->next;
    head->next = swapPairs(nxt->next);
    nxt->next = head;
    return nxt;
}
/*
25. K 个一组翻转链表
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

进阶：

你可以设计一个只使用常数额外空间的算法来解决此问题吗？
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换
 */
ListNode *reverseKGroup2(ListNode *head, int k)
{
    ListNode *dummyHead = new ListNode(0, head);
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *ret_head = dummyHead;
    ListNode *next = nullptr;
    ListNode *new_head = nullptr;

    int i = 1;
    while (fast != nullptr)
    {
        // printf("No.%d val: %d\n", i, fast->val);
        if (i % k == 0)
        {
            next = fast->next;
            fast->next = nullptr;
            // printf_node(slow);

            ret_head->next = reverseList(slow);

            slow->next = next;

            ret_head = slow;
            fast = slow;
            slow = next;
        }
        fast = fast->next;
        i++;
    }
    return dummyHead->next;
}

/*
return {head,tail}
 */
pair<ListNode *, ListNode *> reverseListTwo(ListNode *head)
{
    ListNode *dummyNode = head;
    ListNode *prev = nullptr;
    ListNode *cur = head;
    ListNode *next = nullptr;
    while (cur != nullptr)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;

        cur = next;
    }
    return {prev, dummyNode};
}

/*
*********************************
*****        ${1:Fun}       *****
*********************************
*/

ListNode *reverseKGroup3(ListNode *head, int k)
{
    ListNode *dummyHead = new ListNode(-1, head);
    ListNode *prev = dummyHead;
    ListNode *cur = dummyHead->next;
    ListNode *next = nullptr;

    int n = 1;
    while (cur != nullptr)
    {
        if (n % k == 0)
        {
            next = cur->next;
            cur->next = nullptr;
            auto [hair, tail] = reverseListTwo(prev->next);

            // 绑定反转的链表
            prev->next = hair;
            tail->next = next;

            prev = tail;
            cur = tail;
        }
        // printf("%d \n", cur->val);
        cur = cur->next;
        n++;
    }
    return dummyHead->next;
}

/* 剩下的不足k个也翻转 */
ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *dummyHead = new ListNode(-1, head);
    ListNode *prev = dummyHead;
    ListNode *cur = dummyHead->next;
    ListNode *next = nullptr;

    int n = 1;
    while (cur != nullptr)
    {
        if (n % k == 0)
        {
            next = cur->next;
            cur->next = nullptr;
            auto [hair, tail] = reverseListTwo(prev->next);

            // 绑定反转的链表
            prev->next = hair;
            tail->next = next;

            prev = tail;
            cur = tail;
        }
        // printf("%d \n", cur->val);
        cur = cur->next;
        n++;
    }
    if (prev->next != nullptr)
    {
        auto [hair, tail] = reverseListTwo(prev->next);
        prev->next = hair;
    }
    return dummyHead->next;
}

/*
86. 分隔链表
给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，
使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。

你应当 保留 两个分区中每个节点的初始相对位置。
 */
ListNode *partition(ListNode *head, int x)
{
    ListNode *biggerHead = new ListNode(-1, nullptr);
    ListNode *smallHead = new ListNode(-1, head);
    ListNode *biggerCur = biggerHead;
    ListNode *cur = smallHead;
    ListNode *nxt = nullptr;
    while (cur != nullptr && cur->next != nullptr)
    {
        nxt = cur->next;
        if (nxt->val >= x)
        { // delete node
            cur->next = nxt->next;
            // add to bigger list
            biggerCur->next = nxt;
            biggerCur = biggerCur->next;
            nxt->next = nullptr;
            continue; // 继续检测下一个元素是否需要跳过 关键
        }
        cur = cur->next;
        // nxt = cur->next;
    }
    // printf_node(smallHead->next);
    // printf_node(biggerHead->next);
    //
    // if (cur == nullptr)
    // {
    //     smallHead->next = biggerHead->next;
    // }
    // else
    {
        cur->next = biggerHead->next;
    }
    return smallHead->next;
}

void test_reverse()
{
    string s = "[1,4,3,5,7,2,5,2]";
    ListNode *head = stringToListNode(s);
    /*  printf_node(reverseKGroup(head, 1));

     head = stringToListNode(s);
     printf_node(reverseKGroup(head, 2));

     head = stringToListNode(s);
     printf_node(reverseKGroup(head, 3));

     head = stringToListNode(s);
     printf_node(reverseKGroup(head, 4)); */
    printf_node(partition(head, 3));
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

/*138. 复制带随机指针的链表  */
Node *copyRandomList(Node *head)
{
    if (head == nullptr)
        return head;

    //遍历原链表 创建新链表节点并建立映射关系
    unordered_map<Node *, Node *> map; //<原链表节点，对应位置的新链表节点>

    Node *cur = head;
    while (cur)
    {
        map[cur] = new Node(cur->val);
        cur = cur->next;
    }

    //遍历原链表 根据map链接新链表
    cur = head;
    while (cur)
    {
        Node *node = map[cur];
        node->next = map[cur->next];
        // node->random = map[cur->random];
        cur = cur->next;
    }

    return map[head];
}

/*   复制原结点  */
Node *copyRandomList2(Node *head)
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
        new_list = head->next;
        // if (head->random)
        {
            // new_list->random = head->random->next;
            // }
            head = new_list->next;
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
        // printf_node(raw_head->next);
        return tem_node;
    }
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

ListNode *split(ListNode *head)
{
    if (head == nullptr)
    {
        return head;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *tem = slow->next;
    slow->next = nullptr;
    return tem;
}

ListNode *merge(ListNode *start, ListNode *middle)
{
    ListNode *dummyNode = new ListNode(0, nullptr);
    ListNode *cur = dummyNode;
    while (start != nullptr && middle != nullptr)
    {
        if (start->val < middle->val)
        {
            cur->next = start;
            start = start->next;
        }
        else
        {
            cur->next = middle;
            middle = middle->next;
        }
        cur = cur->next;
    }
    // 收尾工作
    cur->next = (start == nullptr) ? middle : start;
    return dummyNode->next;
}

/*
148. 排序链表
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

进阶：

你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗

思路：递归排序
 */
ListNode *sortList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *begin = head;
    ListNode *middle = split(head);

    begin = sortList(begin);
    middle = sortList(middle);
    return merge(begin, middle);
}

/*
160. 相交链表
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
 */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == nullptr || headB == nullptr)
    {
        return nullptr;
    }

    ListNode *pa = headA, *pb = headB;
    while (pa != pb)
    {
        pa = (pa == nullptr) ? headB : pa->next;
        pb = (pb == nullptr) ? headA : pb->next;
    }
    return pa;
}

ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB)
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
203. 移除链表元素
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 */
ListNode *removeElements(ListNode *head, int val)
{
    ListNode *dummyHead = new ListNode(0, head);
    ListNode *tem = dummyHead;
    while (tem->next != nullptr)
    {
        if (tem->next->val == val)
        {
            tem->next = tem->next->next;
        }
        else
        {
            tem = tem->next;
        }
    }
    return dummyHead->next;
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
    ListNode *begin = stringToListNode(s);
    auto [head, tail] = reverseListTwo(begin);
    // printf_node(head);
    // printf_node(tail);
    test_reverse();
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
    test_list();
    // test_lru();
}