/*
 * @description  循环数组实现队列 玩明白 [l,r)
 * @date   2024/5/11 18:02
 * @author zhc
 */
#include <iostream>

using namespace std;

class Queue
{
private:
    size_t sz;
    // 循环数组
    int* arr;
    int max_sz;
    int l;
    int r;
public:
    Queue(int max_sz) : sz(0), max_sz(max_sz), l(0), r(0)
    {
        arr = new int[max_sz];
    }

    ~Queue()
    {
        delete arr;
    }

    // size
    int size() const
    {
        return sz;
    }

    bool empty() const
    {
        return sz == 0;
    }

    // read
    int front()
    {
        if(empty())
        {
            return -1;
        }
        return arr[l];
    }

    int back()
    {
        if(empty())
        {
            return -1;
        }
        // r - 1 位置
        int position = r == 0 ? (max_sz - 1) : (r - 1);
        return arr[position];
    }

    // write
    void push(int x)
    {
        arr[r] = x;
        r = r == max_sz - 1 ? 0 : r + 1;
        sz++;
    }

    int pop()
    {
        l = l == max_sz - 1 ? 0 : l + 1;
        sz--;
    }

    void print()
    {
        for(int i = l; i < r; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q(5);
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