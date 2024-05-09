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
 *
 * @param head 单链表的头指针
 * @return     返回反转后的单链表的头指针
 */
ListNode* reverseList(ListNode* head)
{
    if(!head && !head->next)
    {
        return head;
    }

    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    while(head != nullptr)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}

ListNode* createLinkedList()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
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
    head = reverseList(head);
    printList(head);
    return 0;
}