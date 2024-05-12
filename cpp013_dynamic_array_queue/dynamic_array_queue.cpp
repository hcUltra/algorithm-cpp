/*
 * @description 动态数组实现队列
 * @author zhc
 */
#include <iostream>
#include <vector>

using namespace std;

class Queue
{
private:
    // 成员数据
    vector<int> q;
    int l;
    int r;
public:
    // 构造函数
    Queue()
    {
        l = r = 0;
    }

    // 成员函数
    // 大小
    bool empty()
    {
        return l == r;
    }

    // 有效范围 [l,r - 1] -> size = (r - 1) - l + 1 = r - 1 -l + 1  = r - l
    bool size()
    {

        return r - l;
    }

    // 访问
    int front()
    {
        return q[l];
    }

    int back()
    {
        return q[r - 1];
    }

    // 修改元素
    void push(int x)
    {
        q.push_back(x);
        r++;
    }

    int pop()
    {
        if(l >= r)
        {
            cout << "queue is empty,can't pop" << endl;
        }
        return q[l++];
    }

    void print()
    {
        for(int i = r - 1; i >= l; --i)
        {
            cout << q[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue* q = new Queue();
    for(int i = 0; i < 3; i++)
    {
        q->push(i + 10);
        q->print();
    }
    cout << "============" << endl;
    for(int i = 0; i < 5; ++i)
    {
        q->pop();
        q->print();
    }
    return 0;
}