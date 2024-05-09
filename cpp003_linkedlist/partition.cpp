#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}/*初始化列表*/
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

// 划分链表 <= x 放左侧 > x 的放右侧
ListNode* partition(ListNode* head, int x)
{
    ListNode* dl = new ListNode(-1);
    ListNode* tl = dl;
    ListNode* dg = new ListNode(-1);
    ListNode* tg = dg;

    while(head)
    {
        if(head->val < x)
        {
            tl = tl->next = new ListNode(head->val);
        } else
        {
            tg = tg->next = new ListNode(head->val);
        }

        head = head->next;
    }

    tl->next = dg->next;

    return dl->next;
}

ListNode* createLinkedList()
{
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);
    return head;
}

void printList(ListNode* head)
{
    ListNode* cur = head;
    while(cur != nullptr)
    {
        if(cur->next != nullptr) cout << cur->val << "->";
        else cout << cur->val;
        cur = cur->next;
    }
    cout << "->null" << endl;
}

int main()
{
    ListNode* head = createLinkedList();
    printList(head);
    head = partition(head, 3);
    printList(head);

    return 0;
}