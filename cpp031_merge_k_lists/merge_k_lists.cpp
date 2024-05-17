/*
 * @description 合并k个有序链表
 * @date   2024/5/17 15:10
 * @author zhc
 */
#include <iostream>
#include <queue>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode* next;

    ListNode(int x) : val(x), next(nullptr)
    {
    }
};

/**
 * 比较器，重载优先级队列的比较规则
 */
struct cmp
{
    bool operator()(ListNode* a, ListNode* b)
    {
        return a->val > b->val;
    }
};

/*
 * 对于基本数据类型：
 * 默认大根堆(升序队列)
 * priority_queue <int,vector<int>,greater<int>> q;
 * 小根堆(降序队列)
 * priority_queue <int,vector<int>,less<int> >q;
 * */
ListNode* mergeKLists(vector<ListNode*> &lists)
{
    priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
    // 将所有的头结点加入到队列
    for(ListNode* node: lists) if(node != nullptr) pq.push(node);
    if(pq.empty()) return nullptr;
    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;

    while(!pq.empty())
    {
        ListNode* node = pq.top();
        pq.pop();

        tail = tail->next = node;
        if(node->next) pq.push(node->next);
    }
    ListNode* ret = dummy->next;
    delete dummy;
    return ret;
}

void printList(ListNode* node)
{
    while (node != nullptr)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}


// 辅助函数：创建链表
ListNode* createList(const int* vals, int size)
{
    ListNode* dummy = new ListNode(-1);
    ListNode* current = dummy;
    for (int i = 0; i < size; ++i)
    {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    ListNode* head = dummy->next;
    delete dummy;
    return head;
}

int main()
{
    vector<ListNode*> lists;
    int list1[] = {1, 4, 5};
    int list2[] = {1, 3, 4};
    int list3[] = {2, 6};
    lists.push_back(createList(list1, 3));
    lists.push_back(createList(list2, 3));
    lists.push_back(createList(list3, 2));

    ListNode* result = mergeKLists(lists);
    printList(result);
    return 0;
}
