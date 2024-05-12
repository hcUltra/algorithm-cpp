/*
 * @description 求两个链表的和
 * @author zhc
 */
#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr)
    {
    }

    ListNode(int x) : val(x), next(nullptr)
    {
    }

    ListNode(int x, ListNode* next) : val(x), next(next)
    {
    }
};

/**
 * 合并两个有序链表
 * @param head 单链表的头指针
 * @return     返回新的链表的头结点
 */
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;
    int t = 0;
    while(l1 || l2 || t)
    {
        if(l1) t += l1->val, l1 = l1->next;
        if(l2) t += l2->val, l2 = l2->next;
        tail = tail->next = new ListNode(t%10);
        t /= 10;
    }
    return dummy->next;
}

ListNode* createLinkedList1()
{
    ListNode* head = new ListNode(2);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    return head;
}

ListNode* createLinkedList2()
{
    ListNode* head = new ListNode(5);
    head->next = new ListNode(6);
    head->next->next = new ListNode(4);
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
    ListNode* head1 = createLinkedList1();
    printList(head1);

    ListNode* head2 = createLinkedList2();
    printList(head2);

    ListNode* head = addTwoNumbers(head1, head2);
    printList(head);
    return 0;
}