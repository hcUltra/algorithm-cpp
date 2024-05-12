/*
 * @description 单链表数组实现队列
 * @author zhc
 */
#include <iostream>

using namespace std;

class ListNode
{
public:
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

class Queue
{
private:
    size_t sz;
    ListNode* head;
    ListNode* tail;
public:
    explicit Queue() : sz(0)
    {
    }

    // 大小
    int size()
    {
        return sz;
    }

    int empty()
    {
        return sz == 0;
    }

    // 访问
    int front()
    {
        // 返回链表尾节点的值
        if(sz < 0)
        {
            return -1;
        }

        return tail->val;
    }

    int back()
    {
        // 返回链表头结点的值
        if(sz < 0)
        {
            cout << "queue is empty" << endl;
            return -1;
        }
        return head->val;
    }

    // 修改
    void push(int x)
    {
        ListNode* node = new ListNode(x);
        // 将x头插到链表
        if(empty())
        {
            head = tail = node;
            sz++;
        } else
        {
            node->next = head;
            head = node;
            sz++;
        }
    }

    int pop()
    {
        if(empty())
        {
            cout << "queue is empty." << endl;
            return -1;
        }
        ListNode* cur = head;
        while(cur->next != tail)
        {
            cur = cur->next;
        }
        int val = cur->val;
        ListNode* tmp = cur->next;
        delete tmp;
        cur->next = nullptr;
        tail = cur;
        sz--;
        return val;
    }

    void print()
    {
        ListNode* cur = head;
        while(cur != nullptr)
        {
            if(cur->next != nullptr)
            {
                cout << cur->val << "->";
            } else
            {
                cout << cur->val << "->null" << endl;
            }
            cur = cur->next;
        }
    }
};

int main()
{
    Queue q;
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;
    q.push(5);
    q.push(7);
    q.push(9);
    q.print();
    cout << "Queue size after pushing elements: " << q.size() << endl;
    cout << "Front element: " << q.front() << ", Back element: " << q.back() << endl;
    q.pop();
    q.print();
    cout << "After popping, front element: " << q.front() << ", Queue size: " << q.size() << endl;
    return 0;
}
