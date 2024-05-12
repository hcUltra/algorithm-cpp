/*
 * @description 
 * @date   2024/5/12 10:08
 * @author zhc
 */
#include <iostream>
#include <vector>

using namespace std;

class Stack
{
private:
    int sz;
    vector<int> arr;
public:
    // constructor & destructor
    /**
     * @param size 同时在栈内的元素个数最多为size
     */
    Stack() : sz(0)
    {
    }

    // size
    bool empty() const
    {
        return sz == 0;
    }

    size_t size() const
    {
        return sz;
    }

    // read
    int peek()
    {
        if(empty())
        {
            cout << "stack is empty" << endl;
            return -1;
        }

        return arr[sz - 1];
    }

    // write
    void push(int x)
    {
        arr.push_back(x);
        sz++;
    }

    int pop()
    {
        if(empty())
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        int val = arr[--sz];
        arr.pop_back();
        return val;
    }

    void print()
    {
        for(int i = 0; i < sz; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack myStack;

    // 测试空栈情况
    cout << "Is the stack empty? " << (myStack.empty() ? "Yes" : "No") << endl;

    // 压栈操作
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.print();
    // 输出当前栈的大小
    cout << "Current stack size: " << myStack.size() << endl;

    // 查看栈顶元素但不移除
    cout << "Top element is: " << myStack.peek() << endl;

    // 弹栈操作并输出弹出的元素
    cout << "Popped: " << myStack.pop() << endl;
    cout << "Popped: " << myStack.pop() << endl;

    // 再次检查栈是否为空及大小
    cout << "Is the stack empty after pops? " << (myStack.empty() ? "Yes" : "No") << endl;
    cout << "Final stack size: " << myStack.size() << endl;
    return 0;
}